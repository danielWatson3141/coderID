#!/usr/bin/env python
import numpy as np
import sys
import pdb
import math

allowed = set()
sys.setrecursionlimit(1500)


def solve(outflow, inflow,limit):
    allowed.clear()
    solvesmall(outflow, inflow, 1, "",limit)
    if len(allowed)==0:
        return "NOT POSSIBLE"
    else:
        min = 100000
        for i in allowed:
            total = getsum(i)
            if total < min:
                min = total

        return str(min)
        
def getsum(inputlist):
    process = [int(i) for i in inputlist]
    return np.sum(process)

def solvesmall(outflow, inflow,n, current,limit):
    if n>limit:
        if checkequal(list(outflow), list(inflow)):
#            print outflow
#            print inflow
            allowed.add(current)
        return ""

    if checkequal([i[0:n] for i in outflow],[i[0:n] for i in inflow]):
        solvesmall(outflow, inflow, n+1, current+"0", limit)


    if checkequal([i[0:n] for i in flip(outflow,n-1)],[i[0:n] for i in inflow]):
        solvesmall(flip(outflow,n-1), inflow, n+1, current+"1", limit)


def checkequal(outflow, inflow):
    for i in outflow:
        if i in inflow:
            inflow.remove(i)

    if len(inflow)==0:
        return True
    else:
        return False
    
        
def flip(outflow, n):
    outflow = [list(item) for item in outflow]
    for out in outflow:
        if out[n] == "0":
            out[n] = "1"
        else:
            out[n] = "0"
    return outflow

numcase = int(sys.stdin.readline())
for casenum in range(1,numcase+1):
    line = sys.stdin.readline().split()
    N = int(line[0])
    L = int(line[1])
    outflow = [list(i) for i in sys.stdin.readline().split()]
    inflow = [list(i) for i in sys.stdin.readline().split()]

    print 'Case #' + repr(casenum)+': '+ str(solve(outflow, inflow,L))
    
