

class FeatureSet:
    features = dict()        
    name = "Generic Set"
    
    def addFeature(self, featureToAdd):
        """Add a freshly constructed feature to the set"""
        self.features.update(featureToAdd.name, featureToAdd)

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
            
    def finalize(self):
        for feature in self.features.values():  
            feature.normalize()

    def evaluate(self, docStr):
        for feature in self.features.values():
            feature.evaluate(docStr)

