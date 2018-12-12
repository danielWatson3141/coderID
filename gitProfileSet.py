import pydriller
import os
import PPTools
from sklearn.feature_extraction.text import TfidfVectorizer
import multiprocessing
from collections import Counter
import time



class gitProfileSet:

    #TODO: Make it so re-compiling doesn't break
    #TODO: Make sibling class of ProfileSet
    #TODO: Make multi-threaded
    langList =["cpp", "c"]

    def __init__(self):
        """Initialize a new gitset"""
        self.repos = []
        self.authors = dict()
        self.featuresDetected = False

    def addRepo(self, args):
        print("Adding repo: "+args)
        try:
            if args not in self.repos:
                self.repos.append(args)
        except Exception:
            print("Couldn't get that one...")
        #self.compileAuthors(newRepo)

    @staticmethod
    def processCommits(commitQueue, authorDict):
        workers = 4
        processes = []
        done = False

        while(True):
            
            if len(processes) < workers and not done:
                while commitQueue.empty():
                    pass                        #wait for commit queue to be non-empty
                commit, repo = commitQueue.get()      #get commit and repo
                if commit == "DONE":                #If no more commits the say done
                    done == True
                    continue
                  
                authorName = commit.author.name #get authorname
                if authorName not in authorDict:
                    authorDict.update({authorName: gitAuthor(commit.author())})

                newProcess = multiprocessing.Process(target=gitProfileSet.processCommit, args=(commit, authorDict.get(authorName), repo))
                newProcess.start()
                processes.append(newProcess)        #start new process and add it to the list
                continue
            elif len(processes) == workers:     #monitor processes for completion
                for process in processes:
                    if not process.isalive():
                        processes.remove(process)
            else:                                    #if we are done, wait for all processes to finish
                for process in processes:
                    process.join()
                return
            

            
    @staticmethod
    def processCommit(commit, author, repo):
        tipe = commitType.categorize(commit)    #Check commit type
        #print("Processing Commit")
        if tipe is not commitType.FEATURE:
            return

        for mod in commit.modifications:
                mod._calculate_metrics()
                if mod.new_path is None or not mod.new_path.split(".")[-1] in gitProfileSet.langList:
                    continue
                
                if not mod.new_path in author.files:
                    author.files.add(mod.new_path)
                
                #parse diff and add lines to list
                leDiff = repo.parse_diff(mod.diff)
                for num, line in leDiff["added"]:
                    author.lines.update({(commit.hash,mod.new_path,num):line})

                #extract functions with lizard
                funs = mod._function_list

                #maintain list of dicts containing the source code of specific functions. Same format as for lines
                lineIndex = 0
                for fun in funs:
                    funLineDict = dict()
                    
                    try:
                        while(leDiff["added"][lineIndex][0]<fun.start_line):
                            lineIndex+=1
                    
                        while(leDiff["added"][lineIndex][0]<fun.end_line):
                            funLineDict.update({(commit.hash,mod.new_path,leDiff["added"][lineIndex][0]):leDiff["added"][lineIndex][1]})
                            lineIndex+=1
                    except IndexError: #if end of input reached before end of functions. This is probable when non-complete functions are submitted.
                        pass
                    if not len(funLineDict.items())==0:
                        author.functions.append(funLineDict)
        
            

        
    @staticmethod
    def mineRepo(repo, queue)->dict:
        """Mine repos for relevant commits. Populates queue."""
        miner = pydriller.repository_mining.RepositoryMining(repo, only_modifications_with_file_types=gitProfileSet.langList,only_no_merge=True)
        print("Scanning repo: "+miner._path_to_repo)
        commitList = miner.traverse_commits()
        repo = pydriller.GitRepository(repo)
        for commit in commitList:
            queue.put((commit, repo))
            
        print("finished"+miner._path_to_repo)
          
    def compileAuthors(self):
        print("Gathering Author data...")
        processQ = multiprocessing.Queue()
        commitQ = multiprocessing.Queue()
        for repo in self.repos:
            newProcess = multiprocessing.Process(target= gitProfileSet.mineRepo, args= (repo, commitQ))
            newProcess.start()          #Start all the producer processes
            processQ.put(newProcess)

        commitConsumer = multiprocessing.Process(target= gitProfileSet.processCommits, args=(commitQ, self.authors))
        commitConsumer.start()          #Start the consumer processes


        while not processQ.empty():     #cycle through the processes,
            process = processQ.get()
            if process.isalive():       #If alive, keep in the queue
                processQ.put(process)
            time.sleep(.1)               #Do this at most 10 times per second so as not to eat resources spinning.

        commitQ.put(("DONE","DONE"))    #Do this to signal no more commits to the consumer
        
        commitConsumer.join()           #Now that producers are done, wait for consumer to finish

        print(len(self.authors))

    def displayAuthors(self):
        import operator
        sortedMatch = sorted(self.authors.items(), key=operator.itemgetter(1), reverse=True)
        
        for name, value in sortedMatch:
            print(value)

    def getFeatures(self):
        inputs=[]
        self.target = []
        print("Tokenizing...")
        for author in self.authors.values():
            for fun in author.functions:
                inputs.append(PPTools.Tokenize.fun(fun))
                self.target.append(author.name)
        print("Textifying...")
        for i in range(0,len(inputs)):
            inputs[i] = PPTools.Tokenize.tokensToText(inputs[i])

        print("Vectorizing...")
        vectorizer =  TfidfVectorizer(analyzer="word", token_pattern="\S*", decode_error="ignore", lowercase=False)
        vectorizer.fit(inputs)
        counts = vectorizer.transform(inputs)
        self.counts = counts
        self.terms = vectorizer.get_feature_names()
        self.featuresDetected = True
            #should fit feature detector here
            #then pass it down

    

