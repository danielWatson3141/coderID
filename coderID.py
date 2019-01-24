from cmd import Cmd

import pickle
import os
import zipfile
import string
import gitProfileSet
import ProfileSet

class MyPrompt(Cmd):

    #TODO: make more OO.
    #TODO: remove class variable access
    #TODO: move utils into PPTools
    #TODO: task queue-ify execution

    def do_init(self, filePath):
        """Initialize profile set. non-existent file will create new  args: filePath"""
        #os.environ["DYLD_LIBRARY_PATH"] = "/usr/local/Cellar/llvm/7.0.1/lib/"
        self.featuresDetected = False
        if filePath == '': 
            filePath = os.getcwd()+"/default.cid"
            

        if os.path.isfile(filePath):
            try:
                self.do_load(filePath)
                self.homeFilePath =filePath
                print("Home filepath is "+filePath)
                return
            except Exception:
                print("Failed to load file.")
                os.remove(filePath)

        self.ps=ProfileSet.ProfileSet(filePath)
        self.gitProfileSet = gitProfileSet.gitProfileSet()
        self.homeFilePath =filePath
        print("Home filepath is "+filePath)


    def do_save(self, filepath=''):
        """Saves state, overwriting given file"""
        
        print("saving...")
        if(filepath is ''):
            filepath = self.homeFilePath
        else:
            self.homeFilePath = filepath 
        
        file = open(self.homeFilePath, 'wb')
        pickler = pickle.Pickler(file, pickle.HIGHEST_PROTOCOL)
        import copy
        pickler.dump((self.ps, copy.deepcopy(self.gitProfileSet))) #save after Compile may be broken by this
        print("Saved to "+self.homeFilePath)

    def do_load(self, args):
        """loads profileSet from file"""
        if(args == None):
            self.do_load(self.homeFilePath)
        if(os.path.isfile(args)):
            file = open(args, 'rb')
            self.ps, self.gitProfileSet = pickle.Unpickler(file).load() #load

    def do_quit(self, args):
        """quits the program WITHOUT SAVING"""
        print("Quitting.")
        raise SystemExit


    def do_classifyFunctions(self, args):
        """Cross validate over functions committed by authors
         in all repos. This will give misleading results 
         unless multiple projects are analyzed"""

        """Builds and evaluates a Random Forest classifier for the chosen authors and features"""
        
        from sklearn.ensemble import RandomForestClassifier
        from sklearn.model_selection import cross_val_score,ShuffleSplit
        from sklearn import metrics, utils
        from sklearn.metrics import classification_report

        import csv
        
        args = args.split(" ")
        n_est = 300
        numAuthors = -1
        expName = "exp"

        if len(args) >= 1 and args[0] != '':
            numAuthors = int(args[0])
        if len(args) >= 2:
            n_est = int(args[1])
        if len(args) >= 3:
            expName = args[2]


        if not self.gitProfileSet.featuresDetected:
            print("Running Feature Detection")
            self.gitProfileSet.getFeatures(numAuthors = numAuthors)

        print("Generating CM")
        n_samples = len(self.gitProfileSet.target)
        clf = RandomForestClassifier(n_estimators=n_est, oob_score=True, max_features="log2")
        
        #shuffle the dataset
        features, targets = utils.shuffle(self.gitProfileSet.counts, self.gitProfileSet.target)
        
        #fit the model to the last 2/3 of the samples
        clf.fit(features[:(n_samples//3)*2], targets[:(n_samples//3)*2])
        
        #predict the other 1/3 of the data
        predictions = clf.predict(features[n_samples//3:])
        expected = targets[n_samples//3:]
        
        #Compute OOB score
        print("OOB score: "+str(clf.oob_score_))
        
        
        #Compute best 50 features
        best = self.bestNFeatures(clf.feature_importances_, self.gitProfileSet.terms, 50)

        import csv

        #write best features
        with open(expName+"_best_features.csv", 'w') as csvfile:
            writer = csv.writer(csvfile, delimiter=',',
                            quotechar='|', quoting=csv.QUOTE_MINIMAL)
            
            for item in best:
                writer.writerow(item)        


        #compute confusion matrix
        cm = metrics.confusion_matrix(expected, predictions)
        print(cm)

        #write confusion matrix
        with open(expName+"CM.csv", 'w') as csvfile:
            writer = csv.writer(csvfile, delimiter=',',
                            quotechar='|', quoting=csv.QUOTE_MINIMAL)
            for row in cm:
                writer.writerow(row)


        #make classification report
        classReport = classification_report(expected, predictions, output_dict=True)

        print(classification_report(expected, predictions))
        #write classification report

        with open(expName+"_report.csv", 'w') as reportFile:
            w = csv.writer(reportFile)

            oneSample = list(classReport.items())[0]
            header = ["Author"]
            header.extend(oneSample[1].keys())
            w.writerow(header)

            for item in classReport.items():
                row = [item[0]]
                row.extend(item[1].values())
                w.writerow(row)


        #compute CV scores
        print("Cross Validating...")
        clf = RandomForestClassifier(n_estimators=n_est, oob_score=True, max_features="log2")

        cv = ShuffleSplit(n_splits=5, test_size=0.3)
        scores = cross_val_score(clf, features, targets, cv=cv)
        print(scores)
        print("CV Average:"+str(sum(scores)/5))
        #print(clf.estimators_)


    def do_pruneGit(self, args):
        """Limit to N authors with more than k functions. 0 for unlimited"""
        args = args.split(" ")
        if len(args) != 2:
            print("Requires 2 args")
            return

        n= int(args[0])
        k= int(args[1])
        
        print("Pruning Authors")
        old = self.gitProfileSet.authors

        new = dict()
        count = 0
        for item in old.items():
            #print(item)
            if len(item[1].functions) >= k:
                new.update([item])
                count+=1
                if count == n and n != 0:
                    break

        self.gitProfileSet.authors = new



    def do_new(self, args):
        """Re-initializes profile set to be empty"""
        self.ps = ProfileSet.ProfileSet("")
        self.gitProfileSet = gitProfileSet.gitProfileSet()
        self.featuresDetected=False

    
    def do_loadGit(self, args):
        """Loads a single git repo"""
        if args =="":
            print("Must enter a path to a git repo.")
        for filePath in args.split(" "):
            self.gitProfileSet.addRepo(filePath)
        self.do_displayGitAuthors("")

    def do_displayGitAuthors(self, args):
        """Displays all authors found in the currently loaded git repos"""
        self.gitProfileSet.displayAuthors()



    def do_loadGitRepos(self, args):
        """Loads a directory args[0] of git repos, as many as args[1] def:inf"""
        args = args.split(" ")
        if len(args) == 0:
            "Must enter a directory"
        
        if len(args)>1:
            lim = int(args[1])
        else:
            lim = float("inf")
        repos = self.ps.listdir_fullpath(args[0])
        for i in range(0,min(len(repos), lim)):
            if not os.path.basename(repos[i])[0]==".":
                self.do_loadGit(repos[i])

    def do_compile(self, args):
        self.gitProfileSet.compileAuthors()  
        print("Compilation Complete")
        
        #self.gitProfileSet.extractForAuthors()
        #self.do_save("")
        #self.do_load("")  #to fix the threadSpawning bug

    def do_view(self, args):
        """View author[0]'s: n[1] most recent (commits, repos, files, functions, lines)[3]"""
        #TODO add quality directions
        try:
            args = args.split(":")
            
            author = self.gitProfileSet.authors.get(args[0])
            

            args = args[1].strip().split(" ")

            n = int(args[0])
            target = args[1]

            if target == "commits":
                target = author.commits.values()
            
            elif target == "repos":
                target = author.repos.values()

            elif target == "files":
                target = author.files

            elif target == "functions":
                total = 0

                for fun in author.functions:
                    ((hsh, fil, line),code) = next(iter(fun.items()))
                    print(fil+":")
                    for line in fun.values():
                        print(line)
                print()
                return
                
            elif target == "lines":
                target = author.lines.values()

            total =0

            for item in target:
                print(item)
                total+=1
                if total>n:
                    return

        except Exception as e:
            print(str(e))
            print("Hint: view Dan: 10 lines")
            return
    

    def do_getGitRepos(self,args):
        """WINDOWS ONLY Read repos from reporeapers .csv file, fetch and store in target directory, using temp if specified. Use temp if trying to download to external drive"""
        if args == "":
            print("Must supply a target filepath.")
            return
        args = args.split(" ")
        
        inputFile = args[0]
        import csv
        data = list(csv.reader(open(inputFile)))
        outputDir = args[1]
        if len(args)>2:
            tempdir = args[2]
        else:
            tempdir = None
        for row in data[1:]:
            repo = row[0]
            
            import subprocess
            import shutil 
            repoDirName = repo.split("/")[1]
            if tempdir != None:
                downTarget = tempdir
            else:
                downTarget = outputDir
            if os.path.exists(downTarget+"/"+repoDirName):
                continue
            if repoDirName not in os.listdir(outputDir):
                #TODO: Make linux worthy
                subprocess.Popen([r'C:/Windows/System32/WindowsPowerShell/v1.0/powershell.exe',
                    '-ExecutionPolicy',
                    'Unrestricted',
                    './downloadrepos.ps1',
                    str(repo), downTarget], cwd=os.getcwd()).wait()  
                if tempdir != None:
                    shutil.copytree(tempdir+repoDirName, outputDir+"/"+repoDirName)
                    shutil.rmtree(tempdir+repoDirName)

    def sanityCheck(self, features, targets, model, numAuthors):

        from sklearn import metrics,utils

        n_samples = len(targets)
       
        features, targets = utils.shuffle(features, targets)
        expected = targets[n_samples //2:]
        # Test here
        model.fit(features[:n_samples//2], targets[:n_samples//2])
        predictions = model.predict(features[n_samples//2:])

        cm = metrics.confusion_matrix(expected, predictions)
        sortedAuthors = sorted(self.gitProfileSet.authors.keys(), reverse=False)
        authCount = numAuthors
        if numAuthors == -1:
            authCount = len(sortedAuthors)
        #assert len(sortedAuthors) == cm.shape[0]
        """
        for i in range(0, authCount):
            print(sortedAuthors[i]+": P="+str(cm[i,i]/sum(cm[i]))+" R="+str(cm[i,i]/sum(cm[:,i])))
        """
        from sklearn.metrics import classification_report
        print(classification_report(expected, predictions))

        #import numpy
        #numpy.set_printoptions(threshold='nan')
        
        print("Confusion matrix:\n%s" % cm)

    @staticmethod
    def bestNFeatures(imp, names, n):
        match = dict(zip(names, imp))
        import operator
        sortedMatch = sorted(match.items(), key=operator.itemgetter(1), reverse=True)
        return sortedMatch[0:n]

    
if __name__ == '__main__':
    prompt = MyPrompt()
    prompt.prompt = 'coderID> '
    prompt.do_init("")
    prompt.cmdloop('Starting prompt...')