import os
import re
import time
import queue
import github
import PPTools
import ASTFeatureExtractor
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
import copy
from tqdm import tqdm
from scipy.sparse import hstack, vstack, csr_matrix
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.feature_selection import mutual_info_classif, SelectKBest


class gitProfileSet(ProfileSet):

    #TODO: Make it so re-compiling doesn't break
    #TODO: Make sibling class of ProfileSet
    
    langList =["cpp", "c"]
    def __init__(self, name):
        """Initialize a new gitset"""
        super(gitProfileSet, self).__init__(name)
        self.repos = []
        self.minedRepos = set()

    def addRepo(self, args):
        print("Adding repo: "+args)
        try:
            if args not in self.repos:
                self.repos.append(args)
        except Exception:
            print("Couldn't get that one...")
        #self.compileAuthors(newRepo)    
    
    def compileAuthors(self, authors = None):
        """Mine all repos in the repo list for commits by those in authors. None for get all"""
        print("mining "+self.name)
        for repo in self.repos:
            if not os.path.exists(repo+"/.git"): #in case the repo is one level down
                repo = os.listdir(repo)[0]
                print("moved to "+repo)
            if repo in self.minedRepos:
                continue
            elif authors is not None:
                self.minedRepos.add(repo)
            #if not os.path.exists(repo+".git"):
            #    repo = os.listdir(repo)[0]
            miner = pydriller.repository_mining.RepositoryMining(repo, only_modifications_with_file_types=gitProfileSet.langList,only_no_merge=True)
            repository = pydriller.GitRepository(repo)
            print("Scanning repo: "+miner._path_to_repo)
                        

            for commit in tqdm(miner.traverse_commits()):
                author = commit.author
                
                if authors is not None and author not in authors:
                    continue
                
                if True:    #for now, not worried about commit type
                    if author.name not in self.authors:
                        self.authors.update({author.name:gitAuthor(author)})
                        #print("Found new author: "+author.name)
                    
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
                        
                        newSC = list()
                        leDiff = repository.parse_diff(mod.diff)
                        for num, line in leDiff["added"]:
                            newSC.append(line)

                        from lizard import analyze_file as liz
                        fileInfo = liz.analyze_source_code(mod.new_path, "\n".join(newSC))

                        #maintain list of dicts containing the source code of specific functions. Same format as for lines
                        lineIndex = 0
                        
                        for fun in fileInfo.function_list:
                            #Make sure these appear in the "function"
                            arg_list_termination = r"\)\s*{"
                            started = False
                            newFun = dict()
                            lineStr = ""
                            try:
                                while(leDiff["added"][lineIndex][0]<fun.start_line):
                                    lineIndex+=1
                            
                                while(leDiff["added"][lineIndex][0]<fun.end_line+1):
                                    last_lineStr = lineStr
                                    lineStr = leDiff["added"][lineIndex][1]
                                    
                                    if not started and re.search(arg_list_termination, "".join([lineStr,last_lineStr])):
                                        started = True
                                        
                                    newFun.update({(commit.hash,mod.new_path,leDiff["added"][lineIndex][0]):lineStr})
                                    lineIndex+=1
                            except IndexError: #if end of input reached before end of functions. This is probable when non-complete functions are submitted.
                                pass

                            if started and len(newFun) > 1 and '}' in lineStr + last_lineStr:
                                author.lines.update(newFun)
                                author.functions.append(self.functionToString(newFun)) 
                                
            self.minedRepos.add(repo)
            print(str("finished"+str(miner._path_to_repo)))
            print(self)

    def displayAuthors(self):
        for value in self.authors.values():
            print(value)


    def getAllFunctions(self):
        functions = []
        for author in self.authors.values():
            functions.extend(author.functions)

        return functions


    def getFeatures(self):
        
        inputs=[]
        self.target = []
        charfeatureNames = featureExtractors.featureExtractors.charfeatureNames
        charLevelFeatures = None
        tokfeatureNames = featureExtractors.featureExtractors.tokfeatureNames
        tokFeatures = None

        print("Extracting Features...") # generating tokens/unigrams
        
        #fns_seen = 0
        for author in tqdm(self.authors.values()):
            
            import random

            if len(author.docs) > maxDocs:
                docs = random.sample(author.docs, maxDocs)
            else:
                docs = author.docs

            for doc in docs:
                #fns_seen += 1
                # TODO: Issue - not full functions, so these features (apart
                # from unigram) are somewhat useless or cannot be calculated

                with open(doc, 'r') as myfile:
                    fn_str = myfile.read()

                #whitespace fn's still getting in. This will catch for that.
                if fn_str.isspace() or fn_str == '':
                    continue
                
                try:
                    tokens = PPTools.Tokenize.text(doc, fn_str) #Sometimes this  breaks for n.a.r.
                except Exception:
                    print("failed parsing "+doc)
                    continue 
                
                inputs.append(PPTools.Tokenize.tokensToText(tokens))

                # Function-string level features
                if charLevelFeatures is None:
                    charLevelFeatures = featureExtractors.featureExtractors.characterLevel(fn_str)
                else:
                    charLevelFeatures = vstack([charLevelFeatures,featureExtractors.featureExtractors.characterLevel(fn_str)])

                if tokFeatures is None:
                    tokFeatures = featureExtractors.featureExtractors.tokenLevel(tokens)
                else:
                    tokFeatures = vstack([tokFeatures,featureExtractors.featureExtractors.tokenLevel(tokens)])

                # Token-level features
                self.target.append(author.name)

       
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
        print("Selecting features via mutual information....")

        relevantIndeces = np.where(np.array(feature_mi) > .05)[0]
        self.counts = self.counts[:,relevantIndeces]
        self.terms = [self.terms[i] for i in relevantIndeces]
        #min_mi = min(relevant_features)
        n_relevant_features = len(relevantIndeces)

        #self.counts = SelectKBest(mutual_info_classif,
        #                         k = n_relevant_features).fit_transform(self.counts, self.target)

        print("Number of features after selection: {}".format(n_relevant_features))
        frac_selected = 100 * n_relevant_features / total_num_features
        print("Percentage of features selected: {:.2f}%".format(frac_selected))

        self.featuresDetected = True
            #should fit feature detector here
            #then pass it down
    
    def functionToString(self, lines):
        return "\n".join(lines.values())

    
    def __str__(self):
         return (str(len(self.authors))+" authors. "+str(sum(map(lambda x: len(x.functions), self.authors.values())))+" functions in total.")
    
    def __lt__(self, other):
        return  self.name.lower() < other.name.lower()

        
