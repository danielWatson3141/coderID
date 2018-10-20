import sys
import itertools
import math
import collections
import functools

T = int(raw_input())
for testId in range(T):
    N = int(raw_input())
    v = map(int, raw_input().split())

    cpt = 0
    for k in xrange(N):
        if v[k] >= k:
            cpt += 1

    res = "GOOD"
    if cpt > 515:
        res = "BAD"
    print "Case #{:d}: {:s}".format(testId+1, res)
