import os.path
import pickle
#import FeatureSet
import PPTools
from sklearn.feature_extraction.text import TfidfVectorizer
from os import walk
from numpy import ndarray

class ProfileSet:
    
    def __init__(self, file, lang="cpp", config=None):
        self.fileSource = file
        self.cfg = config
        self.language = lang
        self.fileCount = 0
        self.docs = []
        self.authors = dict()
        self.featureDetected=False

    def addAuthorsDir(self, topDir):
        preFileCount = self.fileCount

        dirs = ProfileSet.listdir_fullpath(topDir)
        for dir in dirs:
            try:
                self.addAuthor(dir)
            except TypeError:
                dirs.extend(ProfileSet.listdir_fullpath(dir))

        print("Added "+str(self.fileCount-preFileCount)+" files from "+str(len(dirs))+" authors.")

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

    def detectFeatures(self):
        
        inputs=[]
        for doc in self.docs:
            inputs.append(PPTools.Tokenize.tokenize(doc))

        for i in range(0,len(inputs)):
            inputs[i] = PPTools.Tokenize.tokensToText(inputs[i])

        print("Vectorizing...")
        
        vectorizer =  TfidfVectorizer(analyzer="word", token_pattern="\S*", decode_error="ignore", lowercase=False)
        vectorizer.fit(inputs)
        counts = vectorizer.transform(inputs)
        self.counts = counts
        self.terms = vectorizer.get_feature_names()

        self.target = []
        
        targetNum = 1
        for author in self.authors.values() :
            for _ in range(len(author.docs)):
                self.target.append(author.authName)
            targetNum+=1
            #should fit feature detector here
            #then pass it down

class Author:
    def __init__(self, dir, cfg=None, lang="cpp"):
        self.authName = os.path.basename(dir)
        self.docs = []
        self.cfg=cfg
        self.language = lang

        for root, dirs, files in os.walk(dir, topdown=False):
            for name in files:
                fullPath = os.path.join(root, name)
                if lang in name:
                    try:
                        open(fullPath,'r').read()    #Check for error reading file here.
                    except UnicodeDecodeError:
                        continue
                     #print("Assembling profile for author "+authName)
                    self.docs.append(os.path.join(root, name))
                       

    def addDoc(self, file):
        self.docs.append(file)
    
    def merge(self, other):
        self.docs.extend(other.docs)
        
    def __str__(self):
        toRet = self.authName+":\n"
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
            print(Exception.__traceback__)
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

