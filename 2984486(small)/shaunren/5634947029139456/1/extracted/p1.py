#!/usr/bin/python3 -SOO
from copy import deepcopy
for case in range(1,int(input())+1):
    n,l = map(int,input().strip().split())
    o = sorted(map(list,input().strip().split()))
    r = list(map(list,input().strip().split()))
    best = float('inf')
    for i in range(n):
        os = deepcopy(o)
        rs = [r[i][:]] + deepcopy(r[:i]) + deepcopy(r[i+1:])
        t,j = 0,0
        for x,y in zip(os[0],rs[0]):
            if x!=y:
                t += 1
                for k in range(n):
                    os[k][j] = '0' if os[k][j]=='1' else '1'
            j+=1
        for x,y in zip(sorted(os),sorted(rs)):
            if x!=y:
                break
        else:
            best = min(best,t)
    print('Case #'+str(case)+':',(best if best<float('inf') else 'NOT POSSIBLE'))
