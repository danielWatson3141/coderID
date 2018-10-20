import sys
from random import randint
from sklearn.linear_model import LogisticRegression
from sklearn.neighbors import KNeighborsClassifier
from sklearn.tree import DecisionTreeClassifier
from sklearn.ensemble import RandomForestClassifier
import numpy as np
import os.path
import pickle

basename = "C-small-attempt4"

input_filename = basename + ".in"
output_filename = basename + ".out"

input_file = open(input_filename, 'r')
output_file = open(output_filename, 'w')

test_cases = int(input_file.readline().rstrip())

def randompermgood():
    perm = [i for i in range(1000)]
    for k in range(1000):
        m = randint(k, 999)
        perm[k], perm[m] = perm[m], perm[k]
    return perm

def randompermbad():
    perm = [i for i in range(1000)]
    for k in range(1000):
        m = randint(0, 999)
        perm[k], perm[m] = perm[m], perm[k]
    return perm

# Generate 10000 of each type of permutation for training, 1000 for test
if os.path.isfile("training.pickle"):
    f = open("training.pickle", "rb")
    X, y = pickle.load(f)
    f.close()
else:
    X = []
    y = []
    print("Generating data...")
    for i in range(50000):
        p = randompermgood()
        X.append(p)
        y.append(0)

        p = randompermbad()
        X.append(p)
        y.append(1)
    X = np.array(X)
    y = np.array(y)
    with open("training.pickle", "wb") as f:
        pickle.dump((X, y), f)
    print("Done!")


print("Fitting data...")
clf = LogisticRegression(C=1)
clf.fit(X, y)
print("Done!")

for case in range(1, test_cases+1):
    N = int(input_file.readline().rstrip())
    perm = [int(i) for i in input_file.readline().rstrip().split()]
    sol = clf.predict(perm)
    if sol == 1:
        solution = "BAD"
    else:
        solution = "GOOD"
    

    # Output all goes below here. Make sure to define var 'solution' 
    output_file.write("Case #" + str(case) + ": " + str(solution))
    if case < test_cases:
        output_file.write('\n')

