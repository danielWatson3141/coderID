#!/usr/bin/python

import sys

N = 1000

DICT = [ [0]*N for _ in xrange(N) ]
for name in sys.argv[1:]:
	t = [ map(int, s.split()) for s in open(name).readlines() ]
	for i in xrange(N):
		for j in xrange(N):
			DICT[i][j] += t[i][j]


for i in xrange(N):
	print " ".join([ "%7d"%x for x in DICT[i] ])
