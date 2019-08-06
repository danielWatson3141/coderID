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
from pathlib import Path

class codeJamProfileSet:

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
        self.files = set()

    #adds all .cpp files in the given GCJ directory
    def addFiles(self, gcjDir = "gcjExtractedFiles/gcj"):
        print("Finding Files")
        for fileName in tqdm(Path(gcjDir).glob("**/*.cpp")):
            self.files.add(str(fileName))
            
    
    def compileAuthors(self, authors = None):
        """Mine all repos in the repo list for commits by those in authors. None for get all"""
        
        if not self.files:
            self.addFiles()

        print("Analyzing Files")
        filesToDiscard = set()

        #decide whether to extract just functions or whole files
        wholeFile = PPTools.Config.get_value("CodeJam", "whole_file")

        if wholeFile:
            print("Analyzing whole file.")
        else:
            print("Analyzing functions.")


        #decide whether to limit the number of extracted files
        limit = bool(PPTools.Config.get_value("Pruning", "limit_to_k"))

        if limit:
            limit = int(PPTools.Config.get_value("Pruning", "funcs_to_keep"))
        else:
            limit = float("inf")

        print("file limit: "+str(limit))


        for fileName in tqdm(self.files):
            try:
                authorName = fileName.split("/")[-5]
                
                if authors is not None and authorName not in authors:
                    continue
                
                if authorName not in self.authors:
                    self.authors.update({authorName:Author(authorName)}) #add new author
                    #print("Found new author: "+author.name)
                
                author = self.authors.get(authorName)

                if len(author.files) >= limit:
                    continue

                if fileName not in author.files:
                    author.files.add(fileName)

                lines = open(fileName).readlines()
                lineIndex = 0
                for line in lines:
                    author.lines[(fileName, lineIndex)] = line
                    lineIndex += 1
                
                
                if wholeFile:
                    author.functions.append("".join(lines))
                else:
                    import lizard
                    fileInfo = lizard.analyze_file(fileName)

                    

                    for fun in fileInfo.function_list:
                        newFun = []            
                        
                        for lineIndex in range(fun.start_line-1, fun.end_line):
                            newFun.append(author.lines[(fileName, lineIndex)])

                        author.functions.append("".join(newFun))
            except Exception:
                filesToDiscard.add(fileName)
        
        self.files.difference_update(filesToDiscard)
        print("skipped "+str(len(filesToDiscard))+" files due to errors.")
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

                fn_str = fun #due to refactor

                #whitespace fn's still getting in. This will catch for that.
                if fn_str.isspace() or fn_str == '':
                    continue

                fns_seen += 1

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
                except Exception as e:
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

        
class Author:

    def __init__(self, name):
        
        self.name = name
        self.files = set()
        self.functions = list() #list of str
        self.lines = dict() #key: {file.cpp,lineNumber} value: literal code
        self.repos = set()
    
    def merge(self, other):
        """merges the authors into one author object, keeping self.name"""
        print("Merging author: "+self.name)
        self.functions.extend(other.functions)
        self.files.union(other.files)
        
    def __str__(self):
        return self.name+": "+str(len(self.files))+" files. "+str(len(self.lines))+" LOC, "+str(len(self.functions))+" complete functions."