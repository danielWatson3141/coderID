from random import randint
'''
Created on Apr 25, 2014

@author: Sean
'''
totalGood = 0.0
maxGood = 0.0
minGood = 100000000000000000000000
goodCount = 0

totalBad = 0.0
maxBad = 0.0
minBad = 1000000000000000000000000
badCount = 0

cutoff = 321164.194 + (333728.548 - 321164.194)/2

for _j in range(1000):
    a = []
    total = 0
    for k in range(1000):
        a.append(k)
    for k in range(1000):
        p = randint(k, 999)
        a[k], a[p] = a[p], a[k]
    for k in range(999):
        if (abs(a[k] - a[k+1]) <= 50):
            total += 1
    totalGood += total
    if (total > maxGood):
        maxGood = total
    if (total < minGood):
        minGood = total
    if (total >= cutoff):
        goodCount += 1

for _x in range(1000):
    a = []
    total = 0
    for k in range(1000):
        a.append(k)
    for k in range(1000):
        p = randint(0, 999)
        a[k], a[p] = a[p], a[k]
    for k in range(999):
        if (abs(a[k] - a[k+1]) <= 50):
            total += 1
    totalBad += total
    if (total > maxBad):
        maxBad = total
    if (total < minBad):
        minBad = total
    if (total < cutoff):
        badCount += 1
            
print totalGood / (1000.0), minGood, maxGood
print totalBad / (1000.0), minBad, maxBad

print "counts: ", goodCount, badCount
        
    