#!/usr/bin/python

import sys
from math import *

def Nf(): return tuple(map(float, sys.stdin.readline().split()))
def Ni(): return tuple(map(int, sys.stdin.readline().split()))
def Ns(): return sys.stdin.readline().split()

T = Ni()[0]
for t in range(1, T + 1):
    N, L = Ni()
    start = Ns()
    target = Ns()
    def getpar(start):
        par = []
        for i in range(L):
            ones = 0
            for s in start:
                if s[i] == '1':
                    ones += 1
            par.append(ones)
        return par

    #S = getpar(start)
    #T = getpar(target)
    S = map(lambda x : int(x, 2), start)
    T = map(lambda x : int(x, 2), target)

    def isPerm(Sm, T):
        return sorted(Sm) == sorted(T)

    answer = None
    for m in range(1<<L):
        Sm = map(lambda x : x^m, S)
        if isPerm(Sm, T):
            flips = bin(m).count("1")
            answer = flips if answer == None else min(answer, flips)

    #print "start", start, S
    #print "target", target, T

    if answer == None:
        answer = "NOT POSSIBLE"

    print "Case #%d: %s" % (t, answer)

