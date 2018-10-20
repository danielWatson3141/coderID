#!/usr/bin/python

import sys

def readints(f):
    return [int(s) for s in f.readline().split()]

def readint(f):
    return int(f.readline())

def flip(flow, i):
    r = []
    for s in flow:
        c = [s[j] for j in xrange(len(s))]
        if c[i] == '0':
            c[i] = '1'
        else:
            c[i] = '0'
        r += ["".join(c)]
    return r

def compat(a, b):
    c = 0
    for i in xrange(len(a)):
        if a[i] == b[i]:
            c += 1
    return c

def chooseSwitch(flow, dev, L):
    comp = compat(flow, dev)
    chosen = -1
    for i in xrange(L):
        flipped = sorted(flip(flow, i))

        c = compat(flipped, dev)

        if c > comp:
            comp = c
            chosen = i

    return chosen

def solvex(f):
    N, L = readints(f)
    flow = f.readline().split()
    dev = f.readline().split()

    flow = sorted(flow)
    dev.sort()

    comp = compat(flow, dev)

    if comp == N:
        return 0

    somethingChosen = True
    cnt = 0
    while somethingChosen:
        i = chooseSwitch(flow, dev, L)
        flip(flow, i)
        if sorted(flow) == dev:
            return cnt
        somethingChosen = i >= 0

    return "NOT POSSIBLE"

def solveWith(L, i, flow, dev):
    if flow == dev:
        return 0
    inc = 0
    if i >= 0:
        flow = sorted(flip(flow, i))
        inc = 1
    if flow == dev:
        return 1
    fl = -1
    for j in xrange(i+1, L):
        f = solveWith(L, j, flow, dev)
        if f + inc > 0 and (fl < 0 or f+inc < fl):
            fl = f + inc
    return fl

def solve(f):
    N, L = readints(f)
    flow = f.readline().split()
    dev = f.readline().split()

    flow.sort()
    dev.sort()

    if flow == dev:
        return 0

    c = solveWith(L, -1, flow, dev)
    
    if c < 0:
        return "NOT POSSIBLE"
    return c


if __name__ == "__main__":
    f = open(sys.argv[1], "r")
    numCases = readint(f)
    for i in xrange(numCases):
        print "Case #%d: %s" % (i + 1, solve(f))
