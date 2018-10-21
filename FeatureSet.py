import PPTools
import os.path
from math import log



class Feature:

    def __init__(self):
        self.featureCount=0
        self.docLength=0
        self.name = None
        self.inputType = "tokens"

    def evaluate(self, input, len):
        """Observe feature over document, keeping raw counts with no averaging or log scaling applied. 
        Only call this method once unless you intend to merge files."""
        self.docLength+=len
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
        return(log(self.featureCount/self.docLength))

            
class Word(Feature):
        def __init__(self, word):
            self.name = word
        def evaluate(self, length):
            """Only use this with wordSet"""
            super(None, length)


class FeatureSet:
    #associate names of features with the appropriate class here    
 
    def __init__(self, file=None):
        self.name = "Generic Set"
        if file==None:
            self.features = deFeatures        
        else:
            self.fs = []
            for line in open(file).readlines():
                self.addFeature(line)

    def addFeature(self, featureToAdd):
        """Add a freshly constructed feature to the set"""
        self.features.update(featureToAdd, deFeatures.get(featureToAdd)())

    def addSubset(self, otherSet):
        """Add a contained subset. Will be evaluated with otherSet.eval before merging. For efficiency"""
        self.features.update(otherSet.name, otherSet)

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
        lang = file_extension
        if lang=="java":
            tokens = PPTools.Tokenize.java(file)
        elif lang=="cpp":
            tokens = PPTools.Tokenize.cpp(file)

        contents = open(file,'r').read()
        for feature in self.features.values():
            if feature.inputType == "tokens":
                feature.evaluate(tokens,len(contents))
            elif feature.inputType == "docText":
                feature.evaluate(contents, len(contents))

    def getFeatureVector(self):
        """Returns feature vector as num[]"""
        vec = []
        for feature in self.features.values():
            if feature is FeatureSet:
                vec.append(feature.getFeatureVector())
            else:
                vec.append(feature.normalizedResult())

        return vec

class wordSet(FeatureSet):
    inputType = "tokens"
    name = "wordSet"
    def evaluate(self, tokens, length):
        for token in tokens:
            if token.spelling() in self.features.keys():
                f = self.features.get(token.spelling())
                f.featureCount+=1

        for feature in self.features:
                feature.evaluate(length)

class keyWordCount(wordSet):
    name = "keyWordCount"
    def __init__(self):
        self.features = {"do": Word("do"),
                    "else-if": Word("else-if"),
                            "if": Word("if"),
                        "else": Word("else"),
                        "switch": Word("switch"),
                        "for": Word("for"),
                        "while": Word("while")}
                        

deFeatures = {
        "keyWordCount": keyWordCount
    }





            
       

    


    


