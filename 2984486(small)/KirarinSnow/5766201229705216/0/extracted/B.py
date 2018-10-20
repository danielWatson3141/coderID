#!/usr/bin/env python
#
# Problem: Full Binary Tree
# Language: Python
# Author: KirarinSnow
# Usage: python thisfile.py <input.in >output.out


from itertools import *

def best(t):
    if t not in bt:
        s = len(b[t])
        if s == 0:
            bt[t] = 0
        elif s == 1:
            bt[t] = total(b[t][0])
        else:
            m = n
            for i, j in combinations(b[t], 2):
                m = min(m, sum(map(lambda x: (total, best)[x == i or x == j](x), b[t])))
            bt[t] = m
    return bt[t]

def total(t):
    if t not in dt:
        dt[t] = 1 + sum(map(lambda x: total(x), b[t]))
    return dt[t]
    

for case in range(int(raw_input())):
    n = int(raw_input())
    t = [map(int, raw_input().split()) for i in range(n-1)]
    
    c = n
    for r in range(1, n+1):
        b = {}
        q = [r]
        v = []
        while q:
            z = q.pop()
            if z in b:
                continue
            b[z] = []
            for x, y in t:
                if z == x and y not in v:
                    b[z].append(y)
                    q.append(y)
                elif z == y and x not in v:
                    b[z].append(x)
                    q.append(x)
            v.append(z)
        
        dt = {}
        bt = {}
        c = min(c, best(r))
                
    ans = c
    print "Case #%d: %s" % (case+1, ans)
