import itertools
NOT_POSSIBLE = -1
SUCCESS = 0

with open("input.in", 'r') as infile:
	cases = int(infile.readline()) # first line num of cases
	results = [0] * cases  # each is num of flips
	
	for case in range(cases):
		N = 0
		L = 0
		firstline = infile.readline().split()  # N's blocks
		N = int(firstline[0])
		L = int(firstline[1])
		switch_states = ["".join(seq) for seq in itertools.product("01", repeat=L)]
		switch_states = [int(x, base=2) for x in switch_states]

		
		initflow = infile.readline().split()
		initflow = [int(x, base=2) for x in initflow]  # convert to binary
		reqflow = infile.readline().split()
		reqflow = [int(x, base=2) for x in reqflow]
			
		for i in range(len(switch_states)):
			# apply switch, use XOR to flip bits
			flow = [switch_states[i] ^ f for f in initflow]  # now have flipped flows
	
			flow.sort()
			reqflow.sort()
			
			matches = []
			for j in range(len(flow)):
				matches.append(SUCCESS if flow[j] == reqflow[j] else 1)
			
			result = sum(matches)
			if result == SUCCESS:
				results[case] = bin(switch_states[i]).count("1") # number of flips (1)s in the switch
				break
			else:
				results[case] = NOT_POSSIBLE

		
	# print out results
	for case in range(cases):
		if results[case] == NOT_POSSIBLE:
			print("Case #{}: {}".format(case + 1, "NOT POSSIBLE"))
		else:
			print("Case #{}: {}".format(case + 1, results[case]))
			