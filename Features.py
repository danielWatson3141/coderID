from FeatureSet import *
from math import log
class Feature:

    def __init__(self):
        self.featureCount=0
        self.docLength=0
        self.name = None

    def evaluate(self, docStr):
        """Observe feature over document, keeping raw counts with no averaging or log scaling applied"""
        pass
    def merge(self, feature):
        """Combine observations of the same feature over two documents"""
        if self.name != feature.name:
            print("Error: Non-equal features merged, skipping")
            return
        
    def absorb(self, feature):
        """Called by merge, should combine the two sets of observations"""
        pass
    def get(self):
        """Returns feature value. Only override this if normalizer is not log(x/length)"""
        return(log(self.featureCount/self.docLength))
        pass

class Lexical:
    class Word(Feature):
            def __init__(self, word):
                self.name = word
            def evaluate(self, docStr):
                print("unimplemented")

    class keyWordCount(FeatureSet):
        features = {"do": Lexical.Word("do"), "else-if": Lexical.Word("else-if"),"if": Lexical.Word("if"),"else": Lexical.Word("else"),"switch": Lexical.Word("switch"),"for": Lexical.Word("for"),"while": Lexical.Word("while")}
        name = "keywords"


    

