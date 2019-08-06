
from cmd import Cmd

import pickle
import os
import zipfile
import string
import ProfileSet

import cProfile

from tqdm import tqdm

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
import deAnonymizer
import testCommitClassification
import copy
import numpy as np
import pandas as pd
import csv
import Classifier
import PPTools
import heapq
import traceback
from codeJamProfileSet import codeJamProfileSet
from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import cross_val_score,ShuffleSplit, StratifiedKFold
from sklearn import metrics, utils
from sklearn.metrics import classification_report

from plotting import plot_roc_auc_curves, plot_function_length_histogram, plot_confusion_matrix, plot_author_roc_auc_curve


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
            
        self.gpsList = set()
        self.saveLocation = os.getcwd()+"/savedSets/"
        self.resultLocation = os.getcwd()+"/classResults/"
        self.plotLocation = os.getcwd()+"/plots/"
        self.repoLocation = os.getcwd()+"/repos/"

        for direc in [self.saveLocation, self.resultLocation, self.plotLocation, self.repoLocation]:
            if not os.path.exists(direc):
                os.mkdir(direc)
                print("directory ", direc, " Created.")

        self.do_refresh("")

        for gps in self.gpsList:
            self.do_load(gps)
            break #just do it once. Hack around getting a single arbitrary element from set
        
        if self.gpsList == set():
            self.do_new("")

        #self.activegps = gitProfileSet.gitProfileSet("default")

        self.prompt = self.activegps.name+">"

        self.config = PPTools.Config.config
        
        #print("Current set: "+self.activegps.name)


    def do_new(self, args):
        """Re-initializes profile set to be empty"""
        if args == "":
            print("No name given, initializing to \"default\"")
            self.activegps = gitProfileSet.gitProfileSet("default")
        elif args == "GCJ":
            self.activegps = codeJamProfileSet(args)
            self.gpsList.add(args)
        else:
            self.activegps = gitProfileSet.gitProfileSet(args)
            self.gpsList.add(args)

        print("New set created: "+self.activegps.name)
        self.prompt = self.activegps.name+">"

    def do_refresh(self, args):
        """Looks around for saved sets and repos"""
        self.gpsList = set()
        for fileName in os.listdir(self.saveLocation):
            self.gpsList.add(fileName)

        # for fileName in os.listdir(self.repoLocation):
        #     if fileName not in self.gpsList:
        #         self.do_load(fileName)
        #         self.do_save("")
        

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
            self.gpsList.add(newName)
        
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
            return None
        
        gpsName = args.replace("/", "_")

        if gpsName in self.gpsList:
            self.activegps = self.loadGPSFromFile(gpsName)
        else:
            self.do_new(gpsName)
            if "/" in args:
                repoName = args.split("/")[1]
            elif "_" in args:
                repoName = args.split("_")[1]
            else:
                print("repo name not well formed.")
                return
            if not os.path.isdir(self.repoLocation+gpsName+"/"+repoName): #check if repo exists
                if not self.clone_repo(args):  #clone if not
                    print("failed to get repo.")
                    return
        
            self.do_loadGit(self.repoLocation+gpsName+"/"+repoName) #load it
            #self.do_save("")
        
        self.prompt = self.activegps.name+">"
        
        #not found in existing sets

    def loadGPSFromFile(self, fileName):
        file = open(os.getcwd()+"/savedSets/"+fileName, 'rb')
        return pickle.Unpickler(file).load() 

    def do_ls(self, args):
        """List all available profile sets"""
        for gpsFile in sorted(self.gpsList):
            if self.activegps.name == gpsFile:
                print(gpsFile+"*")
            else:
                print(gpsFile)
        
    def do_rm(self, args):
        """Removes a [1] permanently. pass * to remove all.
        [1]: [author, repo, set]
        [2]: [name]
        If [1] is set, removes gps, otherwise, removes from current gps
        """

        args = args.split(" ")

        if args[0] in ["author", "repo", "set"]:
            if args[0] == "author":
                authorName = " ".join(args[1:])
                self.activegps.rmAuthor(authorName)
            elif args[0] == "repo":
                self.activegps.rmRepo(args[1])
            else:
                os.remove(self.saveLocation+args[1])
                self.gpsList.remove(args[1])
        else:
            print("check usage")
            return

    def do_minegcj(self, args):
        """gathers info from extracted gcj directory. Pulls everything. Use zipSearch for partial extraction or extract full gcj.zip. Overwrites existing set"""
        currentDir = args.strip()
        if type(self.activegps) is not codeJamProfileSet:
            self.do_new("GCJ")
        
        self.activegps.compileAuthors()
        self.do_save


    def do_zipSearch(self, args):
        """Gets n authors from a code jam zip file with more than K documents of type cpp and unzips them to the specified directory"""
       
        if args == "":
            fro = "gcj.zip"
            to = "gcjExtractedFiles/"
            n = int(self.config["CodeJam"]["max_authors"])
            K = int(self.config["CodeJam"]["min_files"])
        else:
            try:
                args = args.split(" ")       
                to=args[0]
                n=int(args[1])
                K=int(args[2])
            except IndexError:
                print("Need 3 args: to, n, k")
                return
        
        if n < 1:
            n=float("Inf")
        if K < 1:
            K = 1

        if not os.path.exists(to):
            os.makedirs(to)

        print("Loading Zip...")
        try:
            self.zfile = zipfile.ZipFile(fro)
        except Exception:
            print("File could not be located. Check the path.")
        print(fro+" loaded.")

        
        extension = "cpp"
                
        print("Searching...")
        authors = dict()
        infoList = self.zfile.infolist()
        authorsToExtract = []
        filesToExtract = []
        #itemCount = len(infoList)
        for index in tqdm(range(0,len(infoList))):
            item = infoList[index]
            
            dirs = item.filename.split("/")
            if(len(dirs)<7):
                continue
            
            solutionIndex = dirs[4]
            if solutionIndex != "0":
                continue

            filename = dirs[-1]
            if(len(filename.split(".")) > 1):
                ext = (filename.split(".")[1]).lower()
            else:
                continue
            #print(ext)
            #print(item)
            authName = dirs[2]
            if ext == extension and (len(authorsToExtract) < n or authName in authorsToExtract):
                filesToExtract.append(item)
                if(authName in authors):
                    authors.update({authName:authors.get(authName)+1})
                else:
                    authors.update({authName:1})
                if authors.get(authName) == K and len(authorsToExtract) < n:
                        #print("Found author "+authName)
                        authorsToExtract.append(authName)
                
        print(str(len(authorsToExtract))+" authors selected.")
        #print(authorsToExtract)
        print("Extracting...")
        current = os.getcwd()
        os.chdir(to)
        for item in tqdm(filesToExtract):
            dirs = item.filename.split("/")
            authName = dirs[2]
            if authName in authorsToExtract:
                self.zfile.extract(item)

        print("Complete.")
        os.chdir(current)

    def do_classifyGCJ(self, args):
        """Builds and evaluates a Random Forest classifier for the chosen authors and features"""
        args = args.split(" ")
        n_est = 300

        expName = "exp"

        if len(args) >= 1 and args[0] != '':
            maxDocs = int(args[0])
        else:
            maxDocs = float("inf")
        if len(args) >= 2:
            n_est = int(args[1])
        if len(args) >= 3:
            expName = args[2]

        if not self.activegps.featuresDetected:
            self.activegps.getFeatures()
        from sklearn.ensemble import RandomForestClassifier
        from sklearn.model_selection import cross_val_score,ShuffleSplit
        from sklearn import metrics, utils
        from sklearn.metrics import classification_report

        n_samples = len(self.activegps.target)
        clf = RandomForestClassifier(n_estimators=n_est, oob_score=True, max_features="log2")

        #reduce the features
        selectedFeatures = self.reFeSe(clf, self.activegps.counts, self.activegps.target)
        trFeatures = trFeatures[:,selectedFeatures]    #feature select for the athor
        terms = [self.activegps.terms[i] for i in selectedFeatures]

        #evaluate model
        stre, pred, tar, importances = self.evaluate(clf, trFeatures, self.activegps.target)
        
        #Compute OOB score
        print("OOB score: "+str(clf.oob_score_))
        
        #Compute best 50 features
        best = self.bestNFeatures(importances, terms, 50)

        import csv

        #write best features
        with open(expName+"_best_features.csv", 'w') as csvfile:
            writer = csv.writer(csvfile, delimiter=',',
                            quotechar='|', quoting=csv.QUOTE_MINIMAL)
            
            for item in best:
                writer.writerow(item)        


        #compute confusion matrix
        cm = metrics.confusion_matrix(tar, pred)
        print(cm)

        #write confusion matrix
        with open(expName+"CM.csv", 'w') as csvfile:
            writer = csv.writer(csvfile, delimiter=',',
                            quotechar='|', quoting=csv.QUOTE_MINIMAL)
            for row in cm:
                writer.writerow(row)


        #make classification report
        classReport = classification_report(tar, pred, output_dict=True)

        print(classification_report(tar, pred))
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
        """Extracts an author's code from the active repo, saving their work in another set"""
        try:
            author = self.activegps.authors[args] 
        except Exception:
            print("Author not found")
            return

        self.save(author.getGPSofSelf())

    def do_getGPSForEmail(self, args):
        """Attempts to find the author's Github page and creates gps for them"""
        dev = object()
        dev.name = args.split("@")[0]
        dev.email = args

        tempAuthor = gitProfileSet.gitAuthor(dev)
        return tempAuthor.getGPSofSelf()

    def do_getCounterSet(self, args):
        """build a gps of all authors work except the ones contained in this set"""

        print("finding repos by authors in this set")
        reposToGet=self.activegps.fetch_authors_other_work()
        #we really don't want forks of projects already in the set
        projectsOwned = set()

        for repo in self.activegps.repos:
            projectName = repo.split("/")[-1]
            projectsOwned.add(projectName)

        uniqueRepos = []

        #try really hard to filter out projects that match existing projects.
        for repo in reposToGet:
            projectName = repo.split("/")[-1]
            skip=False
            for ownedProject in projectsOwned:
                if ownedProject in projectName or projectName in ownedProject:
                    skip=True
                    break
            if not skip:
                uniqueRepos.append(repo)

        reposToGet = uniqueRepos
        alreadySeenCommits = self.activegps.commits #remember the commits we've seen to avoid double counting them

        self.do_new(self.activegps.name+"_counter") #Make a new set

        self.activegps.commits.update(alreadySeenCommits) #put the already seen commits into the new set's commits to avoid double counting them
        print("cloning repos")
        for repoURL in tqdm(reposToGet):
            try:
                path = self.clone_repo(repoURL)
            except Exception as e:
                print("Couldn't get "+repoURL)
                continue

            self.activegps.addRepo(path)
        print("found "+str(len(self.activegps.repos)))
        self.do_save()

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

    def do_mineAll(self, args):
        """Mine all repos in set list"""
        for gps in self.gpsList:
            try:
                self.do_load(gps)
                self.do_compile(gps)
            except Exception as e:
                print("failed to mine "+gps)
                traceback.print_exc()
        
    def do_quit(self, args):
        """quits the program WITHOUT SAVING"""
        print("Quitting.")
        raise SystemExit

    def do_attackWith(self, args):
        """De-anonymize the presently loaded repo using arg1 as training data"""
        if len(args) == 0:
            print("requires one argument")

        targetGPS = self.activegps
        weaponGPS = self.loadGPSFromFile(args)

        if not hasattr(targetGPS, "counts"):
            self.targetGPS.getFeatures()
            self.save(targetGPS)
        if not hasattr(weaponGPS, "counts"):
            weaponGPS.getFeatures()
            self.save(weaponGPS)

        import deAnonymizer

        deAnon = deAnonymizer.DeAnonymizer(weaponGPS)

        report, curves = deAnonymizer.testDeAnonymizer(deAnon, targetGPS)
        print(str(report))

        plot_author_roc_auc_curve("everyone", curves[0], curves[1],report["auc"],session_name=self.activegps.name+"_vs_"+targetGPS.name+"_attack_roc.png")

        import csv

        #write report results
        with open(self.activegps.name+"_vs_"+targetGPS.name+"_attack_results.csv", 'w') as csvfile:
            writer = csv.writer(csvfile, delimiter=',',
                            quotechar='|', quoting=csv.QUOTE_MINIMAL)
            
            oneSample = list(report.values())[0]
            header = ["Author"]
            header.extend(oneSample.keys())
            print(header)
            writer.writerow(header)
            #make classification report
            for authorName, result in report.items():
                if authorName == "auc":
                    row = ["auc"]+[result]
                else:
                    row = [authorName]+[value for key, value in result.items()]
                print(row)
                writer.writerow(row)

    def do_filterAuthors(self, args):
        """takes a gps, filters current set's authors to only those in target set"""
        if len(args) == 0:
            print("Check usage")
            return

        targetGPS = self.loadGPSFromFile(args)
        newAuthors = self.activegps.authors.copy()
        for authorName, author in self.activegps.authors:
            if authorName in self.targetGPS.authors:
                newAuthors[authorName]=author

        self.activegps.authors = newAuthors

    def do_multiClassTest(self, args):
        """Builds a model for each author and classifies by maximum liklihood"""
        expName = self.activegps.name
       
        if len(args) > 0:
            expName = args[0]

        if not self.activegps.featuresDetected:
            print("Running Feature Detection")
            self.activegps.getFeatures()
            self.activegps.featuresSelected = None
            self.do_save()

        print("Generating Class Report")
        splits = int(self.config["Cross Validation"]["n_splits"])
        cv = StratifiedKFold(n_splits=splits, shuffle=True)
        pred = []
        tar = []
        conf = []
        imp = None  #cumulative feature importances
        #print("Cross Validating")
        features = self.activegps.counts
        targets = self.activegps.target
        names = self.activegps.terms
        count=1
        for train, test in cv.split(features, targets):
            print("fold "+str(count)+" out of "+str(splits))
            count+=1
            trFeatures = features[train]
            trTarget = targets[train]   #grab the training set...

            teFeatures = features[test]
            teTarget = targets[test]    #...and the test set.

            conf = dict()
            for author in tqdm(self.activegps.authors.keys()):
                clf = Classifier.Classifier().model
                auth_trFeatures = self.reFeSe(clf, trFeatures, trTarget)    #feature select for the athor
                clf = self.train_binary(trFeatures[:,auth_trFeatures], trTarget, author)
                if clf.classes_[0] == author:   #Make sure the author in question is treated as the pos label...
                    conf[author] = [prob[0] for prob in clf.predict_proba(teFeatures[:,auth_trFeatures])]
                else:
                    conf[author] = [prob[1] for prob in clf.predict_proba(teFeatures[:,auth_trFeatures])]

            for i in range(0, len(teTarget)):
                max_prob = 0
                guess = ""
                for author in self.activegps.authors.keys():
                    prob = conf[author][i]
                    if prob > max_prob:
                        max_prob = prob
                        guess = author
                
                pred.append(guess)

            tar.extend(teTarget)

        plot_confusion_matrix(tar, pred, self.activegps.authors.keys()) 
        
        print(classification_report(pred, tar, output_dict=False))
        report = classification_report(pred, tar, output_dict=True)
         
        authorNames = []
        with open(self.resultLocation+expName+"_multi_report.csv", 'w+') as reportFile:
            w = csv.writer(reportFile)
            oneReport = list(report.items())[0]     
            oneSample = oneReport[1]
            header = ["Author"]
            header.extend(oneSample.keys())
            #print(header)
            w.writerow(header)
            #make classification report
            for authorName, result in report.items():
                authorNames.append(authorName)
                row = [authorName]+[value for key, value in result.items()]
                print(row)
                w.writerow(row)
        
    
    def do_twoClassTest(self, args):
        """Builds and evaluates a Random Forest classifier over each author in a 1vAll manner and write results to a file."""

        expName = self.activegps.name
       
        if len(args) > 0:
            expName = args[0]

        if not self.activegps.featuresDetected:
            print("Running Feature Detection")
            self.activegps.getFeatures()
            self.activegps.featuresSelected = None
            self.do_save()

        print("Generating Class Report")

        results = dict()
        for authorName in (self.activegps.authors.keys()):
            print(authorName)
            results.update(
                {authorName:
                    self.twoClassTest(authorName, dictOutput=True)
                }
            )

        import csv

        # Create csv target directory if non-existent
        
        # imp = None
        # for authorName, result in results.items():
        #     importances = result["importances"]
        #     if imp is None:
        #         imp = importances
        #     else:
        #         imp = np.add(imp,importances)

        # best = self.bestNFeatures(imp, self.activegps.terms, 200)

        # #write best features
        # with open(self.resultLocation+expName+"_best_features.csv", 'w+') as csvfile:
        #     writer = csv.writer(csvfile, delimiter=',',
        #                     quotechar='|', quoting=csv.QUOTE_MINIMAL)

        #     for item in best:
        #         writer.writerow(item)

        with open(self.resultLocation+expName+"_binary_report.csv", 'w+') as reportFile:
            w = csv.writer(reportFile)
            oneReport = list(results.items())[0]
            oneSample = oneReport[1][oneReport[0]]
            header = ["Author"]
            header.extend(oneSample.keys())
            #print(header)
            w.writerow(header)
            #make classification report
            for authorName, result in results.items():
                result = result[authorName]
                row = [authorName]+[value for key, value in result.items()]
                print(row)
                w.writerow(row)

        # Plot ROC AUC curves
        plot_roc_auc_curves(results, self.plotLocation, expName)

    def twoClassTest(self, author, dictOutput=False):
        
        if author not in self.activegps.authors:
            print("Author not found")
            return
        gps = self.activegps
        if not gps.featuresDetected:
            print("Running Feature Detection")
            gps.getFeatures()
        
        
        targets = self.activegps.target
        features = self.activegps.counts
        names = self.activegps.terms

        targets = self.binaryify(targets, author)[0]   #make problem binary

        clf = Classifier.Classifier().model
        
        #cross validate for prec and rec
        splits = int(self.config["Cross Validation"]["n_splits"])
       
        cv = StratifiedKFold(n_splits=splits, shuffle=True)
        pred = []
        tar = []
        conf = []
        imp = None  #cumulative feature importances
        #print("Cross Validating")

        fSet = self.reFeSe(clf, features, targets)
        features = features[:,fSet]
        
        for train, test in cv.split(features, targets):

            trFeatures = features[train]
            trTarget = targets[train]   #grab the training set...

            clf = self.train_binary(trFeatures, trTarget, author)   #train the model

            teFeatures = features[test]
            teTarget = targets[test]    #...and the test set.

            if imp is None:
                imp = clf.feature_importances_  #grab the feature importances
            else:
                imp = np.add(imp, clf.feature_importances_)

            pred.extend(clf.predict(teFeatures))    #evaluate on the test data
            tar.extend(teTarget)

            if clf.classes_[0] == author:   #Make sure the author in question is treated as the pos label...
                conf.extend([prob[0] for prob in clf.predict_proba(teFeatures)])
            else:
                conf.extend([prob[1] for prob in clf.predict_proba(teFeatures)])

        imp = np.divide(imp,splits)


        from sklearn.metrics import auc, roc_curve  #AUC computation

        fpr, tpr, thresholds = roc_curve(tar, conf, pos_label=author)   #...for this
        auc = auc(fpr, tpr)

        report = classification_report(pred, tar, output_dict=dictOutput)
        #print(classification_report(pred, tar, output_dict=False))
        report[author]["AUC"] = auc
        report["importances"] = imp
        report["fpr"] = fpr
        report["tpr"] = tpr
        report["targets"] = list(map(lambda label: 1 if label == author else 0, tar))
        report["predictions"] = conf

        return report

        

        


        
    def binaryify(self, outputs, author):
        targets = []
        authorInd = []
        notAuthorInd = []
        for i in range(0,len(outputs)):  #find indeces containing examples from author in question
            authorName = outputs[i]
            if authorName == author:
                targets.append(author)
                authorInd.append(i)
            else:
                targets.append("not_"+author)
                notAuthorInd.append(i)

        return (np.array(targets), authorInd, notAuthorInd)

    def train_binary(self, features, outputs, author):
        
        targets, authorInd, notAuthorInd = self.binaryify(outputs, author)

        authorCount = len(authorInd)
        notAuthorCount = len(notAuthorInd)

        test_ratio = float(self.config['Cross Validation']['test_ratio'])

        if authorCount / notAuthorCount < test_ratio:  #if author makes up less than test_ratio of the sample, reduce the sample size
            maxNotAuthorAllowed = int((1 / test_ratio) * authorCount)
            from random import sample
            notAuthorInd = sample(notAuthorInd, maxNotAuthorAllowed)
            features = features[authorInd+notAuthorInd]
            targets = [targets[i] for i in authorInd+notAuthorInd]
        
        targets = np.array(targets)

        clf = Classifier.Classifier().model
        
        #cross validate for prec and rec
        clf.fit(features, targets)   #train the model
        return clf #return the model

    @staticmethod
    def reFeSe(model, features, targets):
         #returns indeces of best features

        nFeatures = features.shape[1]

        #reduce sample size to decrease training time
        maxSamples = int(PPTools.Config.config["Feature Selection"]["max_samples"])
        reductionFactor = float(PPTools.Config.config["Feature Selection"]["reduction_factor"])
        if len(targets) > maxSamples:
            from random import sample
            samples = sample(range(0,len(targets)), maxSamples)
            features = features[samples,:]
            targets = targets[samples]

        featureSubset = features
        previous = 0
        strength = .01
        previousBest = range(0, features.shape[1])
        best = None
        once = True #run at least once
        #choose optimal feature set size
        while True:
            previous = strength
            
            strength, pred, tar, importances = MyPrompt.evaluate(model, featureSubset, targets)
            #print((nFeatures, strength))
            if strength < previous and not once:
                break
            if once:
                once = False
            from operator import itemgetter
            match = list(zip(previousBest, importances))

            nonZero = np.where([m[1] > 0 for m in match])[0]
            nzero = (nFeatures) - len(nonZero)

            match = [match[i] for i in nonZero]
            
            if best is not None:
                    previousBest = best

            if nzero > reductionFactor*nFeatures: #get rid of all 0 importance features
                nFeatures = nFeatures - nzero
                best = [m[0] for m in match]
                featureSubset = features[:,best]
                #do at least once more
                #once = True
            else:   #if there are not many, sort and keep the top non-zero ones
                nFeatures = int((1-reductionFactor)*nFeatures)-nzero
                best = list(heapq.nlargest(nFeatures, match, key = itemgetter(1)))
                best = [b[0] for b in best]
                featureSubset = features[:,best]
        
        return previousBest
        
    @staticmethod
    def evaluate(clf, features, targets):
        from sklearn.model_selection import cross_val_score, ShuffleSplit
        numSamples = features.shape[0]
        section = 'Cross Validation'

        splits = PPTools.Config.get_value(section, 'n_splits')
        trSize = int(min(PPTools.Config.get_value(section, 'train_min'),
                         numSamples * PPTools.Config.get_value(section, 'train_ratio')))
        teSize = int(min(PPTools.Config.get_value(section, 'test_min'),
                         numSamples * PPTools.Config.get_value(section, 'test_ratio')))
        featureCount = features.shape[1]
        cv = ShuffleSplit(n_splits=splits, train_size=trSize, test_size=teSize)
        
        pred = []
        tar = []
        
        importances = np.zeros(featureCount)
        strength = 0
        for train, test in cv.split(features, targets):

            trFeatures = features[train]
            trTarget = targets[train]

            teFeatures = features[test]
            teTarget = targets[test]

            tar.extend(teTarget)
   
            clf.fit(trFeatures, trTarget)

            predictions = clf.predict(teFeatures)
            pred.extend(predictions)
            stren = len(np.where(predictions == teTarget)[0])/teSize

            strength += stren / splits
            importances += clf.feature_importances_ / splits
            
        return (strength, pred, tar, importances)


    def do_featureDetect(self, args):
        """Perform feature selection operations. 
        This is called automatically from classifyFunctions if not run already.
        This resets the state of selected features, requiring that procedure to be run again."""   
        
        self.activegps.getFeatures()
        self.activegps.featuresSelected = None
        self.do_save()

    def do_multiClassSingleModelTest(self, args):
        """Builds a single multi-class classifier and evaluates over the dataset"""
        expName = self.activegps.name
       
        if len(args) > 0:
            expName = args[0]

        if not self.activegps.featuresDetected:
            print("Running Feature Detection")
            self.activegps.getFeatures()
            self.activegps.featuresSelected = None
            self.do_save()

        print("Generating Class Report")
        splits = int(self.config["Cross Validation"]["n_splits"])
        cv = StratifiedKFold(n_splits=splits, shuffle=True)
        pred = []
        tar = []
        imp = []  #cumulative feature importances
        #print("Cross Validating")
        features = self.activegps.counts
        targets = self.activegps.target

        names = self.activegps.terms
        selectedTermCounts = dict()
        featureImportances = dict()
        for train, test in tqdm(list(cv.split(features, targets))):

            trFeatures = features[train]
            trTarget = targets[train]   #grab the training set...

            teFeatures = features[test]
            teTarget = targets[test]    #...and the test set.

            #train multi-output classifier
            clf = Classifier.Classifier().model
            
            selectedFeatures = self.reFeSe(clf, trFeatures, trTarget)
            trFeatures = trFeatures[:,selectedFeatures]    #feature select for the athor
            selectedNames = [names[i] for i in selectedFeatures]

            clf.fit(trFeatures, trTarget)

            importances = clf.feature_importances_

            for term in selectedNames:
                if term in selectedTermCounts:
                    selectedTermCounts[term] += 1
                else:
                    selectedTermCounts[term] = 1

            for i in range(0, len(importances)):
                name = selectedNames[i]
                if name in featureImportances:
                    featureImportances[name]+=importances[i]
                else:
                    featureImportances[name]=importances[i]
                
            pred.extend(clf.predict(teFeatures[:,selectedFeatures]))
            tar.extend(teTarget)

        
        print(classification_report(pred, tar, output_dict=False))
        report = classification_report(pred, tar, output_dict=True)
         

        with open(self.resultLocation + expName + "_single_model_multi_report.csv", 'w+') as reportFile:
            w = csv.writer(reportFile)
            oneReport = list(report.items())[0]     
            oneSample = oneReport[1]
            header = ["Author"]
            header.extend(oneSample.keys())
            #print(header)
            w.writerow(header)
            #make classification report
            for authorName, result in report.items():
                row = [authorName]+[value for key, value in result.items()]
                print(row)
                w.writerow(row)

        with open(self.resultLocation + expName + "_single_model_multi_features.csv", 'w+') as reportFile:
            w = csv.writer(reportFile)
            header = ["feature Name","Type", "FoldsSelected", "sumImportance"]
            #print(header)
            w.writerow(header)
            #make feature report
            for name in selectedTermCounts.keys():
                row = [name, self.activegps.featureTypes[name], selectedTermCounts[name], featureImportances[name]]
                #print(row)
                w.writerow(row)




    def do_authorsInCommon(self, args):
        """display common authors between repos"""
        for file1 in os.listdir(self.saveLocation):
            for file2 in os.listdir(self.saveLocation):
                if file1 == file2:
                    break
                gps1 = self.loadGPSFromFile(file1)
                gps2 = self.loadGPSFromFile(file2)
                inCommon = self.authorsInCommon(gps1, gps2)
                
                if inCommon: #if not empty
                    print(file1+", "+file2+": "+str(inCommon))

    def do_attack(self, args):
        """attempt to de-anonymize a target profileSet"""

        deAnon = deAnonymizer.DeAnonymizer(self.activegps.name)
        deAnon.addGPS(self.activegps)

        if len(args)<1:
            print("needs a profile set to attack")
            return

        target = self.loadGPSFromFile(args)

        report = deAnonymizer.testDeAnonymizer(deAnon, target)
        print(str(report))

        import csv

        #write report results
        with open(self.activegps.name+"_vs_"+target.name+"_attack_results.csv", 'w') as csvfile:
            writer = csv.writer(csvfile, delimiter=',',
                            quotechar='|', quoting=csv.QUOTE_MINIMAL)
            
            oneSample = report[0]
            header = ["Author"]
            header.extend(oneSample.keys())
            #print(header)
            writer.writerow(header)
            #make classification report
            for authorName, result in report.items():
                result = result[authorName]
                row = [authorName]+[value for key, value in result.items()]
                print(row)
                writer.writerow(row)



    def authorsInCommon(self, gps1, gps2):
        return [author for author in gps1.authors.keys() if author in gps2.authors]
        

    def do_pruneAuthors(self, args):
        """Limit to N authors with between k and m functions. 0 for unlimited"""
        args = args.split(" ")
        n=0
        k=0
        m=0
        if len(args) == 3:
            n= int(args[0])
            k= int(args[1])
            m= int(args[2])
        else:
            print("Requires 3 args for custom. Doing default set in config.ini.")
            n = int(self.config["Pruning"]["max_authors"])
            k = int(self.config["Pruning"]["min_functions"])
            m = int(self.config["Pruning"]["max_functions"])

        print("Pruning Authors")
        old = self.activegps.authors
        new = dict()
        count = 0
        for item in (old.items()):
            #print(item)
            if len(item[1].functions) >= k and len(item[1].functions) <= m:
                new.update([item])
                count+=1
                if count == n and n != 0:
                    break

        self.activegps.authors = new
        self.activegps.featuresDetected = False

    def pruneFunctions(self, args):
        """keeps only K functions from all authors"""
        if len(args) == 1:
            k= int(args[0])
        else:
            print("Requires 1 arg for custom. Doing default set in config.ini.")
            k = int(self.config["Pruning"]["funcs_to_keep"])

        for author in tqdm(self.activegps.authors):
            old = author.functions
            new = list()
            count = 0
            for fun in old:
                new.add(fun)
                count+=1
                if count == k:
                    break
                



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

    def do_repoInfo(self, args):
        """prints the reposin this profileSet"""
        for repo in self.activegps.repos:
            print(repo)

    def do_generateGpsReport(self, args):
        """
        Generates the details of each compiled repository.
        """
        cols = ["num_unique_authors", "num_functions",
                "num_lines_of_code", "avg_lines_of_code"]
        report = {}

        if args == "":
            print("must supply a filepath to a session datasheet")
            return

        session_df = pd.read_csv(args)

        sessions = list(session_df["session"])
        self.do_refresh("")

        for gpsName in sessions:
            self.do_load(gpsName)
            self.do_pruneGit("1000 50 1000")
            gps = self.activegps
            print(gps.name)
            #self.do_displayGitAuthors("")
            author_functions = gps.getAllFunctions()
            num_functions = len(author_functions)
            print(num_functions)
            num_lines_of_code = 0
            for function in author_functions:
                num_lines_of_code += len(function.split("\n"))

            avg_lines_of_code = num_lines_of_code / num_functions
            # name, number of unique authors, number of functions, LOC, avg LOC,
            report[gps.name] = [len(gps.authors), num_functions,
                                num_lines_of_code, avg_lines_of_code]

        report = pd.DataFrame.from_dict(report, orient="index", columns=cols)
        report.index.name = "repo_name"
        file_loc = os.getcwd() + "/sample_reports/repos_breakdown.csv"
        report.to_csv(file_loc)


    def do_displayAndPlotFunctionLengths(self, args):
        """
        Displays total number of functions, LOC, and average function LOC.
        Also plots a histogram of function length by LOC
        """
        # Calculate metrics on functions
        author_functions = self.activegps.getAllFunctions()
        num_functions = len(author_functions)
        num_lines_of_code = 0
        for function in author_functions:
            num_lines_of_code += len(function.split("\n"))

        avg_lines_of_code = num_lines_of_code / num_functions

        # Print function metrics
        table_template = "{0:35}{1:8}"
        print(table_template.format("Total number of functions:", num_functions))
        print(table_template.format("Total lines of code:", num_lines_of_code))
        print(table_template.format("Avg lines of code per function:", round(avg_lines_of_code, 2)))

        # Plot function length histogram
        expName = self.activegps.name
        if len(args) > 0:
            expName = args[0]

        plot_function_length_histogram(author_functions, self.plotLocation, expName)


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
                target = author.repos

            elif target == "files":
                target = author.files

            elif target == "functions":
                total = 0

                for fun in author.functions:
                        print(fun)
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
    
    def do_getGitReposFromFile(self, args):
        if args == "":
            print("Must supply a source filepath.")
            return

        data = (open(args).readlines())

        for repoName in data:
            self.do_load(repoName.strip())
            self.do_save()

    def do_getGitReposFromRepoReapers(self,args):
        """Read repos from reporeapers .csv file, fetch and store in target directory, using temp if specified. Use temp if trying to download to external drive"""
        if args == "":
            print("Must supply a source filepath.")
            return
        args = args.split(" ")
        
        inputFile = args[0]
        import csv
        data = list(csv.reader(open(inputFile)))
        if len(args) > 1:
            nReposToFetch = int(args[1])
        else:
            nReposToFetch = len(data)

        print("Fetching necessary repos...")

        for row in tqdm((data[1:nReposToFetch+1])):
            repo = row[0]
            try:
                self.do_getRepo(repo)
            except Exception:
                print("skipping "+repo)

    @staticmethod
    def bestNFeatures(imp, names, n):
        match = dict(zip(names, imp))
        import operator
        sortedMatch = sorted(match.items(), key=operator.itemgetter(1), reverse=True)
        return sortedMatch[0:n]

    def do_gpsInfo(self, args):
        """print basic info about this gps"""
        print(self.activegps)

    def do_run(self, args):
        """run a provided bash/coderID script file. Bash lines should start with /"""
        import subprocess
        if os.path.isfile(args):
            with open(args, 'r') as f:
                for line in f:
                    try:
                        if line[0] == '/':
                            subprocess.Popen(line[1:], stdout=subprocess.PIPE, shell=True)
                        elif line.isspace():
                            continue
                        else:
                            self.onecmd(line)
                    except Exception as e:
                        print(e)
                        print("invalid command: " + line)
        else:
            print("please provide a coderID script file.")

    def do_getRepo(self, args):
        """Fetches a specific repo from github. Example: BVLC/caffe"""
        import re
        if re.fullmatch(r".*/.*", args):
            self.clone_repo(args)
        else:
            print("Incorrect format. Example: BVLC/caffe")

    def clone_repo(self, targetRepo, destination = ""):

        import re
        if re.match(r"[A-Za-z]*/[A-Za-z]*",targetRepo):
            with open(os.getcwd()+"/github.token", 'r') as file:
                import github
                g = github.MainClass.Github(file.readline().split("\n")[0], timeout=30)
            targetRepoURL = g.search_repositories(targetRepo)[0].clone_url
            if destination == "":
                destination = self.repoLocation + targetRepo.replace("/", "_")
        else:
            targetRepoURL = targetRepo
            repoName = targetRepoURL.split("/")[-2]+"_"+(targetRepoURL.split("/")[-1]).split(".")[0]
            if destination == "":
                destination = self.repoLocation + repoName

        if not os.path.exists(destination):
            os.mkdir(destination)
        import git
        #print("cloning "+targetRepoURL)
        try:
            result = git.Git(destination).clone(targetRepoURL)
        except git.GitCommandError:
            #print("repo exists, skipping.")
            pass
        #result
    
        #import traceback
        #traceback.print_exception(e)
        
        return destination

    
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
    
    memory_limit() # Limitates maximun memory usage to 90%
    try:
        prompt = MyPrompt()
        prompt.prompt = 'coderID> '
        prompt.do_init()
        if len(sys.argv) > 1 and os.path.isfile(sys.argv[1]):
            print("Running Script File...")
            prompt.do_run(sys.argv[1])

        prompt.cmdloop('Starting prompt...')
        

    except MemoryError:
        sys.stderr.write('\n\nERROR: Memory Exception\n')
        sys.exit(1)
