T = int(raw_input())

results = []

def check(N,L,flows,needs):
	#find flippings: each is a list of the indices of bits we need to flip
	flippings = []
	validities = []
	for i in xrange(N):
		entry = []
		for j in xrange(L):
			if flows[0][j] != needs[i][j]:
				entry.append(3) #flip
			else:
				entry.append(2) #don't flip
		flippings.append(entry)
	#print "flippings:", flippings
	for i in xrange(N): #for each flipping
		newflows = []
		flips = 0
		valid = True
		for a in xrange(L): #for each bit
			if flippings[i][a] == 3: flips += 1 #count number of flips in flipping
		for j in xrange(N): #for each flow
			newflow = ""
			for k in xrange(L): #for each bit
				if flippings[i][k] == 3:
					if flows[j][k] == "1": newflow += "0"
					else: newflow += "1"
				else:
					if flows[j][k] == "1": newflow += "1"
					else: newflow += "0"
			if newflow not in needs:
				valid = False
		if valid == True:
			validities.append(flips)
		else:
			validities.append(100)
	return validities


for i in xrange(T):
	N, L = map(int, raw_input().split())
	flows = map(str, raw_input().split())
	needs = map(str, raw_input().split())
	resultarray = check(N,L,flows,needs)
	#print "resultarray:", resultarray
	result = min(resultarray)
	results.append(result)

"""
for k in xrange(T):
	if results[k] == 100:
		print "Case #{}: NOT POSSIBLE".format(k+1)
	else:
		print "Case #{}: {}".format(k+1, results[k])

"""
f = open("ChargingChaosOut.txt", 'w')
for k in xrange(T):
	if results[k] == 100:
		print >> f, "Case #{}: NOT POSSIBLE".format(k+1)
	else:
		print >> f, "Case #{}: {}".format(k+1, results[k])
f.close()