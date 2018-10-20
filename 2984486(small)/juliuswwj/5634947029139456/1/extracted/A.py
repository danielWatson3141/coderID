#!/usr/bin/python

import os, sys

def run():
    global N, L, outlets, devices
    dmap = {}
    dt = {}
    for i in xrange(N):
        dt[i] = set( xrange(N) )
    dmap[''] = dt

    while len(dmap)>0:
        nmap = {}
        for p,dt in dmap.items():
            l = len(p)
            dt0 = {}
            dt1 = {}
            for i,st in dt.items():
                dt0[i] = set()
                dt1[i] = set()
                for j in st:
                    if outlets[j][l] == devices[i][l]:
                        dt0[i].add(j)
                    else:
                        dt1[i].add(j)
                if len(dt0[i]) == 0: del dt0[i]
                if len(dt1[i]) == 0: del dt1[i]
            if len(dt0) == N: nmap[p+'0'] = dt0
            if len(dt1) == N: nmap[p+'1'] = dt1
        dmap = nmap
        #print dmap
        if l>=L-1: break
    
    if len(dmap)==0: return 'NOT POSSIBLE'
    mc = L
    for p in dmap.keys():
        c = 0
        for i in xrange(L): 
            if p[i] == '1': c += 1
        if mc > c: mc = c
    return mc

T = int(sys.stdin.readline())
for tt in xrange(T):
    N,L = map(int, sys.stdin.readline().split())
    outlets = sys.stdin.readline().split()
    devices = sys.stdin.readline().split()
    print 'Case #%d: %s' % (tt+1, run())
    