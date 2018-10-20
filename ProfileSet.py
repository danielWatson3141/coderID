import os.path
import pickle

class ProfileSet:
    fileSource = None
    authors = []

    def merge(self, otherPS):
        print("merging...")
    def addAuthor(self, dir): 
        print("adding author")

    def __init__(self, file):
        self.fileSource = file
        if os.path.isfile(file):
            self.merge(pickle.Unpickler(file).load)
        else:
            self.authors = []

class Author:
    authName = None
    docs = []
    def __init__(self, file):
        authName = os.path._getfinalpathname(file)
        print("Assembling profile for author "+authName)
        docs.append(file)
    def addDoc(self, file):


class Document:

    def __init__(self, fileS, docStr, feat):
        self.fileSource = fileS
        self.docString = docStr
        self.features = feat


  
