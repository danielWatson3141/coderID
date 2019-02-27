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

        cfg = PPTools.Config.config

        self.cfg = cfg
        self.saveLocation = os.getcwd()+cfg['dir']['save']
        self.resultLocation = os.getcwd()+cfg['dir']['csv_output']
        self.dataStore = os.getcwd()+cfg['dir']['data_store']
        self.authorStore = os.getcwd()+cfg['dir']['author_store']
        self.repoStore = os.getcwd()+cfg['dir']['repo_store']

        if not os.path.isdir(self.saveLocation):
            os.mkdir(self.saveLocation)
        
        if not os.path.isdir(self.resultLocation):
            os.mkdir(self.resultLocation)


        if not os.path.isdir(self.authorStore):
            os.mkdir(self.authorStore)

        if not os.path.isdir(self.repoStore):
            os.mkdir(self.repoStore)

        self.updateList()

        if len(self.gpsList) is not 0:
            self.do_load(self.gpsList[0])
        else:
            self.activegps = gitProfileSet.gitProfileSet("default")

        self.prompt = self.activegps.name+">"
        print("Current set: "+self.activegps.name)

    def updateList(self):
        for fileName in os.listdir(self.saveLocation):
            if fileName not in self.gpsList:
                self.gpsList.append(fileName)

    def do_new(self, args):
        """Re-initializes profile set to be empty"""
        if args == "":
            print("No name given, initializing to \"default\"")
            self.activegps = gitProfileSet.gitProfileSet("default")
        else:
            self.activegps = gitProfileSet.gitProfileSet(args)
            self.gpsList.append(args)

        self.prompt = self.activegps.name+">"
        
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

    def save(self, gps, fileName = None):

        if fileName is None:
            file = open(self.saveLocation+gps.name, 'wb')
        else:
            file = open(fileName, 'wb')
            
        pickler = pickle.Pickler(file, pickle.HIGHEST_PROTOCOL)
        pickler.dump(gps)
        
    def do_load(self, args):
        """Switches currently active gps to one with given name. ***PROLLY SHOULD SAVE FIRST***"""
        if(args == ""):
            print("Error, must supply name of existing gps. Use 'new' to start a fresh one.")
        if args not in self.gpsList:
            print("GPS not found. ls to check available sets.")
            return
        self.activegps = self.load(args)
        self.prompt = self.activegps.name+">"

    def load(self, gpsName):
        self.updateList()
        for gpsFile in self.gpsList:
            path, extension = os.path.splitext(gpsFile)
            fileName = path.split("/")[-1]
            if gpsName == fileName:
                return(self.loadGPSFromFile(gpsName))

    def loadGPSFromFile(self, fileName):

        if "/" in fileName:
            file = open(fileName, 'rb')
        else:
            file = open(os.getcwd()+"/savedSets/"+fileName, 'rb')
        
        return pickle.Unpickler(file).load() 
           
    def do_ls(self, args):
        """List all available profile sets"""
        self.updateList()
        for gpsFile in self.gpsList:
            if self.activegps.name == gpsFile:
                print(gpsFile+"*")
            else:
                print(gpsFile)
        
    def do_rm(self, args):
        """Removes a specified gps permanently. pass * to remove all."""
        self.updateList()
        for gpsFile in self.gpsList:
            if gpsFile == args:
                os.remove(self.saveLocation+gpsFile)
                self.gpsList.remove(gpsFile)
                break
            if args == "*":
                os.remove(self.saveLocation+gpsFile)

    def do_mineDirectory(self, directory):
        """Mine all repos in directory and save the output"""

        if not os.path.isdir(directory):
            print("Not a directory!")
            return

        for subdir in os.listdir(directory):
            self.do_new(subdir)
            self.do_loadGit(directory+"/"+subdir)
            self.do_mineRepos("")
        
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
        """
        args = args.split(" ")
        n_est = 300
        
        if len(args) >= 1 and args[0] != '':
            numAuthors = int(args[0])
        if len(args) >= 2:
            n_est = int(args[1])
        if len(args) >= 3:
            expName = args[2]
        """
        if len(args) > 0:
            expName = args[0]

        if not self.activegps.featuresDetected:
            print("Running Feature Detection")
            self.activegps.getFeatures()

        if self.activegps.featuresSelected is None:
            self.activegps.featureSelect()

        print("Generating CM")
        n_samples = len(self.activegps.target)
        #clf = RandomForestClassifier(n_estimators=n_est, oob_score=True, max_features="sqrt")
        clf = Classifier.Classifier()

        #shuffle the dataset
        features, targets = utils.shuffle(self.activegps.featuresSelected, self.activegps.target)
        
        #fit the model to the first 2/3 of the samples
        train_size = int(np.floor(n_samples * clf.train_size))
        clf.model.fit(features[:train_size], targets[:train_size])
        
        #predict the last 1/3 of the data
        predictions = clf.model.predict(features[train_size:])
        expected = targets[train_size:]

        import csv

        # Create csv target directory if non-existent
        try:
            os.mkdir(self.resultLocation)
            print("CSV Directory ", self.resultLocation, " Created.")
        except FileExistsError:
            pass

        if clf.model_name == 'random_forest':
            #Compute OOB score
            print("OOB score: "+str(clf.model.oob_score_))
        
            #Compute best 50 features
            best = self.bestNFeatures(clf.model.feature_importances_, self.activegps.terms, 50)

            #write best features
            with open(self.resultLocation+expName+"_best_features.csv", 'w+') as csvfile:
                writer = csv.writer(csvfile, delimiter=',',
                                quotechar='|', quoting=csv.QUOTE_MINIMAL)

                for item in best:
                    writer.writerow(item)


        #compute confusion matrix
        cm = metrics.confusion_matrix(expected, predictions)
        print(cm)

        #write confusion matrix
        with open(self.resultLocation+expName+"CM.csv", 'w+') as csvfile:
            writer = csv.writer(csvfile, delimiter=',',
                            quotechar='|', quoting=csv.QUOTE_MINIMAL)
            for row in cm:
                writer.writerow(row)


        #make classification report
        classReport = classification_report(expected, predictions, output_dict=True)

        print(classification_report(expected, predictions))
        #write classification report

        with open(self.resultLocation+expName+"_report.csv", 'w+') as reportFile:
            w = csv.writer(reportFile)

            oneSample = list(classReport.items())[0]
            header = ["Author"]
            header.extend(oneSample[1].keys())
            w.writerow(header)

            for item in classReport.items():
                row = [item[0]]
                row.extend(item[1].values())
                w.writerow(row)


    def do_detectAuthor(self, args):
        """Given an Author name, attempt to identify any code in active repo written by any author in the active gps. Will set ROC point such that FPR <= maxFP"""
        
        self.detectAuthor(self.do_getGPSForAuthor(args), self.activegps)
        

    
    def detectAuthor(self, authorGPS, gps):
        if not gps.featuresDetected:     #get features of currently active repo
            gps.getFeatures()
            self.save(gps)

        if not authorGPS.featuresDetected:
            authorGPS.getFeatures()
            self.save(authorGPS)

        authorName = authorGPS.name #possibly unsafe?

        authFeat = copy.deepcopy(authorGPS.counts)
        authTargets = copy.deepcopy(authorGPS.target)

        gpsFeat = copy.deepcopy(gps.counts)
        gpsTargets = copy.deepcopy(gps.target)

        targets = authTargets + gpsTargets

        #THIS IS fucked up.
        # A: shouldn't do cross val. I have separate test and training data
        # B: How should I feature select if I assume the existing data is unlabled?

        notCount = 0
        authorCount = 0
        for i in range(1, len(targets)):
            if not targets[i] == authorName:
                targets[i] = "not_"+authorName
                notCount += 1
            else:
                authorCount += 1

        import scipy
        from sklearn.metrics import roc_curve, auc
        import matplotlib.pyplot as plt

        features = scipy.sparse.vstack(authFeat, gpsFeat)

        features, terms = gitProfileSet.gitProfileSet.featureSelect(features, authorGPS.terms, targets)

        clf = Classifier.Classifier().model
        

        cv = StratifiedKFold(n_splits=self.cfg["Feature Selection"]["n_splits"], shuffle=True)
        tprs = []
        aucs = []
        mean_fpr = np.linspace(0, 1, 100)

        i=0
        
        #Much of the code that follows is C+P from:
        #https://scikit-learn.org/stable/auto_examples/model_selection/plot_roc_crossval.html#sphx-glr-auto-examples-model-selection-plot-roc-crossval-py
        for train, test in cv.split(features, targets):

            trFeatures = features[train]
            trTarget = targets[train]

            teFeatures = features[test]
            teTarget = targets[test]
   
            predictions = clf.fit(trFeatures, trTarget).clf.predict_proba(teFeatures)
            
            fpr, tpr, thresholds = roc_curve(teTarget, predictions[:, 1])
            tprs.append(scipy.interp(mean_fpr, fpr, tpr))
            tprs[-1][0] = 0.0
            roc_auc = auc(fpr, tpr)
            aucs.append(roc_auc)
            
            plt.plot(fpr, tpr, lw=1, alpha=0.3,
             label='ROC fold %d (AUC = %0.2f)' % (i, roc_auc))

            i += 1
        
        plt.plot([0, 1], [0, 1], linestyle='--', lw=2, color='r',
            label='Chance', alpha=.8)

        mean_tpr = np.mean(tprs, axis=0)
        mean_tpr[-1] = 1.0
        mean_auc = auc(mean_fpr, mean_tpr)
        std_auc = np.std(aucs)
        plt.plot(mean_fpr, mean_tpr, color='b',
                label=r'Mean ROC (AUC = %0.2f $\pm$ %0.2f)' % (mean_auc, std_auc),
                lw=2, alpha=.8)

        std_tpr = np.std(tprs, axis=0)
        tprs_upper = np.minimum(mean_tpr + std_tpr, 1)
        tprs_lower = np.maximum(mean_tpr - std_tpr, 0)
        plt.fill_between(mean_fpr, tprs_lower, tprs_upper, color='grey', alpha=.2,
                        label=r'$\pm$ 1 std. dev.')

        plt.xlim([-0.05, 1.05])
        plt.ylim([-0.05, 1.05])
        plt.xlabel('False Positive Rate')
        plt.ylabel('True Positive Rate')
        plt.title('Receiver operating characteristic example')
        plt.legend(loc="lower right")
        plt.show()   

    def do_authorAuthTest(self, args):
        """Find precision and recall for given author in 2 class test"""
        if args == "":
            print("Needs an author parameter")

        print(self.twoClassTest(args))

    def do_allAuthTest(self, args, mindocs = 30):
        output = dict()
        for authorName, author in tqdm(self.activegps.authors.items()):
            if len(author.functions) > mindocs:
                result = self.twoClassTest(authorName, dictOutput=True)
                precision = result[authorName]["precision"]
                recall = result[authorName]["recall"]
                support = result[authorName]["support"]
                output.update({authorName:(precision, recall, support)})

        for result in output.items():
            print(result)

    def twoClassTest(self, author, splits = 5, dictOutput=False):
        
        if author not in self.activegps.authors:
            print("Author not found")
            return
        gps = self.activegps
        if not gps.featuresDetected:
            print("Running Feature Detection")
            gps.getFeatures()
        
        features = copy.deepcopy(gps.counts)
        targets = copy.deepcopy(gps.target)

        
        authorCount = 0
        notCount = 0
        for i in range(1, len(targets)):
            if not targets[i] == author:
                targets[i] = "not_"+author
                notCount += 1
            else:
                authorCount += 1


        clf = RandomForestClassifier(n_estimators=600, oob_score=True, max_features="sqrt", class_weight={author:5, "not_"+author:1})
        
        #cross validate for prec and rec

        cv = StratifiedKFold(n_splits=splits, shuffle=True)
        pred = []
        tar = []
        #print("Cross Validating")
        for train, test in cv.split(features, targets):

            trFeatures = features[train]
            trTarget = targets[train]

            teFeatures = features[test]
            teTarget = targets[test]
   
            clf.fit(trFeatures, trTarget)

            pred.extend(clf.predict(teFeatures))
            tar.extend(teTarget)

        return classification_report(pred, tar, output_dict=dictOutput)

    def do_getGPSAll(self, args):
        """get GPS of all repos of all authors in repo where possible. Type "skip" (or anything really) to skip commits to the active GPS"""
        nGPS = gitProfileSet.gitProfileSet(self.activegps.name+"_complement")
        
        for author in tqdm(self.activegps.authors.values()):
            authfile = self.authorStore+author.name
            if os.path.isfile(authfile):
                authGPS = self.loadGPSFromFile(authfile)
            else:
                authGPS = author.getGPSofSelf(skip=self.activegps.repos)
                self.save(authGPS, authfile) #write gps to disk, even if empty. This helps prevent unnecessary API requests
            for auth in authGPS.authors.values():
                if len(auth.commits) > 0:
                    nGPS.authors.update(authGPS.authors)
                    break

        self.save(nGPS)
        
        print(str(len(nGPS.authors))+" authors found from "+str(len(self.activegps.authors))+" authors.")

    def do_getGPSForAuthor(self, args):
        """Check Github for a matching author, then pull their content. 
        If a file version exists, load it.
        By default, the set gathered will skip over any content
        that already exists in the active GPS ***unless loaded from an existing file***"""

        if args in self.activegps.authors:
            author = self.activegps.authors[args] 
            print("Author found in current set.")
            return author.getGPSofSelf(skip = self.activegps.repos)
            
        if os.path.isfile(self.authorStore+"/"+args):
            print("Saved author found. Loading...")
            return self.loadGPSFromFile(self.authorStore+"/"+args)
        
        print("No existing profile found. Creating a new one.")
        author = gitProfileSet.gitAuthor((args, ''))
        return author.getGPSofSelf()

    def do_featureDetect(self, args):
        self.activegps.getFeatures()
        self.do_save()

    def do_featureSelect(self, args):
        if args is not '':
            redF = float(args)
        else:
            redF = .7    
        self.activegps.featureSelect(redF)
        self.do_save()
    
    def decisionMaximizationProcedure(self, success:np.array, confidence:np.array, maxFP=.1, precision = .01):
        """return the highest d such that P(success| confidence > d) >= 1-maxFP"""

        if len(success) != len(confidence):
            raise Exception("success and confidence vectors must be equal in length")

        corclass = confidence[success]      #Confidence in correct instances
        misclass = confidence[not success]  #Confidence in incorrect instances

        totalCount = len(success)
        
        #If misclassification rate is less than maximum false positive rate then the optimal cut-off is is the minimum of the correct instances
        if len(misclass) < maxFP*totalCount:
            return min(corclass)
        

        upper = 1
        lower = 0
        d = .5
        fp = 1

        maxIter = 10
        iterCount = 0   #Don't iterate more than ten times. Necessary to prevent infinite loop on small datasets

        while (fp > maxFP+precision or fp < maxFP-precision) and iterCount < maxIter:

            
            iterCount += 1

            d = (upper+lower)/2
            
            fp = len(np.where(misclass>d))/totalCount   #fp rate with d at its current value

            print("d: "+d+" "+"fp: "+fp)
            
            if fp < maxFP:
                upper = d
            else:
                lower = d

        if iterCount == 10:
            print("terminated after 10 iterations. This is problematic.")
        return d

    def determineConfidence(self, features, targets, n_est = 300):
        """Cross validate over the given data and return the scores"""
        print("Cross Validating...")
        clf = RandomForestClassifier(n_estimators=n_est, oob_score=True, max_features="sqrt")
        numSamples = features.shape[0]
        train_size=min(1000 ,  numSamples* .5)
        test_size=min(200 ,  numSamples* .2)
        splits = 3

        cv = StratifiedKFold(n_splits=splits)
        
        success = np.empty((test_size*splits))
        confidence = np.empty((test_size*splits))
        index = 0

        for train, test in cv.split(np.zeros(len(targets)), targets):
            
            trainingSet = (features[train], targets[train]) #Select training set

            clf.fit(trainingSet[0], trainingSet[1])         #train model

            testSet = (features[test], targets[test])       #Select test set

            probabilities = clf.predict_proba(testSet[0])   #predict probabilities over test set
            
            for sample, target in zip(probabilities, testSet[1]):
                predIndex = np.argmax(sample)
                prediction = clf.classes_[predIndex]  #get item with max probability

                success[index] = prediction == target #record whether the result was correct
                confidence[index] = sample[predIndex] #record the confidence of the result
                index += 1

        return (success, confidence)

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

    def do_displayGitRepos(self, args):
        """Displays all repos currently in the set"""
        for repo in self.activegps.repos:
            print(repo)

    def do_setOption(self, args):
        """This method should take args option , value. Not implemented yet, check config issue on Github."""
        pass

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

    def do_mineRepos(self, args):
        """Mine the selected repos for relevant commits. Saves automatically upon completion, so if you want a name other than default save it first"""
        args = args.split(" ")
        # try:
        keep = []
        for i in range(0, len(self.activegps.repos)):
            repo = self.activegps.repos[i]
            if os.path.isdir(repo):
                keep.append(i)
                continue
            import re
            if re.match("[a-zA-Z]*/[a-zA-Z]*", repo).endpos == len(repo):
                destination = self.repoStore+repo.replace("/", "_")
                if os.path.isdir(destination):
                    keep.append(i)
                    self.activegps.repos[i] = destination+"/"+repo.split("/")[1]
                    continue
                else:
                    success = self.clone_repo(repo, destination)
                    if success:
                        self.activegps.repos[i] = destination+"/"+repo.split("/")[1]
                        keep.append(i)
                        continue
            print(repo +" not kept.")

        self.activegps.repos = [self.activegps.repos[i] for i in keep]  
        self.activegps.mineLocalRepos()
        print("Compilation Complete")
        #except Exception:
         #   print("Problem during compilation. Saving...")
        
        self.do_save()

    def clone_repo(self, targetRepo, destination):
        try:
            with open(os.getcwd()+"/github.token", 'r') as file:
                import github
                g = github.MainClass.Github(file.readline().split("\n")[0], timeout=30)
            targetRepoURL = g.search_repositories(targetRepo)[0].clone_url

            os.mkdir(destination)
            import git
            git.Git(destination).clone(targetRepoURL)
        except Exception:
            print("repo not cloned: "+targetRepo)
            return False
        return True
           
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
        sortedAuthors = sorted(self.activegps.authors.keys(), reverse=False)
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
