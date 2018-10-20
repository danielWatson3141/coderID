# -*- coding: utf-8 -*-
"""
Created on Tue Apr 15 15:51:19 2014

@author: aaditya prakash
"""

import math
import time
import numpy as np
import scipy as sc
from itertools import permutations
from itertools import combinations
from collections import Counter


fName = "B-small-attempt0111.in"
#fName = "aaaa.txt"
fOut = fName + "OUT"

def fun__(strIn):
    strOutput = []
    strList = strIn.split("\n")
    numT = int(strList[0])

    j = 1
    i = 0
    while True:
        i += 1
        if(strList[j]==''): break
        N = int(strList[j])
        j += 1
        L = []
        for n in range(N-1):
            a = list(map(int, list(strList[j].split(' '))))
            #print(a)
            L.append(a)

            j+=1


        #print(N, L)
        res = Strategy(N, L)
        strOutput.append("Case #" + str(i) + ": " + str(res))

        if(j == len(strList)):
            break

    fileOut = open(fOut, "w")
    for item in strOutput:
        fileOut.write(item + '\n')
    fileOut.close()



def Strategy(N, L):

    #print(N, L)

    cc = Counter()

    for i in range(N-1):
        L0 = L[i][0]
        L1 = L[i][1]
        cc[L0] += 1
        cc[L1] += 1
        #print(L[i])

    countX = [0]*100

    print(cc)
    #print("h")
    for c in cc:
        y = min(2, cc[c]-1)
        #print("cc", c, " **" ,cc[c]-1, y)
        countX[y] += 1


    if(countX[1]==1):
        return 0
    else:
        return countX[1] -1



def Sample():


    N = 7
    L = [[4,5],[4,2], [1,2], [3,1], [6,4], [3,7]]

    N = 4
    L = [[1,2], [2,3], [3,4]]
    #print(Strategy(N, L))


fInput = open(fName, "r")
strIn = fInput.read()
timeStart = time.clock()

fun__(strIn)

#Sample()

print('Time (sec):' + str(time.clock() - timeStart))




