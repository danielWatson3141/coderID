#!/usr/bin/python -u

# Solves Google Codejam "Charging Chaos"
# http://code.google.com/codejam
# Sam Moore (matches)
# 2014-04-26

import sys
import os

def GetFlow(string):
	flow = 0
	for i,s in enumerate(string):
		if (s == '1'):
			flow = flow | (1 << i)
	return flow

def CountBits(integer):
	count = 0
	while integer > 0:
		count += (integer & 1)
		integer = integer >> 1
	return count

def main(argv):
	nCases = int(sys.stdin.readline().strip(" \r\n"))
	
	for c in xrange(1, nCases+1):
		# Solve case
		N, L = map(int, sys.stdin.readline().strip(" \r\n").split(" "))

		#print "N, L are " + str((N, L))
		inputs = map(GetFlow, sys.stdin.readline().strip(" \r\n").split(" "))	
		flows = map(GetFlow, sys.stdin.readline().strip(" \r\n").split(" "))	

		p = 0
		for p in range((1 << (L+1))):
			#print "p = %x - bits %d" % (p, CountBits(p))
			newin = map(lambda e : e ^ p, inputs)
			if (len(set(newin).difference(set(flows))) == 0):
				break

		count = CountBits(p)
		if count <= L:
			print "Case #%d: %d" % (c, count)
		else:
			print "Case #%d: NOT POSSIBLE" % (c,)

	
	return 0

if __name__ == "__main__":
	sys.exit(main(sys.argv))
		
