def xor(a, b):
	if len(a) == 1:
		return [a == b]
	return [a[0] == b[0]] + xor(a[1:], b[1:])

def flip(flow, switches):
	return [int(not flow[i]) if switches[i] else flow[i] for i in range(len(flow))]

def charge(initial, required):
	count = float('inf')
	
	for device in required:
		# print device
		fail = False
		switches = map(lambda x: int(not x), xor(initial[0], device))
		# print switches
		newFlows = [flip(flow, switches) for flow in initial]
		# print newFlows

		for device2 in required:
			# print 'd2', device2
			match = None

			for flow in newFlows:
				# print 'f', flow
				if device2 == flow:
					match = flow
					break
			if match:
				newFlows.remove(flow)
			else:
				fail = True
				break
		
		if not fail:
			count = min(count, sum(switches))

		# print
		# print
	return "NOT POSSIBLE" if count == float('inf') else count

from sys import stdin

input = stdin.read().split('\n')

for t in range(int(input[0])):
	N, L = map(int, input[3 * t + 1].split())
	initial = [map(int, x) for x in input[3 * t + 2].split()]
	required = [map(int, x) for x in input[3 * t + 3].split()]

	print "Case #{0}: {1}".format(t+1, charge(initial, required))