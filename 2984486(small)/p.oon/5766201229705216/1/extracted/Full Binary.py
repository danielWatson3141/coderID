import sys
import itertools
sys.stdin = open('../input.txt')
sys.stdout = open('out.txt','w')

sys.setrecursionlimit(9999999)

inf = 999999
def do(x,paren):
    ll = []
    for i in g[x]:
        if(i == paren): continue
        ll.append(do(i,x))
    if(len(ll) == 1):
        return 1,ll[0][1]+1
    elif(len(ll) >= 2):
        ll.sort(reverse=True)
        size = sum(i[1] for i in ll) + 1
        remaining = ll[0][0]+ll[1][0] +1
        return remaining,size
    return 1,1

for t in range(int(input())):
    n = int(input())
    g = [[] for i in range(n+1)]
    for i in range(n-1):
        a,b = map(int,input().split(' '))
        g[a].append(b)
        g[b].append(a)

    mincut = inf
    for i in range(1,n+1):
        mincut = min(mincut,n-do(i,-1)[0])
    print('Case #%d: %d' %(t+1,mincut))