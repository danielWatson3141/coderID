import itertools

### HELPER FUNCTIONS

def do_flips(outlets, flip_indices):
	"""Flips indices in flip_indices in the outlets.
	Each outlet should still be a list."""
	for i in flip_indices:
		for outlet in outlets:
			if outlet[i] == '0':
				outlet[i] = '1'
			else:
				outlet[i] = '0'

### MAIN PROGRAM ###

input_filename  = "A-small-attempt1.in"
output_filename = "A-small-ans1.txt"

f = open(input_filename , "r")
g = open(output_filename, "w")

number_of_cases = int(f.readline())

case_cnt = 0
while case_cnt < number_of_cases:

	N, L = f.readline().strip().split(" ")
	N, L = int(N), int(L)
	devices = f.readline().strip().split(" ")
	outlets = f.readline().strip().split(" ")
	
	devices = [list(x) for x in devices]
	outlets = [list(x) for x in outlets]
	
	indices_to_flip_odd = set()
	indices_to_flip_even = set()
	answer = "POSSIBLE"
	for i in xrange(L):
		device_1_cnt = sum([int(x[i]) for x in devices])
		outlet_1_cnt = sum([int(x[i]) for x in outlets])
		# for column i, number of 1s in devices must be = number of 0s or number of 1s in outlets
		if device_1_cnt != outlet_1_cnt and device_1_cnt + outlet_1_cnt != N:
			answer = "NOT POSSIBLE"
			break
		else:
			# if 1s in devices = 0s in outlets (or vice versa, then have to flip)
			if device_1_cnt != outlet_1_cnt and device_1_cnt + outlet_1_cnt == N:
				indices_to_flip_odd.add(i)
			elif device_1_cnt == outlet_1_cnt and device_1_cnt + outlet_1_cnt == N:
				indices_to_flip_even.add(i)
	
	if answer == "POSSIBLE" and N == 1:
		answer = str(len(indices_to_flip_odd))
	
	if answer == "POSSIBLE":
		devices_test = [''.join(x) for x in devices]
		devices_test.sort()
		
		# flip all the indices that MUST be flipped
		do_flips(outlets, indices_to_flip_odd)
		flips = len(indices_to_flip_odd)
		
		
		foundAnswer = False
		# generate all possible index sets to flip which could result in the answer
		# and run through them
		for k in xrange(len(indices_to_flip_even) + 1):
			for indices_to_flip in itertools.combinations(indices_to_flip_even, k):
				
				do_flips(outlets, indices_to_flip)

				# do testing
				outlets_test = [''.join(x) for x in outlets]
				outlets_test.sort()
				
				if devices_test == outlets_test:
					answer = str(flips + len(indices_to_flip))
					foundAnswer = True
					break
				
				do_flips(outlets, indices_to_flip)
			
			if foundAnswer == True:
				break
		
		if foundAnswer == False:
			answer = "NOT POSSIBLE"

	# output to screen & file
	print   "Case #" + str(case_cnt+1) + ": " + answer
	g.write("Case #" + str(case_cnt+1) + ": " + answer + "\n")
	
	# move on to the next case
	case_cnt += 1

f.close()
g.close()

