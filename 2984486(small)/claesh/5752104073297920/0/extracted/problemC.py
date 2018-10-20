#!/usr/bin/python
#
# problemC.py
#

# Import
from gcj import Problem
import random
import numpy as np

# Parser
def parser(fin):
    return [fin.readInt(), fin.readInts()]

N = 1000
BADS = []
for _ in xrange(1000):
    bad = range(N)
    for k in xrange(0,N):
        p = random.randint(0,N-1)
        bad[k], bad[p] = bad[p], bad[k]
    BADS.append(bad)

GOODS = []
for _ in xrange(1000):
    good = range(N)
    for k in xrange(0,N):
        p = random.randint(k,N-1)
        good[k], good[p] = good[p], good[k]
    GOODS.append(good)

def dist(a,b):
    return sum(map(lambda x,y: abs(x-y), a, b))

# Solver
def solver(data):
    [N, x] = data
    
    x = range(1000)
    for k in xrange(0,N):
        p = random.randint(k,N-1)
        x[k], x[p] = x[p], x[k]
        
    good_dist = []
    for good in GOODS:
        good_dist.append(dist(x,good))
        
    good_dist_std = np.std(good_dist)
        
    bad_dist = []
    for bad in BADS:
        bad_dist.append(dist(x,bad))
    
    bad_dist_std = np.std(bad_dist)
    
    if good_dist_std - bad_dist_std >= 150:
        return 'GOOD'
    else:
        return 'BAD'


# Main
if __name__ == '__main__':
    Problem(parser, solver, globals()).run()
