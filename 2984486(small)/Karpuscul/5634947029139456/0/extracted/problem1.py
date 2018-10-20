import itertools

def toBinList(list):
	return map(lambda x: int(x, 2), list)

def solve(N, L, outlets, devices):
	sortedOutlets = sorted(outlets)

	#print(sorted(devices), sortedOutlets)

	if sorted(devices) == sortedOutlets:
		return 0

	for n in range(1, L + 1):
		for s in set(itertools.permutations(['1'] * n + ['0'] * (L - n))):
			switch = int(''.join(s), 2)
			#print(bin(switch))
			updatedDevices = map(lambda x: x ^ switch, devices)
			#print(sorted(updatedDevices), sortedOutlets)
			if sorted(updatedDevices) == sortedOutlets:
				return n

	return "NOT POSSIBLE"

lineNumber = -1
results = []

for line in open("A-small-attempt1.in"):
	lineNumber += 1

	if lineNumber == 0:
		continue;

	print(lineNumber)

	lineRemainder = lineNumber % 3
	values = map(lambda x: x.strip(), line.split(" "))
	if lineRemainder == 1:
		N, L = map(lambda x: int(x), values)
	elif lineRemainder == 2:
		outlets = toBinList(values)
	else:
		devices = toBinList(values)
		#print(N, L, map(lambda x: bin(x), outlets), map(lambda x: bin(x), devices))
		results.append(solve(N, L, outlets, devices))

output = open("output1.txt", "w")
for i in range(len(results)):
	output.write("Case #%s: %s\n" % (i + 1, results[i]))
