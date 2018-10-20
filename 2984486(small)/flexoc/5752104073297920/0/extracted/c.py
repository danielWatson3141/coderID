from random import randrange
T = input()
for t in xrange(T):
	K = input()
	l = raw_input()
	o = "GOOD" if randrange(0,2) == 0 else "BAD"
	print "Case #%d: %s" %(t+1,o)