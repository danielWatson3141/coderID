#!/usr/bin/env python

import sys

def subsets(s):
	yield []
	for i, d in enumerate(s):
		for comb in subsets(s[i+1:]):
			yield [d] + comb

f = sys.stdin

switch = {'0':'1', '1':'0'}

T = int(f.readline().strip())

for i in range(1, T+1):
	[N, L] = [int(x) for x in f.readline().strip().split()]
	init = f.readline().strip().split()
	req = f.readline().strip().split()
	
	min_flips = 10000
	for subset in subsets(range(L)):
		flipd = []
		for socket in init:
			for j in subset:
				socket = socket[:j] + switch[socket[j]] + socket[j+1:]
			if socket not in req: break
			flipd.append(socket)
		if len(flipd) == len(req) and len(subset) < min_flips: min_flips = len(subset)
	if min_flips == 10000:
		y = "NOT POSSIBLE"
	else:
		y = min_flips

	print "Case #%s: %s" % (i, y)
