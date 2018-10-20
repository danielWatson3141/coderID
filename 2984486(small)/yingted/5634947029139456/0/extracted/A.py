#!/usr/bin/env python2
for t in xrange(1,1+int(raw_input())):
	n,l=map(int,raw_input().split())
	a=map(long,raw_input().split(),[2]*n)
	b=map(long,raw_input().split(),[2]*n)
	c=map(long.__xor__,a,b)
	a.sort()
	print"Case #%d:"%t,
	try:
		print min(bin(i).count('1') for i in xrange(2**l)if a==sorted(map(long(i).__xor__,b)))
	except ValueError:
		print"NOT POSSIBLE"
