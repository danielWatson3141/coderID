from collections import defaultdict

lines = open('A-large.in', 'r').read().splitlines()
line = iter(lines)

numCases = int(line.next())

outputFile = open('A-large.out', 'w')

for i in range(numCases):
	testNumbers = line.next()
	# firstMatrix

	devices = line.next().strip().split(" ")
	sockets = line.next().strip().split(" ")

	mappings = defaultdict(list)
	for device in devices:
		for socket in sockets:
			diff = []
			for (bit1, bit2) in zip(device, socket):
				if bit1 == bit2:
					diff.append(0)
				else:
					diff.append(1)
			mappings[device].append(diff)

	# print mappings

	device1 = devices[0]
	found_mappings = []
	for mapping in mappings[device1]:
		# print mapping
		found_this_mapping = True
		indexes = []
		for device in devices:
			try:
				# print mappings[device]
				ix = mappings[device].index(mapping)
				# print ix
				if ix in indexes:
					found_this_mapping = False
				else:
					indexes.append(ix)
			except:
				found_this_mapping = False
		if found_this_mapping:
			found_mappings.append(mapping)
			continue

	if len(found_mappings) > 0:
		sums = map(lambda t: sum(t), found_mappings)
		outputFile.write("Case #" + str(i + 1) + ": " + str(min(sums)) + "\n")
	else:
		outputFile.write("Case #" + str(i + 1) + ": NOT POSSIBLE" + "\n")



