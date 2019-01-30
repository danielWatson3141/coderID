import os.path
import pickle
#import FeatureSet
import PPTools
import featureExtractors
import sys
import warnings
if not sys.warnoptions:
    warnings.simplefilter("ignore")
import numpy as np

from scipy.sparse import hstack, vstack, csr_matrix
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.feature_selection import mutual_info_classif, SelectKBest
from os import walk
from numpy import ndarray

from tqdm import tqdm

class ProfileSet:
    
    def __init__(self, lang="cpp", config=None):
        
        self.cfg = config
        self.language = lang
        self.fileCount = 0
        self.docs = []
        self.authors = dict()
        self.featuresDetected=False

    def addAuthorsDir(self, topDir):
        """Take a directory of directories, each of which contains an author's work"""
        preFileCount = self.fileCount

        dirs = ProfileSet.listdir_fullpath(topDir)
        for dir in dirs:
            try:
                self.addAuthor(dir)
            except TypeError:
                dirs.extend(ProfileSet.listdir_fullpath(dir))

        #print("Added "+str(self.fileCount-preFileCount)+" files from "+str(len(dirs))+" authors.")

    def authCount(self):
        return len(self.authors)

    def pruneAuthors(self,n, k):
        myCopy = self.authors.copy()
        for pair in myCopy.items():
            if len(pair[1].docs) < int(k):
                for doc in pair[1].docs:
                    self.docs.remove(doc)
                del self.authors[pair[0]]
        
        myCopy = self.authors.copy()
        import operator
        topNAuthors = sorted(myCopy.items(), key=operator.itemgetter(1), reverse=True)[:n]
        for pair in myCopy.items():
            if pair not in topNAuthors:
                for doc in pair[1].docs:
                    self.docs.remove(doc)
                del self.authors[pair[0]]

    def pruneFeatures(self):
        from sklearn import feature_selection
        self.counts = feature_selection.SelectKBest(feature_selection.mutual_info_classif,k=1000).fit_transform(self.counts,self.target)
                        



    @staticmethod
    def listdir_fullpath(d):
        return [os.path.join(d, f) for f in os.listdir(d)]

    def merge(self, otherPS):
        old = self.authors
        new = otherPS.authors

        new.update(old)
        self.authors = new

        
    def addAuthor(self, dir):
        #print("Trying to build author: "+dir)
        nAuth = Author(dir,self.cfg, self.language)
        if len(nAuth.docs)==0:
            #print("No docs of type "+self.language+" found in "+dir)
            return
        if os.path.basename(dir) not in self.authors:
            self.docs=self.docs+nAuth.docs
            self.fileCount += len(nAuth.docs)
            self.authors.update({os.path.basename(dir):nAuth})
        else:
            self.docs=self.docs+nAuth.docs
            self.fileCount += len(nAuth.docs)
            self.authors.get(os.path.basename(dir)).merge(nAuth)
            #print("author "+dir+" was merged.")

    def fileConcat(self):
        self.docs =[]
        for author in self.authors.values():
            author.fileConcat()
            self.docs.extend(author.docs)

    def detectFeatures(self, maxDocs):
        
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
        textLines = list(len(lines))

        for lineInfo, line in lines:
            cHash, fil, lnum = lineInfo
            textLines[lnum] = line

        return "\n".join(textLines)

class Author:
    def __init__(self, dir, cfg=None, lang="cpp"):
        self.name = os.path.basename(dir)
        self.docs = []
        self.cfg=cfg
        self.language = lang

        for root, dirs, files in os.walk(dir, topdown=False):
            for name in files:
                fullPath = os.path.join(root, name)
                #print(name)
                if "cpp" in name:
                    try:
                        open(fullPath,'r').read()    #Check for error reading file here.
                    except UnicodeDecodeError:
                        continue
                     #print("Assembling profile for author "+authName)
                    #print("Got "+name)
                    self.docs.append(os.path.join(root, name))
                       

    def addDoc(self, file):
        self.docs.append(file)
    
    def merge(self, other):
        self.docs.extend(other.docs)
        
    def __str__(self):
        toRet = self.name+":\n"
        for doc in self.docs:
            toRet += "\t"+str(doc)+"\n"
        return toRet

    def __lt__(self, other):
        return len(self.docs) < len(other.docs)

    def fileConcat(self):
        """irreversable. Joins files in the same solution to be a single file and deletes the originals."""
        newdocs = []
        try:
            for filePath in self.docs:
                fileset = ProfileSet.listdir_fullpath(os.path.dirname(filePath))
                if len(fileset) <= 1:
                    newdocs.append(filePath)
                    continue
                outfilename = ""
                for file in fileset:
                    filename, file_extension = os.path.splitext(file)
                    outfilename = outfilename+"+"+os.path.basename(filename)[:-4]
                
                outfilename = outfilename+"."+self.language

                if os._exists(outfilename):
                    continue

                newdocs.append(outfilename)

                with open(outfilename, 'w') as outfile:
                    for fname in fileset:
                        with open(fname, 'r') as readfile:
                            outfile.write(readfile.read() + "\n\n")
        except Exception:
            print(Exception)
            print("Something went wrong, No changes made.")
            return
        for doc in self.docs:
            if doc not in newdocs:
                os.remove(doc)
        self.docs=newdocs
                        

    
    @staticmethod
    def is_number(s):
        try:
            float(s)
            return True
        except ValueError:
            pass
    
        try:
            import unicodedata
            unicodedata.numeric(s)
            return True
        except (TypeError, ValueError):
            pass
    
        return False    

