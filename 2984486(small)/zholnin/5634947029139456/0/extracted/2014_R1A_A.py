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




sys.setrecursionlimit(1000) #1000 is default
Prep = []


def preprocess():

    return None
    
def readinput(Input):
    N, L = Input.readints()
    
    X = []
    A = Input.readstrings()
    for a in A:
        b = int(a, 2)
        X.append(b)
    
    A = Input.readstrings()
    for a in A:
        b = int(a, 2)
        X.append(b)
    
    return X

def solve(Problem, Prep):
    X = Problem
    
    x = reduce(lambda a, b: a ^ b, X)
    
    if x == 0:
        return 0
    
    if x > 0 and (len(X) / 2) % 2 == 0:
        return "IMPOSSIBLE"
    
    x = bin(x)
    return x.count("1")
    
    print x    

    return 0


if __name__ == "__main__":
    doit(preprocess, readinput, solve, MultiCore = False, Verify = False, Input = SMALL, Filename = None, Problem = "A", Attempt = 0)
