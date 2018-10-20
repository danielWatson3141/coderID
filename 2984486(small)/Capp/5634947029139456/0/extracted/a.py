#!/usr/bin/env python

from sys import stdin
from numpy import array

T = int(stdin.readline())

for t in range(T):
    N, L = array(stdin.readline().split()).astype(int)
    D1 = [int(i, 2) for i in stdin.readline().split()]
    D2 = [int(i, 2) for i in stdin.readline().split()]
    D2.sort()

    ret = []

    for i in range(2**L):
        tmpD1 = [d1 ^ i for d1 in D1]
        tmpD1.sort()
        if tmpD1 == D2: ret.append(i)
        pass
    

    print "Case #%d:" % (t+1),
    if len(ret) == 0:
        print "NOT POSSIBLE"
    else:
        ret2 = array(ret) * 0
        a = array(ret)
        for l in range(L):
            ret2 += a % 2
            a /= 2
            pass
        print min(ret2)
