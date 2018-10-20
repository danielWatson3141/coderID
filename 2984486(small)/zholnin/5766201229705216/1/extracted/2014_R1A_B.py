import sys # standard Python library
import itertools # standard Python library
#from PerfectAllocation import PerfectAllocation # http://pastebin.com/5sv1quf0
from operator import itemgetter # standard Python library
import bisect # standard Python library
import math # standard Python library
import copy # standard Python library
from fractions import gcd # standard Python library
from utilities import *  # this is helper file which can be found at http://pastebin.com/RNbC6TtE. It does not contain problem-specific algorithms.
#from blist import blist # add-on library which can be downloaded from https://pypi.python.org/pypi/blist/


sys.setrecursionlimit(1000) #1000 is default
Prep = []


def preprocess():
    return None
    
def readinput(Input):
    N = Input.readint()
    
    Edges = {}
    
    for i in range(N-1):
        x, y = Input.readints()
        if x not in Edges:
            Edges[x] = {}
        if y not in Edges:
            Edges[y] = {}
            
        Edges[x][y] = None
        Edges[y][x] = None
    
    return Edges

def solve(Problem, Prep):
    
    @memoize
    def dive(s, i):
        o = Edges[i].keys()
        if s <> 0:
            o.remove(s)
        
        if len(o) == 0:
            return 0
        
        if len(o) == 1:
            return Edges[i][o[0]]
        
        if len(o) == 2:
            return dive(i, o[0]) + dive(i, o[1])
        
        cost = []
        for e in o:
            cost.append((Edges[i][e], e))
        
        cost.sort(reverse = True)
        
        total = dive(i, cost[0][1]) + dive(i, cost[1][1]) + sum([y for y, _ in cost[2:]])
        
        return total

    
    Edges = Problem
    
    C = True
    
    while C:
        C = False
        for e in Edges:
            for t in Edges[e]:
                if Edges[e][t] <> None:
                    continue
                if len(Edges[t]) == 1:
                    Edges[e][t] = 1
                    C = True
                    continue
                count = 0
                s = Edges[t].keys()
                for s1 in s:
                    if s1 == e:
                        continue
                    if count == None or Edges[t][s1] == None:
                        count = None
                    else:
                        count += Edges[t][s1]
                if count <> None:
                    Edges[e][t] = count + 1
                    C = True
    
    best = len(Edges)
    
    for i in Edges:
        if i == 4:
            pass
        test = dive(0, i)
        best = min(test, best)                 
        
    return best


if __name__ == "__main__":
    doit(preprocess, readinput, solve, MultiCore = True, Verify = False, Input = LARGE, Filename = None, Problem = "B", Attempt = 0)
