#!/usr/bin/python

from math import *
from itertools import *

def solve(G):
    ns = map(int, raw_input().split())

    disps = []

    for i in range(len(ns)):
        disps.append(i - ns[i])

    return sqrt(sum(x ** 2 for x in disps))

T = int(raw_input())
results = []
for i in range(T):
    results.append(solve(*(int(s) for s in raw_input().split(' '))))

foo = zip(results, count())
foo.sort()
res = {}

for f in foo[:T//2]:
    res[f[1]] = 'GOOD'
for f in foo[T//2:]:
    res[f[1]] = 'BAD'

for i in range(T):
    print "Case #%i: %s" % (i+1, res[i])
