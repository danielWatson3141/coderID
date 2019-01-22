import PPTools
import os.path
from math import log

from sklearn.feature_extraction.text import CountVectorizer

class Feature:

    def __init__(self, name):
        self.featureCount=0
        self.docLength=0
        self.name = name
        self.inputType = "tokens"

    def evaluate(self, input):
        """Observe feature over document, keeping raw counts with no averaging or log scaling applied. 
        Only call this method once unless you intend to merge files."""
        pass      
        
    def merge(self, feature):
        """Combine observations of the same feature over two documents"""
        if self.name != feature.name:
            print("Error: Non-equal features merged, skipping")
            return
        self.featureCount = self.featureCount + feature.featureCount 
        self.docLength = self.docLength + feature.docLength
    
    def normalizedResult(self):
        """Proper normalizer for this feature value. Only override this if normalizer is not log(x/length)"""
        if self.featureCount == 0:
            return 0
        return(log(self.featureCount/self.docLength))


class FeatureSet(Feature):
       
 
    def __init__(self, file=None):
        self.name = "Generic Set" 
        self.features = dict()
        self.inputType = "file"
        if file==None:
            for featureName in deFeatures.keys():
                self.addFeature(featureName)        
        else:
            self.fs = []
            for line in open(file).readlines():
                self.addFeature(line)

    def addFeature(self, featureToAdd):
        """Add a freshly constructed feature to the set"""
        self.features.update({featureToAdd: deFeatures.get(featureToAdd)()})

    
    def merge(self, other):
        """Merge two feature sets. The result is the union, with matching features merged"""
        myFeat = self.features
        otherFeat = other.features

        for key in otherFeat.keys():
            if key in myFeat:
                myFeat.get(key).merge(otherFeat.get(key))
            else:
                myFeat.update(key, otherFeat.get(key))
            

    def evaluate(self, file):
        """Default for feature set. ALL SUBCLASSES should override this"""
        
        filename, file_extension = os.path.splitext(file)
        lang = file_extension[1:]
        tokens=""
        if lang=="java":
            tokens = PPTools.Tokenize.java(file)
        elif lang=="cpp":
            tokens = PPTools.Tokenize.cpp(file)
       
        contents = open(file,'r').read()

        for feature in self.features.values():
            if feature.inputType == "tokens":
                feature.evaluate(tokens)
            elif feature.inputType == "docText":
                feature.evaluate(contents)
            elif feature.inputType == "file":
                feature.evaluate(file)

    def getFeatureVector(self):
        """Returns feature vector as num[]"""
        vec = []
        for feature in self.features.values():
            if isinstance(feature, FeatureSet):
                vec.append(feature.getFeatureVector())
            else:
                vec.append(feature.normalizedResult())

        return vec

class wordSet(FeatureSet):
    inputType = "tokens"
    name = "wordSet"
    def __init__(self):
        pass


    def evaluate(self, tokens):
        for token in tokens:
            try:
                if token.spelling in self.features:
                    f = self.features.get(token.spelling)
                    f.featureCount+=1
            except UnicodeDecodeError:
                #print("Failed to parse char")
                continue

        for feature in self.features.values():
                feature.evaluate("",len(tokens))


        

class keyWordCount(wordSet):
    #associate names of features with the appropriate class here 
    name = "keyWordCount"
    def __init__(self):
        self.features = {"do","else-if","if","else","switch","for","while"}
        

deFeatures = {
        "keyWordCount": keyWordCount
    }
