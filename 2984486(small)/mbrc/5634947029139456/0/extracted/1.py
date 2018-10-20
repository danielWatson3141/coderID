from itertools import *
import copy
def f(x):
	return int("".join(x))
def solve(n,l,X,Y):
	A=set(map(f,Y))
	best=100
	for i in range(0,l):
		for C in combinations(range(0,l),i):
			B=copy.deepcopy(X)
			for j in C:
				for k in range(0,n):
					if(B[k][j]=='0'): B[k][j]='1'
					else            : B[k][j]='0'
			D=set(map(f,B))
			if (A==D):
				return str(i)
	return "NOT POSSIBLE"

t=input()
for i in range(1,t+1):
	n,l = map(int,raw_input().split())
	X   = map(list,raw_input().split())
	Y   = map(list,raw_input().split())
	print "Case #"+str(i)+": "+solve(n,l,X,Y)
	


