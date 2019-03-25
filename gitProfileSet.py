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


class gitProfileSet:

    #TODO: Make it so re-compiling doesn't break
    #TODO: Make sibling class of ProfileSet
    
    langList =["cpp", "c"]
    def __init__(self, name):
        """Initialize a new gitset"""
        self.name = name
        self.repos = []
        self.authors = dict()
        self.featuresDetected = False
        self.featuresSelected = None
        self.termsSelected = None
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
        for repo in self.repos:
            if repo in self.minedRepos:
                continue
            elif authors is not None:
                self.minedRepos.add(repo)
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
        numAuthors = PPTools.Config.get_value('Model', 'number_of_authors')
        # Flags from the config indicating whether to include each feature type or not
        ast_flag = PPTools.Config.get_value('Feature Levels', 'ast_level')
        tok_flag = PPTools.Config.get_value('Feature Levels', 'token_level')
        char_flag = PPTools.Config.get_value('Feature Levels', 'char_level')

        inputs=[]
        node_types = []
        node_bigrams = []
        depths = None
        depths_names = ['max_ast_node_depth', 'avg_ast_node_depth']
        node_type_depths = Counter()
        code_unigrams = []

        self.counts = None
        self.terms = []
        self.target = []

        charfeatureNames = featureExtractors.featureExtractors.charfeatureNames
        charLevelFeatures = None
        tokfeatureNames = featureExtractors.featureExtractors.tokfeatureNames
        tokFeatures = None

        fns_seen = 0
        fns_failed = 0
        invalid_fns = 0
        no_tokens_fns = 0
        print("Gathering char and token level features") # generating tokens/unigrams
        authors_seen = 0

        for author in tqdm(self.authors.values()):
            if numAuthors != -1 and authors_seen == numAuthors:
                    break
            authors_seen += 1

            for fun in author.functions:
                fn_str = fun #due to refactor

                #whitespace fn's still getting in. This will catch for that.
                if fn_str.isspace() or fn_str == '':
                    continue

                fns_seen += 1
                self.target.append(author.name)

                # Function-string level features
                if char_flag:
                    if charLevelFeatures is None:
                        charLevelFeatures = featureExtractors.featureExtractors.characterLevel(fn_str)
                    else:
                        charLevelFeatures = vstack([charLevelFeatures,
                                                    featureExtractors.featureExtractors.characterLevel(fn_str)])

                try:
                    tu = PPTools.Tokenize.get_tu(fn_str)
                    tokens = list(tu.get_tokens(extent=tu.cursor.extent))  # Sometimes this  breaks for n.a.r.

                    if tok_flag:
                        if tokFeatures is None:
                            tokFeatures = featureExtractors.featureExtractors.tokenLevel(tokens)
                        else:
                            tokFeatures = vstack([tokFeatures,
                                                  featureExtractors.featureExtractors.tokenLevel(tokens)])
                        inputs.append(PPTools.Tokenize.tokensToText(tokens))  # Convert to text
                except Exception as e:
                    """
                    msg = str(e)
                    fname = "test/{}/no_tokens{}.cpp".format(self.name, no_tokens_fns)
                    no_tokens_fns += 1
                    with open(fname, "w+") as f:
                        f.write(fn_str + "\n")
                        f.write("+++++++++++++++++++++++++++++++\n")
                        f.write(msg)
                    """
                    continue

                try:
                    # Function tokens level features
                    if ast_flag:
                        tokens = list(tu.get_tokens(extent=tu.cursor.extent))
                        token_text = PPTools.Tokenize.tokensToText(tokens, ignore_comments=True)  # can't use this for inputs, but need to ignore comments for AST features
                        token_text = token_text.split(" ")
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

                except Exception as e:
                    """
                    msg = str(e)
                    fname = "test/{}/failed{}.cpp".format(self.name, fns_failed)

                    if "Ill-defined function" in msg:
                        fname = "test/{}/invalid{}.cpp".format(self.name, invalid_fns)
                        invalid_fns += 1
                    else:
                        fns_failed += 1

                    with open(fname, "w+") as f:
                        f.write(fn_str + "\n")
                        f.write("+++++++++++++++++++++++++++++++\n")
                        f.write(msg)
                        # raise(e)
                    """

                    node_bigrams.append("")
                    node_types.append("")
                    depths = vstack([depths, csr_matrix([0,0], shape=(1, 2))])
                    for node_type in node_type_depths:
                        node_type_depths[node_type].append(0.0)


                del tokens
            
        inputs = np.array(inputs)
        node_types = np.array(node_types)
        node_bigrams = np.array(node_bigrams)

        """
        if ast_flag:
            msg = "Functions seen: {}\n".format(fns_seen)
            msg += "Stats:\n" + "Invalid functions: {:.2f}%\n".format(100 * invalid_fns / fns_seen)
            msg += "Valid functions that were successfully parsed: {:.2f}%".format(100 * (1 - fns_failed / (fns_seen - invalid_fns)))

            resultLocation = os.getcwd() + "/classResults/"
            with open(resultLocation + self.name + "_function_parsing.txt", 'w+') as f:
                print(msg)
                f.write(msg)
        """

        print("Vectorizing...")
        vectorizer =  TfidfVectorizer(analyzer="word", token_pattern="\S+",
                                       decode_error="ignore", lowercase=False)
        vectorizer_tf = TfidfVectorizer(analyzer="word", token_pattern="\S+",
                                        decode_error="ignore", lowercase=False,
                                        use_idf=False)

        # Character-level
        if char_flag:
            self.counts = hstack([self.counts, charLevelFeatures], format = 'csr')
            self.terms += charfeatureNames


        # Token-Level
        if tok_flag:
            # TFIDF
            self.counts = hstack([self.counts, vectorizer.fit_transform(inputs)],
                                 format = 'csr')
            self.terms += vectorizer.get_feature_names()
            # Token features
            self.counts = hstack([self.counts, tokFeatures], format='csr')
            self.terms += tokfeatureNames


        # AST-Level
        if ast_flag:
            self.counts = hstack([self.counts, depths], format='csr')
            self.terms += depths_names

            # adding the node_type_depths
            node_type_depth_names = node_type_depths.keys()
            for node_type in node_type_depth_names:
                depth_vector = np.array(node_type_depths[node_type]).reshape((fns_seen, 1))
                depth_vector = csr_matrix(depth_vector, shape = (fns_seen, 1))
                self.counts = hstack([self.counts, depth_vector], format='csr')
            self.terms += node_type_depth_names
            del node_type_depth_names

            # AST Node Types TF and TFIDF
            self.counts = hstack([self.counts, vectorizer.fit_transform(node_types),
                                  vectorizer_tf.fit_transform(node_types)], format='csr')
            self.terms += vectorizer.get_feature_names() + vectorizer_tf.get_feature_names()

            # AST Node Bigrams TF
            vectorizer = TfidfVectorizer(analyzer="word", lowercase=False,
                                         tokenizer=lambda x: x.split(";"))
            self.counts = hstack([self.counts, vectorizer.fit_transform(node_bigrams)],
                                 format='csr')
            self.terms += vectorizer.get_feature_names()

            """
            with open("test/{}/bigrams.txt".format(self.name), "w+") as f:
                for bigram in vectorizer.get_feature_names():
                    f.write(bigram + "\n")
            """

        del inputs, node_types, code_unigrams, node_bigrams

        self.target = np.array(self.target)
        #self.featuresDetected = True
            #should fit feature detector here
            #then pass it down
    
    def functionToString(self, lines):
        return "\n".join(lines.values())

    
    def __str__(self):
         return (str(len(self.authors))+" authors. "+str(sum(map(lambda x: len(x.functions), self.authors.values())))+" functions in total.")

        
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
        for repo in tqdm(repos):
            if repo not in self.repos:
                gps.addRepo(repo)

        if mine:
            gps.compileAuthors()   

        return gps

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

