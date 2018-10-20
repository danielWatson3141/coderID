#!/usr/bin/env python

import fileinput
import sys
import math

def read_cases():
    fh = fileinput.input()
    T = int(fh.readline().strip())
    cases = []
    for t in range(T):
        case = {}
        case["N"]  = int(fh.readline().strip())
        case["es"] = []
        for e in range(case["N"] -1):
            case["es"] += [map(int, fh.readline().strip().split(" "))]
        cases += [case]
    if fh.readline().strip() !="":
        raise Exception
    return cases

def count_max_nodes(n, d_n2es):
    cs = len(d_n2es[n])
    if cs>=2:
        best = 0
        for i in range(cs-1):
            for j in range(i+1, cs):
                l = d_n2es.copy()
                l[l[n][i]] = [e for e in l[l[n][i]] if e!=n]
                r = d_n2es.copy()
                r[r[n][j]] = [e for e in r[r[n][j]] if e!=n]
                l_resp = count_max_nodes(d_n2es[n][i], l)
                r_resp = count_max_nodes(d_n2es[n][j], r)
                result = 1+l_resp+r_resp
                if result > best:
                    best = result
        return best
    elif cs == 1:
        return 1
    return 1

def process_case(case):
    N = case["N"]
    es = case["es"]
    d_n2es = {}
    for n in range(1,1+N):
        d_n2es[n]=[]
    for e in es:
        d_n2es[e[0]]+= [e[1]] 
        d_n2es[e[1]]+= [e[0]]
    #d_n2links = dict([(n, len(d_n2es[n])) for n in d_n2es.keys()])
    #one_links = [n for n in d_n2es.keys() if d_n2links[n]==1]
    #only_children = [n for n in one_links if d_n2links[d_n2es[n][0]]==1]
    #print one_links, only_children
    best = 0
    for r in range(1,1+N):
        max_nodes = count_max_nodes(r, d_n2es)
        #print r, max_nodes
        if max_nodes > best:
            best = max_nodes
    return N-best


if __name__ == "__main__":
    cases = read_cases()
    #print cases

    for i, case in enumerate(cases[:]):
        result = process_case(case)
        print "Case #%s:" % (i+1, ) , result
        sys.stderr.write("Progress: %d/%d (%d%%) \r" % (i+1, len(cases), int(100.*(i+1)/len(cases) ) ) )
        sys.stderr.flush()
