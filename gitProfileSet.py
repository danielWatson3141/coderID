import os
import re
import time
import queue

import PPTools
import pydriller
import featureExtractors
import multiprocessing
import sys
import warnings
if not sys.warnoptions:
    warnings.simplefilter("ignore")
import numpy as np
from collections import Counter
import itertools

from scipy.sparse import hstack, vstack, csr_matrix
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.feature_selection import mutual_info_classif, SelectKBest


class gitProfileSet:

    #TODO: Make it so re-compiling doesn't break
    #TODO: Make sibling class of ProfileSet
    
    langList =["cpp", "c"]
    def __init__(self):
        """Initialize a new gitset"""
        self.repos = []
        self.authors = dict()
        self.featuresDetected = False
        self.minedRepos = set()

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
    def mineRepo(repo, queue):
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
    
          
    #TODO: take args from cli
    def compileAuthors(self, minAuth = 25, minDocs = 9):
        import sys
        platform = sys.platform
        # This is disabled for now. Probably permanently
        if platform is None: #or platform is "darwin":
            print("Doing work in parellel")
            self.compileInParellel()
        else:
            print("Doing work in sequence")
            self.compileInSequence(minAuth, minDocs)

    def compileInSequence(self, minAuthors, minDocs):
        
        authorsWithEnoughDocs = 0
        for author in self.authors:
            if len(author.functions) > minDocs:
                authorsWithEnoughDocs += 1

        for repo in self.repos:
            if authorsWithEnoughDocs >= minAuthors:
                return
            if repo in self.minedRepos:
                continue
            else:
                self.minedRepos.add(repo)
            miner = pydriller.repository_mining.RepositoryMining(repo, only_modifications_with_file_types=gitProfileSet.langList,only_no_merge=True)
            repository = pydriller.GitRepository(repo)
            print("Scanning repo: "+miner._path_to_repo)
            
            tipeCounts = dict()

            for commit in miner.traverse_commits():
                tipe = commitType.categorize(commit)

                if tipe not in tipeCounts:
                    tipeCounts.update({tipe: 0})
                count = tipeCounts.get(tipe)
                tipeCounts.update({tipe: count+1})


                if tipe is commitType.FEATURE:
                    author = commit.author
                    if author.name not in self.authors:
                        self.authors.update({author.name:gitAuthor(author)})
                        print("Found new author: "+author.name)
                    
                    author = self.authors.get(author.name)

                    author.commits.add(repo + commit.hash)

                    if repo not in author.repos:
                        author.repos.add(repo)
                    
                    for mod in commit.modifications:
                        mod._calculate_metrics()
                        if mod.new_path is None or not mod.new_path.split(".")[-1] in gitProfileSet.langList:
                            continue
                        
                        author.files.add(mod.new_path)
                        #parse diff and add lines to list
                        
                        leDiff = repository.parse_diff(mod.diff)
                        for num, line in leDiff["added"]:
                            author.lines.update({(commit.hash,mod.new_path,num):line})

                        #extract functions with lizard
                        funs = mod._function_list

                        #maintain list of dicts containing the source code of specific functions. Same format as for lines
                        lineIndex = 0
                        for fun in funs:
                            newFun = dict()
                            try:
                                while(leDiff["added"][lineIndex][0]<fun.start_line):
                                    lineIndex+=1
                            
                                while(leDiff["added"][lineIndex][0]<fun.end_line):
                                    newFun.update({(commit.hash,mod.new_path,leDiff["added"][lineIndex][0]):leDiff["added"][lineIndex][1]})
                                    lineIndex+=1
                            except IndexError: #if end of input reached before end of functions. This is probable when non-complete functions are submitted.
                                pass
                            if len(newFun) > 1:
                                author.functions.append(newFun)
                                if len(author.functions) == minDocs:
                                    authorsWithEnoughDocs += 1
                                    

                    
                    
            print(str("finished"+str(miner._path_to_repo)))
            print("types: "+str(tipeCounts))
            #print(authorsWithEnoughDocs+" authors with enough code so far.")




    def compileInParellel(self):
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


    def getFeatures(self, numAuthors):
        inputs=[]
        self.target = []
        charfeatureNames = featureExtractors.featureExtractors.charfeatureNames
        charLevelFeatures = None
        tokfeatureNames = featureExtractors.featureExtractors.tokfeatureNames
        tokFeatures = None

        print("Tokenizing...") # generating tokens/unigrams
        authors_seen = 0
        #fns_seen = 0
        for author in self.authors.values():
            if numAuthors != -1 and authors_seen == numAuthors:
                    break
            authors_seen += 1

            for fun in author.functions:
                #fns_seen += 1
                # TODO: Issue - not full functions, so these features (apart
                # from unigram) are somewhat useless or cannot be calculated

                fn_str = '\n'.join(fun.values())

                #whitespace fn's still getting in. This will catch for that.
                if fn_str.isspace() or fn_str == '':
                    continue
                
                tokens = PPTools.Tokenize.fun(fun)
                inputs.append(list(tokens))

                # Function-string level features
                if charLevelFeatures is None:
                    charLevelFeatures = featureExtractors.featureExtractors.characterLevel(fn_str)
                else:
                    charLevelFeatures = vstack([charLevelFeatures,
                                                featureExtractors.featureExtractors.characterLevel(fn_str)])

                # Token-level features
                self.target.append(author.name)

        print("Textifying...") # converting back to a document
        for i in range(0,len(inputs)):
            if tokFeatures is None:
                tokFeatures = featureExtractors.featureExtractors.tokenLevel(inputs[i])
            else:
                tokFeatures = vstack([tokFeatures,
                                      featureExtractors.featureExtractors.tokenLevel(inputs[i])])


            inputs[i] = PPTools.Tokenize.tokensToText(inputs[i]) #Convert to text

        inputs = np.array(inputs)
        print("Vectorizing...")
        vectorizer =  TfidfVectorizer(analyzer="word", token_pattern="\S*",
                                       decode_error="ignore", lowercase=False)

        #vectorizer.fit(inputs)
        self.counts = vectorizer.fit_transform(inputs) # unigrams

        # full feature set
        self.counts = hstack([self.counts, charLevelFeatures, tokFeatures], format='csr')
        self.terms = vectorizer.get_feature_names() + charfeatureNames + \
                     tokfeatureNames
        self.target = np.array(self.target)

        # First round feature selection using mutual information
        print("Selecting features via mutual information....")
        total_num_features = self.counts.shape[1]
        print("Number of features before selection: {}".format(total_num_features))

        feature_mi = mutual_info_classif(self.counts, self.target)
        relevant_features = [mi for mi in feature_mi if mi > 0]
        min_mi = min(relevant_features)
        n_relevant_features = sum([1 for mi in feature_mi if mi > min_mi])

        self.counts = SelectKBest(mutual_info_classif,
                                  k = n_relevant_features).fit_transform(self.counts, self.target)

        print("Number of features after selection: {}".format(n_relevant_features))
        frac_selected = 100 * n_relevant_features / total_num_features
        print("Percentage of features selected: {:.2f}%".format(frac_selected))

        self.featuresDetected = True
            #should fit feature detector here
            #then pass it down

    def functionToString(self, lines):
        textLines = list(len(lines))

        for lineInfo, line in lines:
            cHash, fil, lnum = lineInfo
            textLines[lnum] = line

        return "\n".join(textLines)

class gitAuthor:

    def __init__(self, dev):
        if dev is not None:
            self.name = dev.name
            self.email = dev.email
        self.commits = set() #store with repo+commitHash
        self.files = set()
        self.functions = list() #list of dicts. Each dict represents a function. str same as self.lines 
        self.lines = dict() #key: {commitHash,file.cpp,lineNumber} value: literal code
        self.repos = set()
    
    #TODO: Do I still need this?
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
        return self.name+": "+str(len(self.commits))+" commits. "+str(len(self.lines))+" LOC, "+str(len(self.functions))+" complete functions from "+str(len(self.repos))+ " repos."

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
                newFun = dict()
                try:
                    while(leDiff["added"][lineIndex][0]<fun.start_line):
                        lineIndex+=1
                
                    while(leDiff["added"][lineIndex][0]<fun.end_line):
                        newFun.update({(commit.hash,mod.new_path,leDiff["added"][lineIndex][0]):leDiff["added"][lineIndex][1]})
                        lineIndex+=1
                except IndexError: #if end of input reached before end of functions. This is probable when non-complete functions are submitted.
                    pass
                if len(newFun) > 0:
                    self.funs.update(newFun)
    #TODO: clean unnecessary getters
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



        