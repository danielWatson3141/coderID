#!/usr/bin/env python

import sys

def solve(n, l, outlets, devices):
    outlets = [int(x, 2) for x in outlets]
    devices = sorted(int(x, 2) for x in devices)
    best = None
    for i in xrange(2**l):
        tmp = [x ^ i for x in outlets]
        num_switches = len([x for x in bin(i) if x == '1'])
        if sorted(tmp) == devices and (best is None or num_switches < best):
            best = num_switches
    return "NOT POSSIBLE" if best is None else best

if __name__ == '__main__':
    fin = open(sys.argv[1], 'rU') if sys.argv[1:] else sys.stdin
    fout = open(sys.argv[2], 'w') if sys.argv[2:] else sys.stdout
    with fin, fout:
        T = int(fin.readline())
        for case in xrange(1, T+1):
            n, l = map(int, fin.readline().split())
            outlets = fin.readline().split()
            devices = fin.readline().split()
            soln = solve(n, l, outlets, devices)
            print >> fout, "Case #{0}: {1}".format(case, soln)

