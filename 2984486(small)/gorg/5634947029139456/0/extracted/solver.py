

def findminswitches(initialInput, neededOutputs, binaryLength, alreadymodified, position, minimalnf) :
	if set(initialInput) == set(neededOutputs) :
		return alreadymodified
	for i in range(position, binaryLength, 1) :
		modified = set([flipbit(x, i) for x in initialInput])
		a = findminswitches(modified,neededOutputs,binaryLength,alreadymodified + 1, i+1, minimalnf)
		if a != None and a < minimalnf :
			minimalnf = a
	return minimalnf
	pass





def minimalNumberOfFlips(initialInput, neededOutputs, binaryLength) :
	minf = 50
	a = findminswitches(initialInput, neededOutputs, binaryLength,0,0,minf)
	if a == minf :
		return "NOT POSSIBLE"
	else :
		return a
	pass





def flipbit(n, position) :
	return n ^ (1 << position)
	
outputfile = open("output.txt", "w")

f = open("A-small-attempt0.in")
lines =  [x.strip("\n") for x in f.readlines()]
testCases = int(lines[0])
for i in xrange(testCases) :
	test = lines[i*3+1:i*3+4]
	sb = test[0].split(" ")
	switches = int(sb[0])
	binaryLength = int(sb[1])
	initialInput = [int(x,2) for x in test[1].split(" ")]
	neededOutputs = [int(x,2) for x in test[2].split(" ")]
	# print naomis
	# print kens
	# print playWar(naomis, kens)

	outputline = "Case #{0}: {1} ".format(i+1, minimalNumberOfFlips(initialInput, neededOutputs, binaryLength))
	outputfile.write(outputline + "\n")

print findminswitches([1,2,3], [4,5,6], 4,0,0,50)