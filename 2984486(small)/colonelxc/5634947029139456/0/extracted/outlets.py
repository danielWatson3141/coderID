#! /usr/bin/env python

import sys


def solve(N, L, outlets, devices):
    
    ios = [int(i,2) for i in outlets]
    ids = sorted([int(i,2) for i in devices])

    best = 100

    for i in xrange(int(2**L)):
        if sorted(map(lambda x: x^i, ios)) == ids:
            if bin(i).count('1') < best:
                best = bin(i).count('1')

    if best == 100:
        return "NOT POSSIBLE"
    else:
        return str(best)




def main():

    testcases = int(sys.stdin.readline())

    for i in xrange(testcases):
        (N, L) = map(int, sys.stdin.readline().strip().split(' '))
        outlets = sys.stdin.readline().strip().split(' ')
        devices = sys.stdin.readline().strip().split(' ')
        print "Case #%d: %s" % (i+1, solve(N, L, outlets, devices))





main()
