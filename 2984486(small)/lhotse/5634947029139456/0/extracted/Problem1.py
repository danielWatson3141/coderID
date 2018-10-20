# -*- coding: utf-8 -*-
"""
Created on Tue Apr 15 15:51:19 2014

@author: aaditya prakash
"""

import math
import time
from copy import deepcopy
#import numpy as np
#import scipy as sc
from itertools import permutations
from itertools import combinations

fName = "A-small-attempt1.in"
#fName  = "bbb.txt"
fOut = fName + "OUT"

def fun__(strIn):
    strOutput = []
    strList = strIn.split("\n")
    numT = int(strList[0])

    for i in range(numT):
        J = strList[3*i+1]
        a = strList[3*i+2]
        b = strList[3*i+3]

        #print(a)
        #print(b)
        a = a.split(' ')
        b = b.split(' ')

        for k in range(len(a)):
            a[k] = list(a[k])

        for k in range(len(b)):
            b[k] = list(b[k])


        res = Strategy(a,b)
        #print(res)
        strOutput.append("Case #" + str(i+1) + ": " + str(res))

    fileOut = open(fOut, "w")
    for item in strOutput:
        fileOut.write(item + '\n')
    fileOut.close()



def Strategy(a, b):

    #print(sorted(a))
    #print(sorted(b))
    #print("STrategy")
    switches = len(b[0])
    N = len(a)
    ori_a = deepcopy(a)
    aa = deepcopy(ori_a)
    flipCount = 0


    #print(switches, 'switches')
    for flip in range(-1,switches):
        aa = deepcopy(ori_a)
        #print(aa)
        #print(ori_a)
        #print("restart")
        success = 0
        #print('flip', flip)
        if(flip != -1):
            flipCount = 1
            #print(flip)
            # flip the ith switch
            for j in range(len(aa)):
                #print("before" , aa[j])
                if(aa[j][flip] == '0'):
                    aa[j][flip] = '1'

                else:
                    aa[j][flip] = '0'
        for i in aa:
            if(i in b):
                success += 1
        if(success == N):
            return flipCount

    for r in range(2,switches):
        for flip in combinations([j for j in range(switches)], r):
            aa = deepcopy(ori_a)
            success = 0

            #flip the switches

            for f in flip:
                for j in range(len(aa)):

                    if(aa[j][f] == '0'):
                        aa[j][f] = '1'

                    else:
                        aa[j][f] ='0'
            for i in aa:
                if(i in b):
                    success += 1
            if(success == N):
                return len(flip)

    return 'NOT POSSIBLE'



def Sample():

    a = '101 111'
    b = '010 001'
    a = a.split(' ')
    b = b.split(' ')

    for i in range(len(a)):
        a[i] = list(a[i])

    for i in range(len(b)):
        b[i] = list(b[i])



    #print(a)
    #print(b)


    #print("restult")
    print(Strategy(a,b))


fInput = open(fName, "r")
strIn = fInput.read()
timeStart = time.clock()

fun__(strIn)

#Sample()

print('Time (sec):' + str(time.clock() - timeStart))




