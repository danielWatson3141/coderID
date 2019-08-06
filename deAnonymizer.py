from gitProfileSet import *
from Classifier import *
from coderID import MyPrompt
from Classifier import *
from sklearn import metrics
class DeAnonymizer:

    def __init__(self, weapon):
        self.profileSet = weapon
        self.authors = self.profileSet.authors
        self.model = None
        self.trainedNames = None           

    def attack(self, gps):
        """returns an NxK martrix with N=number of functions in gps, K=number of authors in self.authors"""
        """each index is the predicted probability that the author wrote the function"""

        targetFeatures = gps.counts
        targetTargets = gps.target
        targetNames = gps.terms

        trainedFeatures = self.profileSet.counts
        trainedTargets = self.profileSet.target
        trainedNames = self.profileSet.terms

        print("unifying features")

        targetNameIndeces = dict()
        for index in range(len(targetNames)):
            targetNameIndeces[targetNames[index]] = index

        trainedNameIndeces = dict()
        for index in range(len(trainedNames)):
            trainedNameIndeces[trainedNames[index]] = index

        #take the intersection of available features between the target and source
        commonNames = listIntersection(targetNames, trainedNames)
        
        #filter to common features in trained
        trainedFeatures = filterFeatures(trainedFeatures, trainedNameIndeces, commonNames)
    
        #perform recursive feature elimination on whats left
        selectedFeatureIndeces = MyPrompt.reFeSe(Classifier().model, trainedFeatures, trainedTargets)
        selectedNames = [commonNames[i] for i in selectedFeatureIndeces]
        
        
        #redo these because they have changed
        trainedNameIndeces = dict()
        for index in range(len(selectedNames)):
            trainedNameIndeces[selectedNames[index]] = index


        #filter to only the selected Features
        trainedFeatures = filterFeatures(trainedFeatures, trainedNameIndeces, selectedNames)
        targetFeatures = filterFeatures(targetFeatures, targetNameIndeces, selectedNames)
        
        print("training model")
        clf = Classifier().model
        clf.fit(trainedFeatures, trainedTargets)
        #predict the probabilities of the functions in the target repo
        print("predicting")
        return (clf.predict_proba(targetFeatures), clf.classes_)

def filterFeatures(features, nameIndeces, commonNames):
    featureIndeces = [nameIndeces[name] for name in commonNames]
    return features[:,featureIndeces]

def listIntersection(fs1, fs2):
    return list(set(fs1).intersection(set(fs2)))

def testDeAnonymizer(deAnonymizer, target):
    """deAnonymizer: a DeAnonymizer with profile sets added
    target: a target profile set with authors we want to de-anonymize
    """
    
    pred_result, classes = deAnonymizer.attack(target)

    groundTruth = target.target

    predicted = []
    odds = []
    
    for predictedProbVector in pred_result:
        #find max and second place
        
        high = 0
        second = 0
        for index in range(len(predictedProbVector)):
            prob = predictedProbVector[index]
            if prob > high:
                second = high
                high = prob
                pred = classes[index]
            elif prob > second:
                second = prob

        confidence = high - second
        
        predicted.append(pred)
        odds.append(confidence)

    report = dict()
    print("producing report")
    samples = range(len(predicted))
    for authorName in tqdm(target.authors):
        
        positives = [i for i in samples if predicted[i] == authorName]
        negatives = [i for i in samples if predicted[i] != authorName]

        occurances = [i for i in samples if groundTruth[i] == authorName]

        truePositives = [i for i in samples if predicted[i] == authorName and predicted[i] == groundTruth[i]]
        trueNegatives = [i for i in samples if predicted[i] != authorName and groundTruth[i] != authorName]
        falsePositives = [i for i in samples if predicted[i] == authorName and groundTruth[i] != authorName]
        falseNegatives = [i for i in samples if predicted[i] != authorName and groundTruth[i] == authorName]

        pr = len(positives) / len(predicted) #positive rate for the author
        
        oc = len(occurances) / len(predicted)

        tpr = len(truePositives) / (len(positives)+1)
        tnr = len(trueNegatives) / (len(negatives)+1)
        fpr = 1-tpr
        fnr = 1-tnr

        report[authorName] = {"pr":pr,"oc": oc,"tpr":tpr, "tnr":tnr, "fpr":fpr, "fnr":fnr}

    averages = dict()
    import statistics
    
    for stat in ["pr", "oc", "tpr", "tnr", "fpr", "fnr"]:
        averages[stat] = statistics.mean([report[authName][stat] for authName in report])
    
    report["avg"] = averages

    fpr, tpr, thresholds = confidenceCurves(predicted, groundTruth, odds)
    curves = [fpr, tpr, thresholds]

    auc = metrics.auc(fpr, tpr)
    report["auc"] = auc

    return (report, curves)

def confidenceCurves(pred, true, confidence):
    def correct(i):
        if pred[i] == true[i]:
            return "correct"
        else:
            return "incorrect"

    correctNess = [correct(i) for i in range(len(pred))]
    return metrics.roc_curve(correctNess, confidence, pos_label="correct")

from collections import Counter
def cOcc(iter):
    return Counter(iter)