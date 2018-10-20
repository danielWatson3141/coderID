import sys
import random

##            
## PROBLEM SOLVING ALGORITHM 
##  
def solve(N,l):
    print('debug: '+str(l))

def testPerm(p):
    return sum([p[i]>i for i in range(len(p))])

##            
## MAIN LOOP: read(from stdin) - solve - print(to stdout) 
##

n=1000
n1=0
n2=0
count1=0
count2=0
#thres=(521+499)//2
thres=(60091+63400)//(120*2)
#thres=(20001391470 + 18803733650)//(120*2)
n=1000
for _ in range(120):
    
    a = [k for k in range(n)]
    for k in range(n):
        p = random.randint(k,n-1)
        a[k],a[p] = a[p],a[k]
    sol1 = testPerm(a)
    n1 += sol1
    if sol1 < thres:
        count1 += 1

    a = [k for k in range(n)]
    for k in range(n):
        p = random.randint(0,n-1)
        a[k],a[p] = a[p],a[k]
    sol2 = testPerm(a)
    n2 += sol2
    if sol2 >= thres:
        count2 += 1

    
thres = (n1+n2)//(2*120)
    
    
T = int(input())
for t in range(T):
    
    ## read case
    N = int(input())
    p = [int(item) for item in input().rstrip().split()]
        
    ## solve and print result
    if testPerm(p) < thres:
        result = 'BAD'
    else:
        result = 'GOOD'
    print('Case #'+str(t+1)+': '+str(result))
    
