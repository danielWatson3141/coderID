'''
Created on Mar 11, 2014

@author: John Cornwell
'''
import operator,math,string,itertools,fractions,heapq,collections,re,array,bisect,random
from fractions import gcd
def lcm(a, b):
	return a * b / gcd(a, b)


# Called before solving any functions
def init(i_num, fc_in):
	return
	


# Parse next set of arguments
def parse_next(fc_in):
	ignore = fc_in.readline()
	ls_outlets = fc_in.readline().split()
	ls_devices = fc_in.readline().split()
	
	fcint = lambda x: int(x, 2)
	
	return map(fcint, ls_outlets), map(fcint, ls_devices)



# Solve individual instance
def solve(ls_out, ls_dev):
	si_dev = set(ls_dev)
	n = len(ls_out)
	ret = 1000
	for i in xrange(n):
		for j in xrange(n):
			flip = ls_out[i] ^ ls_dev[j]
			new_out = [x ^ flip for x in ls_out]
			#print ls_out[i], ls_dev[j], flip
			if set(new_out) == si_dev:
				ret = min(bin(flip).count("1") ,ret)
			
	return ret if ret != 1000 else "NOT POSSIBLE"



def _run_main():
	# Config
	s_let = 'A'
	s_run = 2
	
	if s_run == 0:
		fc_in = open('infile.in', 'r')
	elif s_run == 1:
		fc_in = open('Z:\Users\John Cornwell\Downloads\%s-small-attempt0.in' % s_let, 'r')
	else:
		fc_in = open('Z:\Users\John Cornwell\Downloads\%s-large.in' % s_let, 'r')
	fc_out = open('out.txt', 'w')
	
	i_num = int(fc_in.readline())
	init(i_num, fc_in)
	
	# Pare and solve test cases
	for i in range(1, i_num+1):
		args = parse_next(fc_in)
		ret = solve(*args)
		s_line = 'Case #%i: %s' % (i, str(ret))
		print s_line
		fc_out.write(s_line + '\n')
		
		
if __name__ == '__main__':
	_run_main()