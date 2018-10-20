__author__ = 'peter'
import numpy as np
import sys

def f(i1, vis, conn):
    vis.add(i1)
    i2s=[]
    for i2 in conn[i1]:
        if not i2 in vis:
            i2s.append(i2)
    if len(i2s)<2:
        return 1
    ps=[]
    for i2 in i2s:
        ps.append(f(i2,vis,conn))
    ps= sorted(ps,reverse=True)
    return 1+ps[0]+ps[1]

res=[]
with open("B-large.in","r") as inF:
    t= int(inF.readline())
    for it in xrange(t):
        n= int(inF.readline())
        conn=map(lambda x:[],xrange(n))
        for i in xrange(n-1):
            i1,i2= map(int,inF.readline().split())
            conn[i1-1].append(i2-1)
            conn[i2-1].append(i1-1)
        minCut=sys.maxint
        for ic in xrange(n):
            vis=set()
            np=f(ic,vis, conn)
            minCut=min(minCut,n-np)
        res.append(minCut)

with open("B-large.out","w") as outF:
    for i in xrange(t):
        outF.write("Case #%d: %d\n"%(i+1,res[i]))