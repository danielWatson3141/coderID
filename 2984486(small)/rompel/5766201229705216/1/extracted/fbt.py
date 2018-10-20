#!/usr/bin/python

import sys, re, string, math, fractions, itertools
from fractions import Fraction

ssr = sys.stdin.readline
ssw = sys.stdout.write
def rdline(): return ssr().strip()
def rdstrs(): return ssr.split()
def rdints(): return map(int, ssr().split())
def rd1int(): return int(rdline())



def maxbt(a, r, ex):
    l1 = [ i for i in a[r] if i!=ex ]
    if len(l1) < 2:
        return 1
    l = [ maxbt(a, i, r) for i in l1 ]
    if len(l) < 2:
        return 1
    l.sort(reverse=True)
    return 1 + l[0] + l[1]


def do_one_case(cnum):
    N = rd1int()
    #e = set()
    a = {}
    for i in range(N-1):
        (x, y) = rdints()
        #e.add((x,y))
        #e.add((y,x))
        a.setdefault(x, []).append(y)
        a.setdefault(y, []).append(x)
    assert len(a)==N
    m = 0
    for i in range(1,N+1):
        mm = maxbt(a, i, None)
        m = max(m, mm)
    print "Case #%d: %d" % (cnum, N-m)


def main():
    N = rd1int()
    for i in range(N):
        do_one_case(i+1)


if __name__ == "__main__":
    main()