class gitAuthor:

    def __init__(self, dev):
        if dev is not None:
            self.name = dev.name
            self.email = dev.email
        self.commits = set() #store with repo+commitHash
        self.files = set()
        self.functions = list() #list of str
        self.lines = dict() #key: {commitHash,file.cpp,lineNumber} value: literal code
        self.repos = set()
    
    def merge(self, other):
        """merges the authors into one author object, keeping self.name"""
        print("Merging author: "+self.name)
        self.commits.update(other.commits)
        self.functions.extend(other.functions)
        self.files.union(other.files)
        self.lines.update(other.lines)
        
    def __str__(self):
        return self.name+": "+str(len(self.commits))+" commits. "+str(len(self.lines))+" LOC, "+str(len(self.functions))+" complete functions from "+str(len(self.repos))+ " repos."
    
    def getRepos(self, skip=None):
        """Get all repos associated with a given author, except for those in skip"""
        with open(os.getcwd()+"/github.token", 'r') as file:
            g = github.MainClass.Github(file.readline)

        users = g.search_users(self.email+" in:email")

        if len(users) == 0:
            print("No matching gh user for author "+self.name)
            return []
        
        if len(users) > 1:
            print("Multiple gh users matching author "+self.name)
        
        repoList = []
        for user in users:
            for repo in user.get_repos():
                if repo.language in gitProfileSet.langList and (not skip or repo not in self.repos):
                    repoList.append(repo)

        return repoList

    def getGPSofSelf(self, skipGiven = True, mine = False):
        """Generates a GPS of all repos this author has contributed, skipping existing repos by default."""

        repos = self.getRepos(skip=skipGiven)
        gps = gitProfileSet(self.name)

        print("fetching repos...")
        for repo in (repos):
            if repo not in self.repos:
                gps.addRepo(repo)

        if mine:
            gps.compileAuthors()   

        return gps