class gitAuthor:

    def __init__(self, dev):
        self.name = dev.name
        self.email = dev.email
        self.commits = dict() #key: commitHash value: commit
        self.files = set()
        self.functions = list() #list of dicts. Each dict represents a function. str same as self.lines 
        self.lines = dict() #key: {commitHash,file.cpp,lineNumber} value: literal code
        self.repos = dict()
        #self.LOC = 0

    def tokenizeLines(self):
        """tokenizes all code belonging to this author. Results are unpicklable so results should be disposed of after use."""
        return PPTools.Tokenize.lines(self.lines)

    def __lt__(self, other):
        return len(self.commits) < len(other.commits)

    def __eq__(self, other):
        return self.name == other.name

    def merge(self, other):
        """merges the authors into one author object, keeping self.name"""
        print("Merging author: "+self.name)
        self.commits.update(other.commits)
        self.functions.extend(other.functions)
        self.files.union(other.files)
        self.lines.update(other.lines)
        


    def __str__(self):
        return self.name+": "+str(len(self.commits.items()))+" commits. "+str(len(self.lines))+" LOC, "+str(len(self.functions))+" complete functions."
    
    

from enum import Enum     
class commitType(Enum):
    FEATURE = "FC"
    BUGFIX = "BF"
    REFACTOR = "RF"
    OTHER = "OTH"

    types = {FEATURE, BUGFIX, REFACTOR, OTHER}

    def describe(self):
        # self is the member here
        return self.name, self.value
    
    #TODO: User better heuristic
    @staticmethod
    def categorize(commit):
        added= 0
        removed =0
        for mod in commit.modifications:
            if mod.new_path is None or not mod.new_path.split(".")[-1] in gitProfileSet.langList:
                continue
            #mod._calculate_metrics()
            added += mod.added
            removed += mod.removed

        if added == 0:
            return commitType.OTHER
        
        if added-removed < .1*added:
            if added < 20:
                return commitType.BUGFIX
            else:
                return commitType.REFACTOR        
        
        if added > 20:
            return commitType.FEATURE

        

        return commitType.OTHER