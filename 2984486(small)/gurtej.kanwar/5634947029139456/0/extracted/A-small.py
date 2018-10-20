#!/usr/bin/python
import sys
import copy
import math

def testFlip(outlets, devices, seq):
    for i in xrange(len(seq)):
        if seq[i] == 1:
            flipIndex(outlets, devices, i)
    #print seq, outlets, devices
    return (len(set(map(str, outlets)) - set(map(str, devices))) == 0)

def flipIndex(outlets, devices, index):
    for out in outlets:
        out[index] = 1 - out[index]

def testFlipSeq(length):
    if length == 0:
        return [[]]
    flippedRem = testFlipSeq(length-1);
    out = []
    for r in flippedRem:
        out.append([1] + r)
        out.append([0] + r)
    return out

T = int(sys.stdin.readline())
for i in xrange(T):
    print "Case #%d:" % (i+1),
    N, L = map(int, sys.stdin.readline().strip().split(" "))
    outlets = map(list, sys.stdin.readline().strip().split(" "))
    devices = map(list, sys.stdin.readline().strip().split(" "))
    for j in xrange(N):
        outlets[j] = map(int, list(outlets[j]))
        devices[j] = map(int, list(devices[j]))
    seqs = testFlipSeq(L)
    best = float("inf")
    for seq in seqs:
        cost = sum(seq)
        if testFlip(copy.deepcopy(outlets), copy.deepcopy(devices), seq):
            if cost < best:
                best = cost
    if math.isinf(best):
        print "NOT POSSIBLE"
    else:
        print best
