import sys
import warnings
if not sys.warnoptions:
    warnings.simplefilter("ignore")
from cmd import Cmd
import sys
import pickle
import os
import zipfile
import string
import gitProfileSet
import ProfileSet
import testCommitClassification
import copy
import numpy as np
import csv
import Classifier
import PPTools
from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import cross_val_score,ShuffleSplit, StratifiedKFold
from sklearn import metrics, utils
from sklearn.metrics import classification_report



from tqdm import tqdm

class MyPrompt(Cmd):

    #TODO: make more OO.
    #TODO: remove class variable access
    #TODO: move utils into PPTools
    #TODO: task queue-ify execution

    def do_init(self):
        """Initialize profile set. non-existent file will create new  args: filePath"""
        #os.environ["DYLD_LIBRARY_PATH"] = "/usr/local/Cellar/llvm/7.0.1/lib/"
        self.featuresDetected = False
            
        self.gpsList = list()
        self.saveLocation = os.getcwd()+"/savedSets/"
        self.resultLocation = os.getcwd()+"/classResults/"

        if not os.path.isdir(self.saveLocation):
            os.mkdir(self.saveLocation)

        for fileName in os.listdir(self.saveLocation):
            self.gpsList.append(fileName)

        if len(self.gpsList) is not 0:
            self.do_load(self.gpsList[0])
        else:
            self.activegps = gitProfileSet.gitProfileSet("default")

        self.prompt = self.activegps.name+">"
        print("Current set: "+self.activegps.name)
        
        

    def do_save(self, filepath=''):
        """Saves active gps, overwriting given file. Also used to rename set."""
        
        workingName = self.activegps.name
            
        print("saving...")
        if(filepath is ''):
            if workingName is "default":
                print("Note: saving under default, this is not recommended. Type a new name or press ENTER to accept: ")
                newName = input()
            else:
                newName = workingName
        else:
            newName = filepath 

        self.activegps.name = newName
        self.save(self.activegps)
        if newName not in self.gpsList:
            self.gpsList.append(newName)
        
        print("Saved to "+newName)

    @staticmethod
    def save(gps):
        file = open(os.getcwd()+"/savedSets/"+gps.name, 'wb')
        pickler = pickle.Pickler(file, pickle.HIGHEST_PROTOCOL)
        pickler.dump(copy.deepcopy(gps))
        
    def do_load(self, args):
        """Switches currently active gps to one with given name. ***PROLLY SHOULD SAVE FIRST***"""
        if(args == ""):
            print("Error, must supply name of existing gps. Use 'new' to start a fresh one.")
        self.activegps = self.load(args)
        self.prompt = self.activegps.name+">"

    def load(self, gpsName):
        for gpsFile in self.gpsList:
            path, extension = os.path.splitext(gpsFile)
            fileName = path.split("/")[-1]
            if gpsName == fileName:
                return(self.loadGPSFromFile(gpsName))

    def loadGPSFromFile(self, fileName):
        file = open(os.getcwd()+"/savedSets/"+fileName, 'rb')
        return pickle.Unpickler(file).load() 

    def do_ls(self, args):
        """List all available profile sets"""
        for gpsFile in self.gpsList:
            if self.activegps.name == gpsFile:
                print(gpsFile+"*")
            else:
                print(gpsFile)
        
    def do_rm(self, args):
        """Removes a specified gps permanently. pass * to remove all."""

        for gpsFile in self.gpsList:
            if gpsFile == args:
                os.remove(self.saveLocation+gpsFile)
                self.gpsList.remove(gpsFile)
                break
            if args == "*":
                os.remove(self.saveLocation+gpsFile)

    def do_getMasterAuthorList(self, args):
        """writes all authors in all currently mined repos to args.csv"""
        authors = []
        for savedSet in os.listdir(self.saveLocation):
            gps = self.loadGPSFromFile(savedSet)
            for author in gps.authors.values():
                authors.append([author.name, author.email])
        
        
            with open(self.resultLocation+args+".csv", 'w+') as csvfile:
                writer = csv.writer(csvfile, delimiter=',',
                                quotechar='|', quoting=csv.QUOTE_MINIMAL)
                for author in authors:
                    writer.writerow(author)


    def do_getGPSForAuthor(self, args):
        try:
            author = self.activegps.authors[args] 
        except Exception:
            print("Author not found")

        self.save(author.getGPSofSelf())

    def do_getGPSForEmail(self, args):
        dev = object()
        dev.name = args.split("@")[0]
        dev.email = args

        tempAuthor = gitProfileSet.gitAuthor(dev)
        return tempAuthor.getGPSofSelf()

    def do_mineDirectory(self, directory):
        """Mine all repos in directory and save the output"""

        if not os.path.isdir(directory):
            print("Not a directory!")
            return

        for subdir in os.listdir(directory):
            if subdir not in self.gpsList:
                self.do_new(subdir)
                self.do_loadGit(directory+"/"+subdir)
                self.do_compile("")
            else:
                print("Skipping "+subdir+" as it is already found.")
        
    def do_quit(self, args):
        """quits the program WITHOUT SAVING"""
        print("Quitting.")
        raise SystemExit


    def do_classifyFunctions(self, args):
        """Cross validate over functions committed by authors
         in all repos. This will give misleading results 
         unless multiple projects are analyzed"""

        """Builds and evaluates a Random Forest classifier for the chosen authors and features"""

        expName = self.activegps.name
       
        if len(args) > 0:
            expName = args[0]

        if not self.activegps.featuresDetected:
            print("Running Feature Detection")
            self.activegps.getFeatures()
            self.activegps.featuresSelected = None
            self.do_save()

        if self.activegps.featuresSelected is None:
            self.activegps.featureSelect()
            self.do_save()

        print("Generating Class Report")
        #n_samples = len(self.activegps.target)
        #clf = RandomForestClassifier(n_estimators=n_est, oob_score=True, max_features="sqrt")
        #clf = Classifier.Classifier()

        results = dict()
        for authorName in tqdm(self.activegps.authors):
            results.update(
                {authorName:
                    self.twoClassTest(authorName, splits = 3, dictOutput=True)
                }
            )

        import csv

        # Create csv target directory if non-existent
        try:
            os.mkdir(self.resultLocation)
            print("CSV Directory ", self.resultLocation, " Created.")
        except FileExistsError:
            pass

        #This doesn't work with one vs all format.
        #TODO: Rethink
        # if clf.model_name == 'random_forest':
        #     #Compute OOB score
        #     print("OOB score: "+str(clf.model.oob_score_))
        
        #     #Compute best 50 features
        #     best = self.bestNFeatures(clf.model.feature_importances_, self.activegps.terms, 50)

        #     #write best features
        #     with open(self.resultLocation+expName+"_best_features.csv", 'w+') as csvfile:
        #         writer = csv.writer(csvfile, delimiter=',',
        #                         quotechar='|', quoting=csv.QUOTE_MINIMAL)

        #         for item in best:
        #             writer.writerow(item)

        with open(self.resultLocation+expName+"_report.csv", 'w+') as reportFile:
            w = csv.writer(reportFile)
            oneReport = list(results.items())[0]
            oneSample = oneReport[1][oneReport[0]]
            header = ["Author"]
            header.extend(oneSample.keys())
            print(header)
            w.writerow(header)
            #make classification report
            for authorName, result in results.items():
                result = result[authorName]
                row = [authorName]+[value for key, value in result.items()]
                print(row)
                w.writerow(row)
            
            #write classification report
   
    def do_authorAuthTest(self, args):
        """Find precision and recall for given author in 2 class test"""
        if args == "":
            print("Needs an author parameter")

        print(self.twoClassTest(args))

    def twoClassTest(self, author, splits = 5, dictOutput=False):
        
        if author not in self.activegps.authors:
            print("Author not found")
            return
        gps = self.activegps
        if not gps.featuresDetected:
            print("Running Feature Detection")
            gps.getFeatures()
        
        features = copy.deepcopy(gps.counts)
        #targets = copy.deepcopy(gps.target)
        targets = list()
        

        authorInd = []
        
        notAuthorInd = []

        for i in range(0,len(gps.target)):  #find indeces containing examples from author in question
            authorName = gps.target[i]
            if authorName == author:
                targets.append(author)
                authorInd.append(i)
            else:
                targets.append("not_"+author)
                notAuthorInd.append(i)

        authorCount = len(authorInd)
        notAuthorCount = len(notAuthorInd)

        test_ratio = float(PPTools.Config.config['Cross Validation']['test_ratio'])

        if authorCount / notAuthorCount < test_ratio:  #if author makes up less than test_ratio of the sample, reduce the sample size
            maxNotAuthorAllowed = int((1 / test_ratio) * authorCount)
            from random import sample
            notAuthorInd = sample(notAuthorInd, maxNotAuthorAllowed)
            features = features[authorInd+notAuthorInd]
            targets = [targets[i] for i in authorInd+notAuthorInd]
        
        targets = np.array(targets)

        clf = Classifier.Classifier().model
        
        #cross validate for prec and rec

        cv = StratifiedKFold(n_splits=splits, shuffle=True)
        pred = []
        tar = []
        conf = []
        #print("Cross Validating")
        for train, test in cv.split(features, targets):

            trFeatures = features[train]
            trTarget = targets[train]

            teFeatures = features[test]
            teTarget = targets[test]
   
            clf.fit(trFeatures, trTarget)

            pred.extend(clf.predict(teFeatures))
            tar.extend(teTarget)
            
            if clf.classes_[0] == author:   #Make sure the author in question is treated as the pos label...
                conf.extend([prob[0] for prob in clf.predict_proba(teFeatures)])
            else:
                conf.extend([prob[1] for prob in clf.predict_proba(teFeatures)])

        from sklearn.metrics import auc, roc_curve
        
        fpr, tpr, thresholds = roc_curve(tar, conf, pos_label=author)   #...for this
        auc = auc(fpr, tpr)
        
        report = classification_report(pred, tar, output_dict=dictOutput)
        report[author]["AUC"] = auc
        report[author]['%'] = 100 * authorCount / (authorCount+notAuthorCount)
        
        return report

    def do_featureDetect(self, args):
        """Perform feature selection operations. 
        This is called automatically from classifyFunctions if not run already.
        This resets the state of selected features, requiring that procedure to be run again."""   
        
        self.activegps.getFeatures()
        self.activegps.featuresSelected = None
        self.do_save()

    def do_featureSelect(self, args):
        """Perform feature selection operation. This is called automatically from classifyFunctions if not run already"""   
        self.activegps.featureSelect()
        self.do_save()

    def do_authorsInCommon(self, args):
        for file1 in os.listdir(self.saveLocation):
            for file2 in os.listdir(self.saveLocation):
                if file1 == file2:
                    break
                gps1 = self.loadGPSFromFile(file1)
                gps2 = self.loadGPSFromFile(file2)
                inCommon = self.authorsInCommon(gps1, gps2)
                
                if inCommon: #if not empty
                    print(file1+", "+file2+": "+str(inCommon))



    def authorsInCommon(self, gps1, gps2):
        return [author for author in gps1.authors.keys() if author in gps2.authors]
        

    def do_pruneGit(self, args):
        """Limit to N authors with between k and m functions. 0 for unlimited"""
        args = args.split(" ")
        if len(args) != 3:
            print("Requires 3 args")
            return

        n= int(args[0])
        k= int(args[1])
        m= int(args[2])
        
        print("Pruning Authors")
        old = self.activegps.authors

        new = dict()
        count = 0
        for item in tqdm(old.items()):
            #print(item)
            if len(item[1].functions) >= k and len(item[1].functions) <= m:
                new.update([item])
                count+=1
                if count == n and n != 0:
                    break

        self.activegps.authors = new
        self.activegps.featuresDetected = False

    def do_new(self, args):
        """Re-initializes profile set to be empty"""
        if args == "":
            print("No name given, initializing to \"default\"")
            self.activegps = gitProfileSet.gitProfileSet("default")
        else:
            self.activegps = gitProfileSet.gitProfileSet(args)
            self.gpsList.append(args)

        self.prompt = self.activegps.name+">"
             
    def do_loadGit(self, args):
        """Loads a single git repo. Can be local or remote."""
        if args =="":
            print("Must enter a path to a git repo.")
        for filePath in args.split(" "):
            self.activegps.addRepo(filePath)
        self.do_displayGitAuthors("")

    def do_displayGitAuthors(self, args):
        """Displays all authors found in the currently loaded git repos"""
        self.activegps.displayAuthors()
        #print(self.activegps)

    def do_loadGitRepos(self, args):
        """Loads a directory args[0] of git repos, as many as args[1] def:inf"""
        args = args.split(" ")
        if len(args) == 0:
            "Must enter a directory"
        
        if len(args)>1:
            lim = int(args[1])
        else:
            lim = float("inf")
        repos = ProfileSet.listdir_fullpath(args[0])
        for i in range(0,min(len(repos), lim)):
            if not os.path.basename(repos[i])[0]==".":
                self.do_loadGit(repos[i])

    def do_compile(self, args):
        """Mine the selected repos for relevant commits. Saves automatically upon completion, so if you want a name other than default save it first"""
        args = args.split(" ")
       # try:
        if len(args) > 1:
            self.activegps.compileAuthors(int(args[0]), int(args[1]) )
        else:
            self.activegps.compileAuthors()
        print("Compilation Complete")
        #except Exception:
         #   print("Problem during compilation. Saving...")
        
        self.do_save()
        
       
    def do_view(self, args):
        """View author[0]'s: n[1] most recent (commits, repos, files, functions, lines)[3]"""
        #TODO add quality directions
        try:
            args = args.split(":")
            author = self.activegps.authors.get(args[0])

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
                    ((hsh, fil, line),code) = next(iter(fun.items())) #Python is whack man.
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

    @staticmethod
    def bestNFeatures(imp, names, n):
        match = dict(zip(names, imp))
        import operator
        sortedMatch = sorted(match.items(), key=operator.itemgetter(1), reverse=True)
        return sortedMatch[0:n]

    def do_gpsInfo(self, args):
        """print basic info about this gps"""
        print(self.activegps)

    def do_testCommitClassification(self, args):
        testCommitClassification.test_heuristic_function()

    
def memory_limit():
    import resource
    soft, hard = resource.getrlimit(resource.RLIMIT_AS)
    resource.setrlimit(resource.RLIMIT_AS, (get_memory() * 1024 , hard))

def get_memory():
    with open('/proc/meminfo', 'r') as mem:
        free_memory = 0
        for i in mem:
            sline = i.split()
            if str(sline[0]) in ('MemFree:', 'Buffers:', 'Cached:'):
                free_memory += int(sline[1])
    return free_memory

if __name__ == '__main__':
    
    #memory_limit() # Limitates maximun memory usage to 90%
    try:
        prompt = MyPrompt()
        prompt.prompt = 'coderID> '
        prompt.do_init()
        prompt.cmdloop('Starting prompt...')
    except MemoryError:
        sys.stderr.write('\n\nERROR: Memory Exception\n')
        sys.exit(1)
