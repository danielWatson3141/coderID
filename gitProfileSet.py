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
from ProfileSet import ProfileSet

class gitProfileSet:

    #TODO: Make it so re-compiling doesn't break
    #TODO: Make sibling class of ProfileSet
    
    langList =["cpp"]
    def __init__(self, name):
        """Initialize a new gitset"""
        self.name = name
        self.repos = []
        self.authors = dict()
        self.featuresDetected = False
        self.featuresSelected = None
        self.termsSelected = None
        self.minedRepos = set()
        self.commits = set()
        
    def addRepo(self, args):
        #print("Adding repo: "+args)
        try:
            if args not in self.repos:
                self.repos.append(args)
        except Exception:
            print("Couldn't get that one...")
        #self.compileAuthors(newRepo)

    def rmRepo(self, arg):
        self.repos.remove(arg)

    def rmAuthor(self, arg):
        self.authors[arg] = None  
    
    def compileAuthors(self, authors = None):
        """Mine all repos in the repo list for commits by those in authors. None for get all"""
        print("mining "+self.name)

        reposToMine = []
        for repo in self.repos:
            if repo not in self.minedRepos:
                reposToMine.append(repo)

        for repo in reposToMine:
            if not os.path.exists(repo+"/.git"): #in case the repo is one level down
                repo = repo+"/"+os.listdir(repo)[0]
                #print("moved to "+repo)
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
                    
                    if commit.hash in author.commits or commit.hash in self.commits:
                        continue    #don't reprocess seen hashes

                    self.commits.add(commit.hash)
                    author.commits.add(commit.hash)

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
        self.repos = self.minedRepos

    def displayAuthors(self):
        for value in self.authors.values():
            print(value)


    def getAllFunctions(self):
        functions = []
        for author in self.authors.values():
            functions.extend(author.functions)

        return functions


    def getFeatures(self):

        if len(self.authors) == 0:
            self.compileAuthors()

        numAuthors = PPTools.Config.get_value('Model', 'number_of_authors')

        inputs=[]
        node_types = []
        node_bigrams = []
        depths = None
        depths_names = ['max_ast_node_depth', 'avg_ast_node_depth']
        node_type_depths = Counter()
        code_unigrams = []

        self.target = []
        charfeatureNames = featureExtractors.featureExtractors.charfeatureNames
        charLevelFeatures = None
        tokfeatureNames = featureExtractors.featureExtractors.tokfeatureNames
        tokFeatures = None
        fns_seen = 0
        fns_failed = 0
        print("Gathering char and token level features") # generating tokens/unigrams
        authors_seen = 0

        for author in tqdm(self.authors.values()):
            if numAuthors != -1 and authors_seen == numAuthors:
                    break
            authors_seen += 1

            for fun in author.functions:

                fns_seen += 1

                fn_str = fun #due to refactor

                #whitespace fn's still getting in. This will catch for that.
                if fn_str.isspace() or fn_str == '':
                    continue

                # having these below meant that they didn't run if a function wasn't parse correctly
                self.target.append(author.name)
                # Function-string level features
                # processing 11 less functions now
                
                tu = PPTools.Tokenize.get_tu(fn_str)
                tokens = list(tu.get_tokens(extent=tu.cursor.extent)) #Sometimes this  breaks for n.a.r.
                # inputs.append(PPTools.Tokenize.tokensToText(tokens))

                import copy
                # getting the token pointer-related errors; comment out for now
                token_text = PPTools.Tokenize.tokensToText(tokens, ignore_comments=True) # can't use this for inputs, but need to ignore comments for AST features
                inputs.append(token_text)  # Convert to text

                token_text = token_text.split(" ")
                try:
                    ast_feature_ext = ASTFeatureExtractor.ASTFeatures(token_text)
                    ast_feature_ext.traverse()

                    # Integrating the AST features
                    node_types.append(ast_feature_ext.node_types)
                    node_bigrams.append(ast_feature_ext.bigrams_text)
                    depths = vstack([depths, ast_feature_ext.depths])

                    # Adding in all the node type depths from current function
                    for node_type in ast_feature_ext.type_depths:
                        if node_type not in node_type_depths:
                            node_type_depths[node_type] = [0.0] * (fns_seen - 1)
                        node_type_depths[node_type].append(ast_feature_ext.type_depths[node_type])

                    # Updating the node types that were not seen in this function but were seen before
                    for node_type in node_type_depths:
                        if node_type not in ast_feature_ext.type_depths:
                            node_type_depths[node_type].append(0.0)
                except:
                    node_bigrams.append("")
                    node_types.append("")
                    depths = vstack([depths, csr_matrix([0,0], shape=(1, 2))])
                    for node_type in node_type_depths:
                        node_type_depths[node_type].append(0.0)
                    fns_failed += 1
                    #continue

                # Function-string level features
                if charLevelFeatures is None:
                    charLevelFeatures = featureExtractors.featureExtractors.characterLevel(fn_str)
                else:
                    charLevelFeatures = vstack([charLevelFeatures,
                                                featureExtractors.featureExtractors.characterLevel(fn_str)])

                if tokFeatures is None:
                    tokFeatures = featureExtractors.featureExtractors.tokenLevel(tokens)
                else:
                    tokFeatures = vstack([tokFeatures, featureExtractors.featureExtractors.tokenLevel(tokens)])

                del tokens, token_text
            
        inputs = np.array(inputs)
        node_types = np.array(node_types)
        node_bigrams = np.array(node_bigrams)

        print("Functions successfully parsed: {:.2f}%".format(100 * (1 - fns_failed / fns_seen)))
        print("Vectorizing...")
        vectorizer =  TfidfVectorizer(analyzer="word", token_pattern=r"\S+",
                                       decode_error="ignore", lowercase=False)
        vectorizer_tf = TfidfVectorizer(analyzer="word", token_pattern=r"\S+",
                                        decode_error="ignore", lowercase=False,
                                        use_idf=False)

        self.counts = hstack([charLevelFeatures, depths, tokFeatures], format = 'csr')
        self.terms = charfeatureNames + depths_names + tokfeatureNames

        def updateTypes(names, typeName):
            if not hasattr(self, "featureTypes"):
                self.featureTypes = dict()
            for name in names:
                self.featureTypes[name] = typeName

        updateTypes(charfeatureNames, "char")
        updateTypes(depths_names, "AST")
        updateTypes(tokfeatureNames, "token")
        # adding the node_type_depths
        node_type_depth_names = node_type_depths.keys()
        for node_type in node_type_depth_names:
            depth_vector = np.array(node_type_depths[node_type]).reshape((fns_seen, 1))
            depth_vector = csr_matrix(depth_vector, shape = (fns_seen, 1))
            self.counts = hstack([self.counts, depth_vector], format='csr')
        self.terms += node_type_depth_names
        updateTypes(node_type_depth_names, "AST")
        del node_type_depth_names

        # Tokens TFIDF
        self.counts = hstack([self.counts, vectorizer.fit_transform(inputs)],
                             format = 'csr')
        self.terms += vectorizer.get_feature_names()
        updateTypes(vectorizer.get_feature_names(), "token_TF/IDF")

        # AST Node Types TF and TFIDF
        self.counts = hstack([self.counts, vectorizer.fit_transform(node_types),
                              vectorizer_tf.fit_transform(node_types)], format='csr')
        self.terms += vectorizer.get_feature_names() + vectorizer_tf.get_feature_names()

        updateTypes(vectorizer.get_feature_names(), "node_type_TF/IDF")
        updateTypes(vectorizer_tf.get_feature_names(), "node_type_TF")
        

        # AST Node Bigrams TF
        vectorizer = TfidfVectorizer(analyzer="word", lowercase=False,
                                     tokenizer=lambda x: x.split(";"))

        self.counts = hstack([self.counts, vectorizer.fit_transform(node_bigrams)],
                             format='csr')
        self.terms += vectorizer.get_feature_names()
        updateTypes(vectorizer.get_feature_names(), "AST_Node_Bigrams_TF/IDF")
        


        del inputs, node_types, code_unigrams, node_bigrams

        self.target = np.array(self.target)
        self.featuresDetected = True
            #should fit feature detector here
            #then pass it down
    
    def functionToString(self, lines):
        return "\n".join(lines.values())

    
    def __str__(self):
         return (str(len(self.authors))+" authors. "+str(sum(map(lambda x: len(x.functions), self.authors.values())))+" functions in total.")
    
    def __lt__(self, other):
        return  self.name.lower() < other.name.lower()

    def merge_into(self, other):
        """merges other into self"""
        other.compileAuthors()  #get author data first
        for repo in other.repos:
            if repo not in self.repos:
                self.repos.append(repo)

        for authorName, author in other.authors.items():
            if authorName in self.authors:
                self.authors[authorName].merge(author)
            else:
                self.authors[authorName] = author

    def fetch_authors_other_work(self):
        """attempts to grab the repos of all authors in the set"""
        sumGPS = gitProfileSet("inverse_"+self.name)
        repoList = []
        from git import Repo
        
        for repoLocation in self.repos:
            
            local = Repo(repoLocation)
            remote = local.remotes[0]

            url = list(remote.urls)[0]
            if "github.com" not in url:
                print("not a github url, can't get contributors for "+repoLocation)
                continue

            
            #initialize pygithub object
            with open(os.getcwd()+"/github.token", 'r') as file:
                g = github.MainClass.Github(file.readline())
            while(g.rate_limiting[0]==0):
                pass

            import re
            splUrl = re.split("[./:]", url)
            fullRepoName = splUrl[5]+"/"+splUrl[6] #get qualified project name from remote url

            githubRepo = g.get_repo(fullRepoName)
            #get Contributors
            contributors = (githubRepo.get_contributors())
            
            for contributor in tqdm(contributors):
                for repo in contributor.get_repos():
                    repoList.append(repo.full_name)

        return repoList
