import copy

def trial():
	(N, L) = [int(i) for i in raw_input().split()]
	flows = [list(charge) for charge in raw_input().split()]
	devices = [list(charge) for charge in raw_input().split()]
	sampleDevice = devices[0]
	temp = set()
	for charge in devices:
		temp.add(tuple(charge))
	devices = temp
	minBits = L+1
	for flow in flows:
		flippedBits = set()
		for l in range(L):
			if flow[l] != sampleDevice[l]:
				flippedBits.add(l)
		if len(flippedBits) < minBits:
			tempFlows = copy.deepcopy(flows)
			hashedFlows = set()
			for tempFlow in tempFlows:
				for bit in flippedBits:
					if tempFlow[bit] == '0':
						tempFlow[bit] = '1'
					else:
						tempFlow[bit] = '0'
				hashedFlows.add(tuple(tempFlow))
			if hashedFlows == devices:
				minBits = len(flippedBits)
	if minBits != L+1:
		return minBits
	return "NOT POSSIBLE"







T = int(raw_input())
for t in range(1,T+1):
	print "Case #%d:" % t,
	print trial()
