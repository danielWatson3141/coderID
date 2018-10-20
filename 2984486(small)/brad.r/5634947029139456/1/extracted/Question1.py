import math
f = open('A-large.in.txt', 'r')
numCases = int(f.readline())
x = 1
while x <= numCases:
	line = f.readline()
	numOutlets, length = line.split()
	numOutlets, length = int(numOutlets), int(length)
	outlets = []
	devices = []
	line = f.readline()
	line = line.split()
	y = 0
	while y < numOutlets:
		outlets.append(line[y])
		y += 1
	line = f.readline()
	line = line.split()
	y = 0
	while y < numOutlets:
		devices.append(line[y])
		y += 1
	differences = []
	currentDevice = currentOutlet = possibleFlips = 0
	possible = True
	while currentOutlet < numOutlets:
		currentDevice = 0
		differences.append([])
		while currentDevice < numOutlets:
			differences[currentOutlet].append(int(outlets[currentOutlet],2) ^int(devices[currentDevice],2))
			currentDevice += 1
		currentOutlet += 1
	possibleValues = differences[0]
	outlet = 1
	while outlet < numOutlets:
		actualValues = []
		for element in possibleValues:
			if element in differences[outlet]:
				actualValues.append(element)
		possibleValues = actualValues
		outlet += 1
	if len(possibleValues) == 0:
		print "Case #" + str(x) + ": NOT POSSIBLE"
	else:
		minFlips = length
		for value in possibleValues:
			flips = 0
			value = str(bin(value))[2:]
			for char in value:
				if char == '1':
					flips += 1
			if flips < minFlips:
				minFlips = flips
		print "Case #" + str(x) + ": " + str(minFlips)
	x += 1