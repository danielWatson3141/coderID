#!/usr/bin/python

import os, sys, copy, itertools

def calc():
    global N, g, cc
    cc = [0, 0, 0, 0]
    for g,e in G.items():
        l = len(e)
        if l>3: l=0
        cc[l]+=1
        
def run():
    global N, NG, G
    N = len(G)
    gm = G.keys()
    for rr in range(N):
        for gg in itertools.combinations(gm, rr):
            G = copy.deepcopy(NG)
            #print gg
            for g in gg:
                if g not in G: continue
                s = G[g]
                del G[g]
                
                for p in s:
                    G[p].remove(g)
                    if len(G[p]) == 0: del G[p]
            calc()
            if cc[0] == 0 and cc[2] == 1: return N-len(G)
            if len(G) == 0: return N
            
    return 0

T = int(sys.stdin.readline())
for tt in xrange(T):
    N = int(sys.stdin.readline())
    G = {}
    E = []
    for i in range(N-1):
        x,y = map(int, sys.stdin.readline().split())
        #E.add( (x, y) )
        if x not in G: G[x] = set()
        G[x].add(y)
        if y not in G: G[y] = set()
        G[y].add(x)
    
    
    
    NG = G
        
    print 'Case #%d: %d' % (tt+1, run())
    