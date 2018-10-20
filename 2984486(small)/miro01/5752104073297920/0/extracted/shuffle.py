#!/usr/bin/env python

import sys
import numpy.random as nprnd

def good(N):
	a = range(N)
	for k in range(N):
		p = nprnd.randint(k, N)
		a[k], a[p] = a[p], a[k]
	return a

def bad(N):
        a = range(N)
        for k in range(N):
                p = nprnd.randint(0, N)
                a[k], a[p] = a[p], a[k]
	return a

#T = 120
#counts = []
#GDa = []
#BDa = []
#for k in range(200):
#	cnt = 0
#	for i in range(T):
#		N = 1000
#		GDa.append(sum(good(N)[:200]))
#		BDa.append(sum(bad(N)[:200]))
#print 1.*sum(GDa)/len(GDa), 1.*sum(BDa)/len(BDa)

f = sys.stdin

T = int(f.readline().strip())

for i in range(1, T+1):
	N = int(f.readline().strip())
	a = [int(x) for x in f.readline().strip().split()]
	if sum(a[:200]) > 96000:
		y = "GOOD"
	else:
		y = "BAD"
	print "Case #%s: %s" % (i, y)
