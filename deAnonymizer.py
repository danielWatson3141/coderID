from gitProfileSet import *
from Classifier import *
from coderID import reFeSe

class DeAnonymizer:

    def init(self):
        self.unionProfileSet = gitProfileSet()
        self.authors = dict()
        self.model = None
        self.trainedNames = None

    def addGPS(self, gps):
        """adds gps to self"""
        self.unionProfileSet.merge_into(gps)
            

    def attack(self, gps):
        """returns an NxK martrix with N=number of functions in gps, K=number of authors in self.authors"""
        """each index is the predicted probability that the author wrote the function"""

        if gps.counts == None:
            gps.getFeatures()
        targetFeatures = gps.counts
        targetTargets = gps.target
        targetNames = gps.terms

        if self.unionProfileSet.counts == None:
            self.unionProfileSet.getFeatures()
        trainedFeatures = gps.counts
        trainedTargets = gps.target
        trainedNames = gps.terms

        print("unifying features")

        targetNameIndeces = dict()
        for index in len(targetNames):
            targetNameIndeces[targetNames[index]] = index

        trainedNameIndeces = dict()
        for index in len(self.trainedNames):
            trainedNameIndeces[targetNames[index]] = index

        #take the intersection of available features between the target and source
        commonNames = listIntersection(targetNames, trainedNames)
        
        #filter to common features in trained
        trainedFeatures = filterFeatures(trainedFeatures, trainedNameIndeces, commonNames)
    
        #perform recursive feature elimination on whats left
        selectedFeatureIndeces = reFeSe(Classifier.model, trainedFeatures, trainedTargets)
        selectedNames = [commonNames[i] for i in selectedFeatureIndeces]
        
        
        #redo these because they have changed
        trainedNameIndeces = dict()
        for index in len(self.trainedNames):
            trainedNameIndeces[targetNames[index]] = index


        #filter to only the selected Features
        trainedFeatures = filterFeatures(trainedFeatures, trainedNameIndeces, selectedNames)
        targetFeatures = filterFeatures(targetFeatures, targetNameIndeces, selectedNames)
        
        print("training model")
        clf = Classifier.model()
        clf.fit(trainedFeatures, trainedTargets)
        #predict the probabilities of the functions in the target repo
        return clf.predict(targetFeatures)

def filterFeatures(features, nameIndeces, commonNames):
    featureIndeces = [nameIndeces[name] for name in commonNames]
    return features[:,featureIndeces]

def listIntersection(fs1, fs2):
    return list(set(fs1).intersection(set(fs2)))

def testDeAnonymizer(deAnonymizer, target):
    """deAnonymizer: a DeAnonymizer with profile sets added
    target: a target profile set with authors we want to de-anonymize
    """
    
    pass


