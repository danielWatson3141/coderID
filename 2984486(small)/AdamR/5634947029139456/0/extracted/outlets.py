import psyco
import sys
import itertools

psyco.full()

test_input = r'''3
3 2
01 11 10
11 00 10
2 3
101 111
010 001
2 2
01 10
10 01'''.split('\n')

DEBUG = False

def debug(s):
	if not DEBUG:
		return
	sys.stderr.write(str(s) + '\n')

def readline():
	if DEBUG:
		return test_input.pop(0)
	return raw_input()				
				
def case(casenum):
	
	# N devices
	# N outlets
	# L flow length
	# L number of switches, 1st flips first bit, etc

	# minimum number of switches to flip
	
	# 3 2
	# 01 11 10
	# 11 00 10
	
	
	N, L = map(int, readline().split())
	debug([N, L])

	outlets = map(lambda x: int(x, 2), readline().split())
	devices = map(lambda x: int(x, 2), readline().split())
	debug([outlets, devices])
	
	output = 'NOT POSSIBLE'
	
	sd = sorted(devices)
	
	if sorted(outlets) == sd:
		output = 0
	else:
		m = None
	
		# For every switch combination.
		for i in xrange(1, 2**L):
			to = list(outlets)
			# Flip the corresponding outlet bits.
			for j, o in enumerate(to):
				to[j] = o ^ i
			if sorted(to) == sd:
				# Number of switches to flip is number of 1 bits.
				# Store the minimum number to flip.
				c = bin(i).count('1')
				if m is None:
					m = c
				else:
					m = min(m, c)
		
		if m is not None:
			output = m


	print "Case #%d: %s" % (casenum, output)
	
	

def main():
	numcases = readline()
	for i in xrange(int(numcases)):
		case(i + 1)

main()
