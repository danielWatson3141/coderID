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
    
    def __init__(self, name):
        self.name = name
        self.authors = dict()
        self.featuresDetected = False
        self.featuresSelected = None
        self.termsSelected = None
        self.minedRepos = set()
        self.featureTypes = dict()

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

    def getFeatures(self, maxDocs):
        pass

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

