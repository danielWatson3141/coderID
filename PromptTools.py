from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import cross_val_score,ShuffleSplit
import numpy as np
import os
import pickle

def loadGPSFromFile(fileName):
    file = open(os.getcwd() + "/savedSets/" + fileName, 'rb')
    return pickle.Unpickler(file).load()

def authorsInCommon(gps1, gps2):
    return [author for author in gps1.authors.keys() if
            author in gps2.authors]

def bestNFeatures(imp, names, n):
    match = dict(zip(names, imp))
    import operator
    sortedMatch = sorted(match.items(), key=operator.itemgetter(1),
                         reverse=True)
    return sortedMatch[0:n]

# TODO: seems to have been directly implemented in do_classifyFunction in coderID?
def sanityCheck(gps, features, targets, model, numAuthors):

    from sklearn import metrics,utils

    n_samples = len(targets)

    features, targets = utils.shuffle(features, targets)
    expected = targets[n_samples //2:]
    # Test here
    model.fit(features[:n_samples//2], targets[:n_samples//2])
    predictions = model.predict(features[n_samples//2:])

    cm = metrics.confusion_matrix(expected, predictions)
    sortedAuthors = sorted(gps.authors.keys(), reverse=False)
    authCount = numAuthors
    if numAuthors == -1:
        authCount = len(sortedAuthors)
    #assert len(sortedAuthors) == cm.shape[0]
    """
    for i in range(0, authCount):
        print(sortedAuthors[i]+": P="+str(cm[i,i]/sum(cm[i]))+" R="+str(cm[i,i]/sum(cm[:,i])))
    """
    from sklearn.metrics import classification_report
    print(classification_report(expected, predictions))

    #import numpy
    #numpy.set_printoptions(threshold='nan')

    print("Confusion matrix:\n%s" % cm)


def decisionMaximizationProcedure(success: np.array, confidence: np.array,
                                  maxFP=.1, precision=.01):
    """return the highest d such that P(success| confidence > d) >= 1-maxFP"""

    if len(success) != len(confidence):
        raise Exception(
            "success and confidence vectors must be equal in length")

    corclass = confidence[success]  # Confidence in correct instances
    misclass = confidence[not success]  # Confidence in incorrect instances

    totalCount = len(success)

    # If misclassification rate is less than maximum false positive rate then
    #  the optimal cut-off is is the minimum of the correct instances
    if len(misclass) < maxFP * totalCount:
        return min(corclass)

    upper = 1
    lower = 0
    d = .5
    fp = 1

    maxIter = 10
    iterCount = 0  # Don't iterate more than ten times. Necessary to prevent
    # infinite loop on small datasets

    while (
            fp > maxFP + precision or fp < maxFP - precision) and iterCount < maxIter:

        iterCount += 1

        d = (upper + lower) / 2

        fp = len(np.where(
            misclass > d)) / totalCount  # fp rate with d at its current value

        print("d: " + d + " " + "fp: " + fp)

        if fp < maxFP:
            upper = d
        else:
            lower = d

    if iterCount == 10:
        print("terminated after 10 iterations. This is problematic.")
    return d


def determineConfidence(features, targets, n_est=300):
    """Cross validate over the given data and return the scores"""
    print("Cross Validating...")
    clf = RandomForestClassifier(n_estimators=n_est, oob_score=True,
                                 max_features="sqrt")
    numSamples = features.shape[0]
    train_size = min(1000, numSamples * .5)
    test_size = min(200, numSamples * .2)
    splits = 3

    cv = ShuffleSplit(n_splits=splits, train_size=train_size,
                      test_size=test_size)

    success = np.empty((test_size * splits))
    confidence = np.empty((test_size * splits))
    index = 0

    for train, test in cv.split(features):

        trainingSet = (features[train], targets[train])  # Select training set

        clf.fit(trainingSet[0], trainingSet[1])  # train model

        testSet = (features[test], targets[test])  # Select test set

        probabilities = clf.predict_proba(
            testSet[0])  # predict probabilities over test set

        for sample, target in zip(probabilities, testSet[1]):
            predIndex = np.argmax(sample)
            prediction = clf.classes_[
                predIndex]  # get item with max probability

            success[
                index] = prediction == target  # record whether the result was correct
            confidence[index] = sample[
                predIndex]  # record the confidence of the result
            index += 1

    return (success, confidence)


def detectKnownAuthors(prompt, targetRepo, maxFP=.1, n_est=300):
    """Given a target repo, attempt to identify any code in said repo written by any author in the gps. Will set ROC point such that FPR <= maxFP"""


    # cross validate, generating a two lists:
    # (success: bool)
    # (confidence: num)

    if not prompt.activegps.featuresDetected:  # get features of currently
        # active repo
        prompt.activegps.getFeatures()
        prompt.do_save("")

    if prompt.activegps.featuresSelected is None:
        prompt.activegps.featureSelect()
        prompt.do_save("")

    success, confidence = determineConfidence(
        prompt.activegps.featuresSelected,
        prompt.activegps.target)  # determine confidence of resolved classifier

    decisionPoint = decisionMaximizationProcedure(success, confidence)

    try:
        targetgps = loadGPSFromFile(targetRepo)
    except FileNotFoundError:
        print("Target GPS not found. Compile it first.")
        return

    if not targetgps.featuresDetected():
        targetgps.getFeatures()

    # train a classifier on entire prompt dataset

    clf = RandomForestClassifier(n_estimators=n_est, max_features="sqrt")

    clf.fit(prompt.activegps.featuresSelected, prompt.activegps.targets)

    pred = clf.predict_proba(targetgps.counts[:,
                             prompt.activegps.selectedIndeces])  # get matrix of class probabilities

    for sample, target in zip(pred, targetgps.target):
        predIndex = np.argmax(sample)
        prediction = clf.classes_[predIndex]  # get item with max probability
        confidence = sample[predIndex]
        success = prediction == target  # record whether the result was correct

        if confidence > decisionPoint:
            print("Match: " + prediction + ", " + target + ", " + confidence)
