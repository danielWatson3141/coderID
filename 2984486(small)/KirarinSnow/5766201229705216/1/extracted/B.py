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
            st = sum(map(total, b[t]))
            bs = map(lambda x: best(x)-total(x), b[t])
            bs.sort()
            bt[t] = st + bs[0] + bs[1]
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
        a = {}
        for i in range(1, n+1):
            a[i] = []
        for x, y in t:
            a[x].append(y)
            a[y].append(x)
        
        b = {}
        q = [r]
        v = []
        while q:
            z = q.pop()
            if z in b:
                continue
            b[z] = []

            for y in a[z]:
                if y not in v:
                    b[z].append(y)
                    q.append(y)
            v.append(z)

        dt = {}
        bt = {}

        c = min(c, best(r))
                
    ans = c
    print "Case #%d: %s" % (case+1, ans)
