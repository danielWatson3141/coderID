#!/usr/bin/python

import sys

DICT = [ map(int, s.split()) for s in open("pc.log.all").readlines() ]

def score(a):
	s = 1
	for (i,x) in enumerate(a):
		s *= DICT[x][i]
	return s

TT = int(sys.stdin.readline())
R = []

for T in xrange(1,TT+1):
	_ = int(sys.stdin.readline())
	a = map(int, sys.stdin.readline().split())
	R.append((T, score(a)))

R2 = sorted(R, key=lambda x:x[1])
print >> sys.stderr, R2
R3 = [ (tid, "GOOD" if i<TT/2 else "BAD") for (i,(tid,sc)) in enumerate(R2) ]

R4 = sorted(R3, key=lambda x:x[0])

for (tid,ans) in R4:
	print "Case #%d: %s" % (tid, ans)

