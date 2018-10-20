import sys # standard Python library
import itertools # standard Python library
#from PerfectAllocation import PerfectAllocation # http://pastebin.com/5sv1quf0
from operator import itemgetter # standard Python library
import bisect # standard Python library
import math # standard Python library
import copy # standard Python library
from fractions import gcd # standard Python library
from utilities import *  # this is helper file which can be found at http://pastebin.com/RNbC6TtE. It does not contain problem-specific algorithms.
from blist import blist # add-on library which can be downloaded from https://pypi.python.org/pypi/blist/
import random


sys.setrecursionlimit(1000) #1000 is default
Prep = []


def preprocess():
    
    """
    def gen_good():
        N = [0, 1, 2]
        for k in range(3):
            i = random.randrange(0, 3)
            N[k], N[i] = N[i], N[k]
        
        return tuple(N)    
    
    Dict = {}
    for s in range(1000000):
        r = gen_good()
        Dict[r[0]] = Dict.get(r[0], 0) + 1
    
    s = [(Dict[i], i) for i in Dict]
    s.sort(reverse = True)
    
    for n, c in s:
        #c1 = [c[i] - i for i in range(len(c))]
        print n, " - ", c, " - ", float(n) / 1000000 * 3
    
    
    exit()
    
    
    """
    
    
    return None
    
def readinput(Input):
    R = Input.readint()
    N = Input.readints()
    
    return N

def solve(Problem, Prep):
    N = Problem
    
    p = len(N) / 2
    
    prob = 0
    
    R = range(len(N))
    
    #print N
    for i in range(len(N)):
        possible = R[i+1:i+p+1]
        probable = R[1:i + 1]
        if i+p+1 < len(N):
            probable = R[i+p+1:] + probable
            
        if len(possible) == 0:
            probable = []
            
        if N[i] in possible:
            prob += 1

        #print possible, probable, N[i], prob
    
    if prob > 400:
        return "BAD"
    else:
        return "GOOD"



if __name__ == "__main__":
    doit(preprocess, readinput, solve, MultiCore = False, Verify = False, Input = SMALL, Filename = None, Problem = "C", Attempt = 0)
