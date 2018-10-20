#!/usr/bin/env python
import sys
import copy
import itertools as it
import math

def solveCase(lines):
    N = int(lines[0])
    edges = {}
    for i in lines[1:]:
        (a, b) = map(int, i.split())
        sa = set([a])
        sb = set([b])
        if a not in edges:
            edges[a] = sb
        else:
            edges[a].update(sb)
        
        if b not in edges:
            edges[b] = sa
        else:
            edges[b].update(sa)
    def isBinaryTree(edg, d):
        Nn = N - len(d)
        #print "\nNn = {}".format(Nn)
        #assert (Nn) % 2 == 1
        if Nn == 1:
            return True
        if Nn == 2:
            return False
        # Check connectivity
        te = 0
        root = False
        ones = 0
        #expected = N - len(d) - 1
        for i in edg:
            #if te > (expected*2):
            #    return False
            #print "edges = {} ... d = {}".format(edg[i], d)
            if i in d: continue
            ne = len(edg[i] - d)
            te += ne
            if ne == 0 or ne > 3:
                return False
            if ne == 2:
                if root is True:
                    return False
                root = True
            ones += 1 if ne == 1 else 0
        
        if 2*ones - 1 != Nn:
            return False
        #print "\nte = {}  N = {}  len(d) = {}".format(te, N, len(d))
        assert te % 2 == 0
        return (te/2) == (N - len(d) - 1)

    if isBinaryTree(edges, set()):
        return 0
    for i in range(1, N - 1):
        ne = N - i
        for cmb in it.combinations(range(1, N + 1), i):
            if isBinaryTree(edges, set(cmb)):
                #print "cmb = {}".format(cmb)
                return i
    return N - 1

lines = [line.strip() for line in sys.stdin]
T = int(lines.pop(0))
#assert len(lines) == T*caseLine
for i in range(0, T):
    caseLine = int(lines[0])
    print "Case #{}: {}".format(i+1, solveCase(lines[0:caseLine]))
    lines = lines[caseLine:]
