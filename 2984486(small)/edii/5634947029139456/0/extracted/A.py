#!/usr/bin/env python
import sys

def create_permutations(low, high):
	if low==high:
		return [[low]]
	else:
		out = []
		while low <= high:
			out.append([low])
			for p in create_permutations(low+1, high):
				out.append([low] + p)
			low+=1
		return out
		
def flip_switches(outlets, flips):
	outlets_out = []
	
	for outlet in outlets:
		outlet_out = outlet
		for f in flips:
			ch = outlet_out[f]
			ch = '0' if ch=='1' else '1'
			outlet_out = outlet_out[:f] + ch + outlet_out[f+1:]
		outlets_out.append(outlet_out)
			
	return outlets_out
	

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

	T = int(f_in.readline())
	for t in range(T):
		f_out.write('Case #%d: ' % (t+1))

		N, L = tuple(map(int, f_in.readline().split(' ')))
		outlets = list(map(str.strip, f_in.readline().split(' ')))
		assert len(outlets) == N
		
		devices = list(map(str.strip, f_in.readline().split(' ')))
		assert len(devices) == N
		
		outlets.sort()
		devices.sort()
		
		flip_p = create_permutations(0, L-1)
		
		min_flips = 1000
		
		#print outlets, devices
		if outlets == devices:
			min_flips = 0
		else:
			for flips in flip_p:
				outlets_f = flip_switches(outlets, flips)
				outlets_f.sort()
				
				if devices == outlets_f:
					if len(flips) < min_flips:
						min_flips = len(flips)
					
		if min_flips == 1000:
			f_out.write('NOT POSSIBLE')
		else:
			f_out.write('%d' % min_flips)
		
		f_out.write('\n')

	f_in.close()
	f_out.close()

if __name__=='__main__':
	main()
