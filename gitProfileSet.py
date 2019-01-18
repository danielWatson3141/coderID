import pydriller
import os
import PPTools
from sklearn.feature_extraction.text import TfidfVectorizer
import multiprocessing
from collections import Counter
import numpy as np
import time
import queue
import re




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
    def processCommits(commitQ, infoQ, bm):

        while True:
            if commitQ.empty():
                time.sleep(.1)
                continue
            
            repo, commit = commitQ.get()

            if commit == "DONE":
                commitQ.put((repo, commit))
                break
            
            info = bm.gitInfo(repo, commit)
            infoQ.put(info)
    
    @staticmethod
    def mineRepo(repo:str, queue:multiprocessing.Queue)->dict:
        """Mine repos for relevant commits. Populates queue."""
        miner = pydriller.repository_mining.RepositoryMining(repo, only_modifications_with_file_types=gitProfileSet.langList,only_no_merge=True)
        print("Scanning repo: "+miner._path_to_repo)
        commitList = miner.traverse_commits()
        
        tipeCounts = dict()
        for commit in commitList:
            tipe = commitType.categorize(commit)

            if tipe not in tipeCounts:
                tipeCounts.update({tipe: 0})
            count = tipeCounts.get(tipe)
            tipeCounts.update({tipe: count+1})


            if tipe is commitType.FEATURE:
                comm = (repo, commit.hash)
                queue.put(comm)
            
        print(str("finished"+str(miner._path_to_repo)))
        print("types: "+str(tipeCounts))
    
          
    
    def compileAuthors(self):
        print("Gathering Author data...")
        
        startTime = time.time()

        #time.sleep(10)
        m = multiprocessing.Manager()
        
        multiprocessing.managers.BaseManager.register('gitInfo', gitInfo) #register gitAuthor to synchronize it
        
        bm = multiprocessing.managers.BaseManager() #to create author objects

        bm.start()

        #authorDict = m.dict()           #make thread managed dict


        #----------------Set up consumer process
        producerWorkers = 2
        consumerWorkers = 4     #How many processes should consume commits

        producerQ = queue.Queue()        #use regular queue here
        consumerQ = queue.Queue()
        repoQ = queue.Queue()
        
        for repo in self.repos:
            repoQ.put(repo)

        commitQ = m.Queue()
        infoQ = m.Queue()
        
        for i in range(1,consumerWorkers):
            newP = multiprocessing.Process(target=gitProfileSet.processCommits, 
                           args=(commitQ, infoQ, bm))
            newP.start()
            consumerQ.put(newP)

            if i <= producerWorkers:
                nextRepo = repoQ.get()
                newP = multiprocessing.Process(target=gitProfileSet.mineRepo, 
                    args=(nextRepo, commitQ))
                newP.start()
                producerQ.put(newP)
            

        
        
        print("Consumers Started")      
        prodDone = False
        conDone = False
        verbosity = 25
        cur = 0
        finished = 0
        while True:
            
            
            if cur == verbosity:
                print("CommitQ: "+str(commitQ.qsize()))
                print("InfoQ: "+str(infoQ.qsize()))
                cur = 0
                if prodDone:
                    remaining = commitQ.qsize() + infoQ.qsize()
                    elapsedTime = time.time() - startTime
                    rate = finished / elapsedTime
                    remainingTime = remaining / rate
                    print("Est. time remaining: "+str(remainingTime/60)+" minutes.")

            else:
                cur+=1

            if not producerQ.empty():     #cycle through the processes,
                process = producerQ.get()
                if process.is_alive():       #If alive, keep in the queue
                    producerQ.put(process)
                elif not repoQ.empty():
                    nextRepo = repoQ.get()
                    newP = multiprocessing.Process(target=gitProfileSet.mineRepo, 
                           args=(nextRepo, commitQ))
                    newP.start()
                    producerQ.put(newP)
                
            elif not prodDone:
                print("Producers done.")
                commitQ.put(("DONE","DONE"))   #Do this to signal no more commits to the consumer
                prodDone = True

            if not consumerQ.empty():
                process = consumerQ.get()
                if process.is_alive():
                    consumerQ.put(process)
            elif not conDone:
                print("Consumers done.")
                conDone = True

            if infoQ.empty():
                if conDone and prodDone:
                    break
                else:
                     time.sleep(.1) #wait a bit
            else:
                info = infoQ.get()
                if info.getauthorName() not in self.authors:
                    self.authors.update({info.getauthorName():gitAuthor(info.getDev())})
                author = self.authors.get(info.getauthorName())
                author.updateFromCommitInfo(info)
                finished += 1

        print("Shutting down manager.")
        bm.shutdown()                   #Close now that work is done
        self.displayAuthors()
        return

    def displayAuthors(self):
        for value in self.authors.values():
            print(value)

    def createLexicalFeaturesTokens(self, token_counts):
        # change this to directly modify feature matrix
        fn_len = 0 # function length, not including whitespace
        num_keyword = 0
        num_word_tokens = 0
        # TODO: need to expand this outside of C++
        # include break, continue, etc.?
        KEYWORDS = set('do', 'if', 'else', 'switch', 'for', 'while')
        for k, v in token_counts.items():
            fn_len += len(k) * v
            if k in KEYWORDS:
                num_keyword += v
            if k.isalnum() and not k.isdigit(): # only words
                num_word_tokens += v

        return [1.0 * np.array([num_keyword, num_word_tokens]), fn_len]


    def createLexicalFeaturesFunctions(self, text):
        line_lengths = []
        num_comments = 0
        num_ternary = 0
        num_macros = 0

        for line in text.splitlines():
            line_lengths.append(len(line))
            # comments - need to account for str literals containing these vals
            if '//' in line or line.startswith('/*'):
                num_comments += 1

            if line.startswith('#'): # macros
                num_macros += 1

            m = re.search("(.+=.+\?.+:.+;)", line)
            if m is None: # no ternary operator
                num_ternary += 1

        return 1.0 * np.array([np.mean(line_lengths), np.std(line_lengths),
                               num_ternary, num_comments, num_macros])

    def getFeatures(self):
        inputs=[]
        lexical_features = []
        self.target = []
        print("Tokenizing...") # generating tokens/unigrams
        for author in self.authors.values():
            for fun in author.functions:
                tokens = PPTools.Tokenize.fun(fun)
                self.target.append(author.name)

                lex_feat_tok = self.createLexicalFeaturesTokens(Counter(tokens))
                lex_feat_fn = self.createLexicalFeaturesFunctions(fun)
                fn_len = lex_feat_tok[1]

                lex_feat_tok = np.log(lex_feat_tok[0] / fn_len)
                lex_feat_fn[2:] = np.log(lex_feat_fn[2:] / fn_len)
                lexical_features.append(lex_feat_tok + lex_feat_fn)

                inputs.append(tokens)
        print("Textifying...") # converting back to a document
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
        if dev is not None:
            self.name = dev.name
            self.email = dev.email
        self.commits = dict() #key: commitHash value: commit
        self.files = set()
        self.functions = list() #list of dicts. Each dict represents a function. str same as self.lines 
        self.lines = dict() #key: {commitHash,file.cpp,lineNumber} value: literal code
        self.repos = set()
    
    @classmethod
    def fromProxy(thisClass, proxy):
        toReturn = gitAuthor(None)
        toReturn.name = proxy.getname()
        toReturn.email = proxy.getemail()
        toReturn.commits.update(proxy.getcommits())
        toReturn.files.union(proxy.getfiles())
        toReturn.lines.update(proxy.getlines())
        toReturn.repos.update(proxy.getrepos())
        return toReturn
        #self.LOC = 0

    def updateFromCommitInfo(self, info):
        self.commits.update({info.gethash(): info.getrepo()})
        self.files.union(info.getfiles())
        self.lines.update(info.getlines())
        self.functions.extend(info.getfuns())
        self.repos.add(info.getrepo())

    def tokenizeLines(self):
        """tokenizes all code belonging to this author. Results are unpicklable so results should be disposed of after use."""
        return PPTools.Tokenize.lines(self.lines)

    def merge(self, other):
        """merges the authors into one author object, keeping self.name"""
        print("Merging author: "+self.name)
        self.commits.update(other.commits)
        self.functions.extend(other.functions)
        self.files.union(other.files)
        self.lines.update(other.lines)
        
    def __str__(self):
        return self.name+": "+str(len(self.commits.items()))+" commits. "+str(len(self.lines))+" LOC, "+str(len(self.functions))+" complete functions."
    

