#!/usr/bin/python

from itertools import *

def specialPrint(xs):
    print '[' + ', '.join(''.join(str(int(y)) for y in x) for x in xs) + ']'

def solve(N, L):
    outlets = [[bool(int(y)) for y in x] for x in raw_input().split()]
    devices = [[bool(int(y)) for y in x] for x in raw_input().split()]

    outlets.sort()
    devices.sort()

    ll = range(L)
    for l in range(L + 1):
        for xs in combinations(ll, l):
            foo = [x[:] for x in outlets]
            for x in xs:
                for bar in foo:
                    bar[x] = not bar[x]
            foo.sort()
            if foo == devices:
                return l
    return 'NOT POSSIBLE'

T = int(raw_input())
for i in range(T):
    print "Case #%i: %s" % (i+1, solve(*(int(s) for s in raw_input().split(' '))))
