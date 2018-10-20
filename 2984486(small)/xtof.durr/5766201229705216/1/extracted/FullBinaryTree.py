#!/usr/bin/env pypy
# -*- coding: utf-8 -*-
# google code jam - c.durr + mathieu schmitt- 2014

# FullBinaryTree
# http://code.google.com/codejam/contest/2984486/dashboard#s=p1
# quadratic complexity
# solve greedily for each possible root

def readint():    return int(raw_input())
def readarray(f): return map(f, raw_input().split())

def readTree():
	n = readint()
	T = [[] for u in range(n)]
	for _ in range(n-1):
		u,v = readarray(int)
		u -= 1
		v -= 1
		T[u].append(v)
		T[v].append(u)
	return T

def solve(T):
	n = len(T)
	return n-1-max(score(T, u, -1) for u in range(n))


# size of largest binary subtree
def score(T, root, father):
	d = 0 
	for v in T[root]:
		if v!=father:
			d += 1
	if d<=1:
		return 0
	s = [score(T, v, root) for v in T[root] if v!=father]
	s.sort()
	return 2 + s[-1]+s[-2]


for test in range(readint()):
	T = readTree()
	print "Case #%i:"% (test+1), solve(T)
    
    
