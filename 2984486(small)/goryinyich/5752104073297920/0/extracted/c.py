import random
import random as rnd
from numpy import *
from matplotlib import pyplot as pl
import os
import sys

def gen_bad(l=1000):
    v = arange(l)
    for i in range(l):
        j = rnd.randrange(l)
        v[i], v[j] = v[j], v[i]
    return v
	
def gen_good():
    v = arange(1000)
    for i in range(1000):
        j = rnd.randrange(i,1000)
        v[i], v[j] = v[j], v[i]
    return v

def stat(v):
    cnt = 0.0
    for i in range(1000):
        cnt += v[i] * i
    return cnt

def stat2(v):
    x = zeros((1000,3))
    for i in range(1000):
        x[i, 0] = 1
        x[i, 1] = i
        x[i, 2] = v[i-1] if i > 0 else v[-1]
    y = v.reshape((1000,1))
    beta = dot(linalg.inv(dot(x.T, x)), dot(x.T, y))
    return beta[2]


##a = []
##aa = []
##for i in range(100):
##    p = gen_good()
##    a.append(stat(p))
##    aa.append(stat2(p))
##a = array(a)
##aa = array(aa)
##print a.mean(), a.std()
##
##b = []
##bb = []
##for j in range(100):
##    p = gen_bad()
##    b.append(stat(p))
##    bb.append(stat2(p))
##b = array(b)
##bb = array(bb)
##pl.show()
##print b.mean(), b.std()
##
##print (a.mean() + b.mean()) / 2.0

tc = int(sys.stdin.readline())
ans = []
for ic in range(tc):
    n = int(sys.stdin.readline())
    p = [int(t) for t in sys.stdin.readline().strip().split()]
    ans.append(stat(p))

b = sorted(ans)
b = (b[59] + b[60]) / 2.0

for ic in range(len(ans)):
    print 'Case #%d: %s' % (ic+1, 'GOOD' if ans[ic] <= b else 'BAD')

