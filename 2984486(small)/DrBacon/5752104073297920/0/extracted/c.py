#!/usr/bin/env python

import fileinput
import sys
import math
import random

def read_cases():
    fh = fileinput.input()
    T = int(fh.readline().strip())
    cases = []
    for t in range(T):
        case = {}
        case["N"] = int(fh.readline().strip())
        case["L"] = map(int, fh.readline().strip().split())
        cases += [case]
    if fh.readline().strip() !="":
        raise Exception
    return cases


def bad_swap(l, i):
    p = random.randint(0,len(l)-1)
    n = l[:]
    n[i], n[p] = n[p], n[i]
    return n

def bad_permute(l):
    for i in range(len(l)):
        l = bad_swap(l, i)
    return l

def process_case(case):
    #print case
    '''
    l = [0,1,2,3,4,5,6,7]
    print
    solns = []
    for i in range(1000000):
        solns += ["".join(map(str, bad_permute(l[:])))]
    d = {}
    for s in solns:
        if s not in d:
            d[s] = 0
        d[s]+=1
    max_ct = max([d[k] for k in d.keys()])
    for s in sorted(d.keys()):
        if d[s]>max_ct-5:
            print s, d[s]
            '''
    #print case
    L = case["L"]
    N = case["N"]
    ct = 0
    for i in range(N-1):
        if L[i]==i+1:
            ct +=1
    if ct > 100:
        return "BAD"
    else:
        return "GOOD"


if __name__ == "__main__":
    cases = read_cases()
    #print cases

    for i, case in enumerate(cases[:]):
        result = process_case(case)
        print "Case #%s:" % (i+1, ) , result
        #sys.stderr.write("Progress: %d/%d (%d%%) \r" % (i+1, len(cases), int(100.*(i+1)/len(cases) ) ) )
        #sys.stderr.flush()
