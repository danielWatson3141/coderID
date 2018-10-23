import os.path
import pickle
import FeatureSet
import PPTools
from sklearn.feature_extraction.text import CountVectorizer
from os import walk
from numpy import ndarray

class ProfileSet:
    
    def __init__(self, file, lang="cpp", config=None):
        self.fileSource = file
        self.cfg = config
        self.language = lang
        self.fileCount = 0
        self.docs = []
        if os.path.isfile(file):
            file = open(file, 'rb')
            self.authors = dict()
            self.merge(pickle.Unpickler(file).load())
        else:
            self.authors = dict()

    def addAuthorsDir(self, topDir):
        preAuthCount = self.authCount()
        preFileCount = self.fileCount

        dirs = ProfileSet.listdir_fullpath(topDir)
        for dir in dirs:
            self.addAuthor(dir)
           

        print("Added "+str(self.fileCount-preFileCount)+" files from "+str(self.authCount()-preAuthCount)+" authors.")

    def authCount(self):
        return len(self.authors)


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
            self.fileCount += len(nAuth.docs) - len(self.authors.get(os.path.basename(dir)).docs)
            self.authors.get(os.path.basename(dir)).merge(nAuth)
            print("author "+dir+" was merged.")
        


    def detectFeatures(self):
        
        inputs=[]
        for doc in self.docs:
            inputs.append(PPTools.Tokenize.tokenize(doc.fileSource))

        for i in range(0,len(inputs)):
            inputs[i] = self.tokensToText(inputs[i])

        print("Vectorizing...")
        
        vectorizer = CountVectorizer(analyzer="word", token_pattern="\S*", decode_error="ignore", lowercase=False)
        counts = vectorizer.fit_transform(inputs)
        self.counts = counts
            
            #should fit feature detector here
            #then pass it down

    @staticmethod
    def tokensToText(tokens):
        returnString = ""
        for token in tokens:
            returnString=returnString+token.spelling+ " "

        return returnString

    def toFeatureMatrix(self):
        target = []
        targetNum=0
        mat = []
        for author in self.authors.values() :
            mat.append(author.featureMatrix())
            for _ in range(len(author.docs)):
                target.append(targetNum)
            targetNum+=1
        
        return sum(mat,[]), target

    def __str__(self):
        if self.cfg==None:
            return str(FeatureSet.deFeatures.keys()).replace(",","\n")
        else:
            return str(FeatureSet.FeatureSet(self.cfg)).replace(",","\n")
            

    

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
                        contents = open(fullPath,'r').read()
                    except UnicodeDecodeError:
                        continue
                     #print("Assembling profile for author "+authName)
                    self.docs.append(Document(os.path.join(root, name), cfg))
                       

    def addDoc(self, file):
        self.docs.append(Document(file, self.cfg))
    
    def merge(self, other):
        self.docs.append(other.docs)

    def collectForAllDocs(self):
        print("Collecting for "+self.authName)
        #fit_transform(docs, )
        
    def featureMatrix(self):
        featureMat = list()
        for i in range(1, len(self.docs)):
            featureMat.append(self.docs[i].featureVector())
        return featureMat

    def __str__(self):
        toRet = self.authName+":\n"
        for doc in self.docs:
            toRet += "\t"+doc.name+"\n"
        return toRet


class Document:
    def __init__(self, file, cfg=None):
        
        self.name = os.path.basename(file)
        self.fileSource = file
        self.featureSet = FeatureSet.FeatureSet(cfg)

    def collect(self):
        self.featureSet.evaluate(self.fileSource)

    def featureVector(self):
        return self.featureSet.getFeatureVector()

    def __str__(self):
        return self.name