class gitAuthor:

    def __init__(self, dev):
        if dev is not None:
            self.name = dev.name
            self.email = dev.email
        self.commits = set() #store with commitHash
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
            g = github.MainClass.Github(file.readline())
        while(g.rate_limiting[0]==0):
            pass
        users = g.search_users(self.email+" in:email")
        repoList = []
        try:
            for user in users:
                for repo in user.get_repos():
                    if repo.language == "C++":
                        repoList.append(repo)

                break #get only first user's stuff
        except Exception:
            #print("email not found: "+self.email)
            pass

        try:
            if repoList == []:
                users = g.search_users(self.name+" in:fullname")
            for user in users:
                for repo in user.get_repos():
                    if repo.language == "C++":
                        repoList.append(repo)

                break #get only first user's stuff
        except Exception:
            #print("name not found: "+self.name)
            pass

        return repoList

    def getRepoListofSelf(self, skipGiven = True, mine = False):
        """Generates a GPS of all repos this author has contributed, skipping existing repos by default."""

        #print("fetching repos from "+self.name)
        repos = self.getRepos(skip=skipGiven)
        return [repo.clone_url for repo in repos]

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
    def categorize(commit, langList=None):
        added = 0
        removed = 0
        for mod in commit.modifications:
            if mod.new_path is None or (langList is not None and mod.new_path.split(".")[-1] not in langList):
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

