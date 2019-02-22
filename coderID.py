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
import Classifier
import PPTools
import PromptTools
import numpy as np

from sklearn import utils
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
        
        file = open(os.getcwd()+"/savedSets/"+newName, 'wb')
        pickler = pickle.Pickler(file, pickle.HIGHEST_PROTOCOL)
        import copy
        pickler.dump(copy.deepcopy(self.activegps))
        if newName not in self.gpsList:
            self.gpsList.append(newName)
        
        print("Saved to "+newName)

    def do_load(self, args):
        """Switches currently active gps to one with given name. ***PROLLY SHOULD SAVE FIRST***"""
        if(args == ""):
            print("Error, must supply name of existing gps. Use 'new' to start a fresh one.")
        for gpsFile in self.gpsList:
            path, extension = os.path.splitext(gpsFile)
            fileName = path.split("/")[-1]
            if args == fileName:
                self.activegps = PromptTools.loadGPSFromFile(args)
                self.prompt = self.activegps.name+">"
                break


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

    def do_mineDirectory(self, directory):
        """Mine all repos in directory and save the output"""

        if not os.path.isdir(directory):
            print("Not a directory!")
            return

        for subdir in os.listdir(directory):
            self.do_new(subdir)
            self.do_loadGit(directory+"/"+subdir)
            self.do_compile("")
        
    def do_quit(self, args):
        """quits the program WITHOUT SAVING"""
        print("Quitting.")
        raise SystemExit

    def do_selectModel(self, args):
        """
        Select the classifier to use on the dataset.
        """
        PPTools.Config.update('Model', 'model_name', args.strip())

    def do_classifyFunctions(self, args):
        """Cross validate over functions committed by authors
         in all repos. This will give misleading results 
         unless multiple projects are analyzed"""

        """Builds and evaluates a classifier for the chosen authors and features"""

        expName = self.activegps.name
        if len(args) == 1:
            expName = args.strip()

        if not self.activegps.featuresDetected:
            print("Running Feature Detection")
            self.activegps.getFeatures()

        if self.activegps.featuresSelected is None:
            self.activegps.featureSelect()

        print("Generating CM")
        n_samples = len(self.activegps.target)
        clf = Classifier.Classifier()

        #shuffle the dataset
        features, targets = utils.shuffle(self.activegps.featuresSelected, self.activegps.target)
        
        #fit the model to the first 2/3 of the samples
        train_size = int(np.floor(n_samples * clf.train_size))
        clf.model.fit(features[:train_size], targets[:train_size])
        
        #predict the last 1/3 of the data
        predictions = clf.model.predict(features[train_size:])
        expected = targets[train_size:]

        # save the results to CSV files in the result location
        PromptTools.save_results(clf, self.activegps, expName, self.resultLocation, expected, predictions)


    def do_match(self, args):
        """search for matches in a target repo"""
        PromptTools.detectKnownAuthors(self, args)

    def do_authorsInCommon(self, args):
        for file1 in os.listdir(self.saveLocation):
            for file2 in os.listdir(self.saveLocation):
                if file1 == file2:
                    break
                gps1 = PromptTools.loadGPSFromFile(file1)
                gps2 = PromptTools.loadGPSFromFile(file2)
                inCommon = PromptTools.authorsInCommon(gps1, gps2)
                
                if inCommon: #if not empty
                    print(file1+", "+file2+": "+str(inCommon))


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
        """Loads a single git repo"""
        if args =="":
            print("Must enter a path to a git repo.")
        for filePath in args.split(" "):
            self.activegps.addRepo(filePath)
        self.do_displayGitAuthors("")

    def do_displayGitAuthors(self, args):
        """Displays all authors found in the currently loaded git repos"""
        self.activegps.displayAuthors()
        #print(self.activegps)

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

    def do_gpsInfo(self, args):
        """print basic info about this gps"""
        print(self.activegps)

    
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
