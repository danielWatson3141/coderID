#!/usr/bin/python

import sys

cases = int(sys.stdin.readline())

for casenum in range(1, cases+1):
    devices, inputs = map(int, sys.stdin.readline().split())
    ins = map(lambda x: int(x, 2), sys.stdin.readline().split())
    outs = map(lambda x: int(x, 2), sys.stdin.readline().split())
    minn = 10**8
    for a in outs:
        tmpout = sorted(outs[:])
        tmpout.remove(a)
        switch = a ^ ins[0]
        tmpins = sorted([i ^ switch for i in ins[1:]])
        if tmpins == tmpout:
            minn = min(bin(switch).count('1'), minn)
    if minn < 10**8:
        print 'Case #{}: {}'.format(casenum, minn)
    else:
        print 'Case #{}: NOT POSSIBLE'.format(casenum)
    