class gitInfo:
    """Container class for extracted git info"""
    
    def __init__(self, repoPath, commit):
        
        repository = pydriller.GitRepository(repoPath)

        self.repo = repoPath
        self.hash = commit
        self.files = list()
        self.lines = dict()
        self.funs = dict()

        commit = repository.get_commit(commit)
        self.author = commit.author
        
        
        for mod in commit.modifications:
            mod._calculate_metrics()
            if mod.new_path is None or not mod.new_path.split(".")[-1] in gitProfileSet.langList:
                continue
            
            self.files.append(mod.new_path)
            #parse diff and add lines to list
            
            leDiff = repository.parse_diff(mod.diff)
            for num, line in leDiff["added"]:
                self.lines.update({(commit.hash,mod.new_path,num):line})

            #extract functions with lizard
            funs = mod._function_list

            #maintain list of dicts containing the source code of specific functions. Same format as for lines
            lineIndex = 0
            for fun in funs:
                
                try:
                    while(leDiff["added"][lineIndex][0]<fun.start_line):
                        lineIndex+=1
                
                    while(leDiff["added"][lineIndex][0]<fun.end_line):
                        self.funs.update({(commit.hash,mod.new_path,leDiff["added"][lineIndex][0]):leDiff["added"][lineIndex][1]})
                        lineIndex+=1
                except IndexError: #if end of input reached before end of functions. This is probable when non-complete functions are submitted.
                    pass

    def getrepo(self):  
        return self.repo
    def gethash(self):  
        return self.hash
    def getDev(self):
        return self.author
    def getauthorName(self):  
        return self.author.name
    def getfiles(self):  
        return self.files
    def getlines(self):  
        return self.lines
    def getfuns(self):  
        return self.funs
    
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