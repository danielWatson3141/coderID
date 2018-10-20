#! /usr/bin/python
from numpy import *
from itertools import *
#f=open('test1')
f=open('a-small-attempt1.in')
T=int(f.readline())
for tt in range(1,T+1):
    [N,L]=[int(i) for i in f.readline().split()]
    sw=[int(i,2) for i in f.readline().split()]
    dev=[int(i,2) for i in f.readline().split()]
    dev=array(sorted(dev))
    sw=array(sw)
    flag=False
    seq =  [''.join(i) for i in product("01", repeat=L)]
    seq = [int(x,2) for x in seq ]
    tmp=[]
    for k in seq:
        t=k
        tmp1=0
        while t>0:
            if t%2==1:
                tmp1 =tmp1+1
            t=t/2
        tmp = tmp + [(tmp1,k)]
    seq = sorted(tmp)
    #print 'seq',seq
    num=0
    for (n,k) in seq:
        num=n
        sw1=sorted(list(k^sw))
        #print sw1, list(dev)
        if sw1==list(dev):
            flag=True
            break

    if flag==True:
        print 'Case','#'+str(tt)+':',num
    else:
        print 'Case','#'+str(tt)+':','NOT POSSIBLE'


