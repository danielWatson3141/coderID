#!/usr/bin/env python3.2
#coding=UTF-8

'''

Google Code Jam 2014
Round 1A
Problem A
Charging Chaos

Instructions:
	chmod u+x process.py
	./process.py <input_file >output_file
	# stderr output is intended to display on a console

Notes:
	* N outlets, N devices
	* flow = string of 0s and 1s, length L
	* all flows different
	* minimum switches
	* 
	* can we begin by sorting both the outlets and devices in some order to make a simple systematic solution easier?
	* can we begin by finding the outlet (or device) that requires the most bits flipped to match *any* device (or outlet)?
	* 
	* sizes:
		* 100 cases
		* small:
			* N <= 10, L <= 10
			* 100 * 10 10-bit strings
		* large: 
			* N <= 150, L <= 40
			* 100 * 150 40-bit strings
	
	* I found a hamming distance function, but not sure how useful it is, since in this case it often matters *which* bits differ
	* if we try all permutations of the devices, to match up to the outlets, then try flipping all combinations of bits, we get:
		* 
	
	* how about this:
		* we are trying to reduce the max number of bits difference between devices and outlets
		* find max(for all devices, min(for all outlets, hamming distance between device and outlet))
		* attempt to minimise that value by flipping 1 switch each iteration
		* will this always get us closer to our goal?
		* pick the device with worst value
		* compare that device against each outlet (150 iterations)
		* for each outlet, determine the switch pattern to flip to get it to match (xor)
		* this is the slow bit: take that switch pattern and apply to all other devices (xor) in turn, and try to match them against outlets
		* but we just have to find 1 pattern that matches - we don't have to eliminate it from the set or anything, since all the patterns are unique
		* so we simply use the first device to determine patterns to try
		* then we check all remaining devices against all remaining outlets in turn, to find a match (aborting as soon as one is found)
		* if we find a single device that doesn't match any outlet, we abort that bit pattern and move to the next
		* we should use integers - I think it should be fine to just let python handle the 40-bit numbers, and not worry about the number sizes?
	
	* clearer statement of the algorithm I worked out:
		dev = devices[0]
		minbits = L+1
		for i in range(N): # outlets
			switches = dev ^ outlet[i]
			bad_device = 0
			for j in range(1,N):  # remaining devices - must get through all of them - try to find 1 good (matching) outlet
				good_outlet = 0
				for k in range(N): # outlets
					if (device[j] ^ outlet[k]) == switches:
						good_outlet = 1
						break
				if not good_outlet:
					bad_device = 1
					break
			if not bad_device:
				bits = count_bits(switches)
				if bits < minbits: minbits = bits
		return None if (minbits == L+1) else minbits
	
	* actually that needs cleaning up by using subroutines with return within and after the loop
				
	* complexity: 
		* about N**3
		* 150**3 = 3,375,000 --- doable
		* I'm running 32-bit windows on 64-bit machine, and I have no clue about cygwin's python build.... hope it will use 64-bit instructions

'''

################################################################################

def count_bits(x):
	count = 0
	while x:
		count += 1
		x &= x-1
	return count

def switch_count(N, L, outlets, devices):
	dev = devices[0]
	minbits = L+1
	
	def switches_works_for_device(switches, device):
		for i in range(N): # try device on all outlets
			if (outlets[i] ^ switches) == device:
				return True
		return False
	
	def switches_works(switches):
		for i in range(1,N): # remaining devices - must get through all of them - try to find 1 good (matching) outlet
			if not switches_works_for_device(switches, devices[i]):
				return False
		return True
	
	for i in range(N): # outlets
		outlet = outlets[i]
		switches = dev ^ outlet
		bits = count_bits(switches)
		if switches_works(switches):
			if bits < minbits:
				minbits = bits
	return None if (minbits == L+1) else minbits

def read_case(id, input):
	N, L = [int(x) for x in input.readline().split()]
	outlets = [int(str, 2) for str in input.readline().split()]
	devices = [int(str, 2) for str in input.readline().split()]
	return (N,L,outlets,devices)

def solve_case(id, case):
	N,L,outlets,devices = case
	
	solution = switch_count(N,L,outlets,devices)
	
	return "Case #{}: {}\n".format(id, 'NOT POSSIBLE' if solution == None else solution)


################################################################################


from sys import stdin, stdout, stderr
import time
import math
import pickle
import io

execution_timer = time.time
#execution_timer = time.clock
debugging = 1


################################################################################


def debug(message):
	if debugging:
		stderr.write(message() if hasattr(message, '__call__') else message)

def report(message):
	stderr.write(message)

def prepare_cached(prepare_data, pickle_path='data.pickle'):
	try:
		data = pickle.load(io.open(pickle_path, 'rb'))
		report("Loaded {}.\n".format(pickle_path))
	except IOError:
		data = prepare_data()
		report("Prepared {}.\n".format(pickle_path))
		pickle.dump(data, io.open(pickle_path, 'wb'))
	return data

def main():
	t0 = execution_timer()
	#prepare()
	t1 = execution_timer()
	report("Completed preparation in {:.6f} seconds.\n".format(t1 - t0))
	
	T = int(stdin.readline())
	for case_id in range(1,T+1):
		report("Processing test case {} of {} (output {}). {:.0f} seconds elapsed.".format(case_id, T, case_id-1, execution_timer() - t1))
		report("\n" if debugging else "\r")
		stderr.flush()
		stdout.write(solve_case(case_id, read_case(case_id, stdin)))
		stdout.flush()
	
	t2 = execution_timer()
	report("Processed {} test cases in {:.6f} seconds.                           \n".format(T, t2 - t1))
	report("Total time: {:.6f} seconds.\n".format(t2 - t0))

if __name__ == '__main__':
	main()

