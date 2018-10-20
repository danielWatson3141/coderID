#!/usr/bin/env python
import sys
import random



def main():
	# Setup input and output file handlers
	if len(sys.argv) == 1:
		f_in = sys.stdin
		f_out = sys.stdout
	else:
		f_in = open(sys.argv[1])
		if len(sys.argv) > 2:
			f_out = open(sys.argv[2], 'w')
		else:
			f_out = sys.stdout
			
	f = open('lookup.txt')
	lines = f.read().splitlines()
	f.close()
	
	# lookup.txt contains factorial(8)=40320 lines, all of which has 
	# one integer. Each integer corresponds to one permutation and is 
	# calculated by running bad algorithm with N=8 20000000 times
	# and then the counter for the given permutation is incremented.
	
	props = []
	for line in lines:
		props.append(float(line)/49.6031746031746 > 1.0) # float(line)/2000000 > 1.0/40320.0
		
	
	def get_propability(loc):
		i = int(round(loc*40320))
		if i >= 40320:
			i = 40319
		return props[i]
		

	T = int(f_in.readline())
	for t in range(T):
		f_out.write('Case #%d: ' % (t+1))

		N=int(f_in.readline())
		
		p = list(map(float, f_in.readline().split(' ')))
		
		loc = 0.0
		try:
			for n in range(N):
				loc += p[n]/(N**(n+1))
		except: # this will throw an exception, but then we'll just continue...
			pass
			
		P = get_propability(loc)
		if P:
			f_out.write('BAD')
		else:
			f_out.write('GOOD')
		
		f_out.write('\n')

	f_in.close()
	f_out.close()

if __name__=='__main__':
	main()
