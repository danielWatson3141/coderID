#!/usr/bin/python
import itertools

def powerset(iterable):
	    "powerset([1,2,3]) --> () (1,) (2,) (3,) (1,2) (1,3) (2,3) (1,2,3)"
	    s = list(iterable)
     	    return itertools.chain.from_iterable(itertools.combinations(s, r) for r in range(len(s)+1))

with open('in','r') as f:
    data=f.read()
linens = data.splitlines()
linens.reverse()
with open('submit','w') as f:
 for x in range(0,int(linens.pop())):
    NL = [int(i) for i in linens.pop().split()]
    N = NL[0]
    L = NL[1]
    init = [[j for j in i] for i in linens.pop().split()]
    needed = [[j for j in i] for i in linens.pop().split()]
    
    foundOne=False
    for P in powerset(range(0,L)):
      mod = []
      mod = [[j for j in i] for i in init]
      for pos in P:
       for m in mod:
		if m[pos]=='1':
			m[pos]='0'
		elif m[pos]=='0':
			m[pos]='1'

      if sorted(mod) == sorted(needed):
	print "Case #%d: %d" %(x+1,len(P))
	foundOne=True
	break;
    if foundOne == False:
			    print "Case #%d: NOT POSSIBLE" % (x+1)


