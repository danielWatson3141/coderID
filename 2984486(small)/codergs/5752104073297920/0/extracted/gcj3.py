#! /usr/bin/python
from numpy import *
from random import *
import json
#from itertools import *
#f=open('test3')

f=open('C-small-attempt1.in')
#g=open('data.file','w')
T=int(f.readline())
N=1000;
emp_prob1=(1.0/N)*(ones([N,N]))
emp_prob2=zeros([N,N])
numiters=25000;
for it in range(numiters):
    #print it
    #perm1 = range(N)
    perm2=  range(N)
    for i in range(N):
    #    rnd1=randint(i,N-1)
        rnd2=randint(0,N-1)
    #    (perm1[i],perm1[rnd1])=(perm1[rnd1],perm1[i])
        (perm2[i],perm2[rnd2])=(perm2[rnd2],perm2[i])
    #print perm2
    for i in range(N):
    #    emp_prob1[i,perm1[i]]+=1.0/numiters
        emp_prob2[i,perm2[i]]+=1.0/numiters
    #emp_prob1=emp_prob1/numiters
    #emp_prob2=emp_prob2/numiters

#print sum(emp_prob1[0,:])
#print sum(emp_prob2[0,:])
#json.dumps(emp_prob2.tolist(),g)
#g=open('data.file')
#emp_prob2=array(json.load(g))
for tt in range(1,T+1):
    N=int(f.readline())
    num = [int(i) for i in f.readline().split()]
    score1=1.0
    score2=0.0
    for i in range(N):
        score2 +=  emp_prob2[i,num[i]]
    #print score1, score2
    if (score1>=score2):
        print 'Case','#'+str(tt)+':','GOOD'
    else:
        print 'Case','#'+str(tt)+':','BAD'


