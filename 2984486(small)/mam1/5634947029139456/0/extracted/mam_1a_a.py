#MAM, Google Code Jam - Round 1A, Problem A

def toBaseTwo(n):
	return int(bin(n)[2:])

def countSwithces(n):
	n = toBaseTwo(n)
	n = str(n)
	count = 0


	for character in n:
		if str(character) == "1":
			count+=1

	return count

def bitSwithcer(outlet, xbin, L):
	switched = str(outlet)
	while len(switched)<L:
		switched = "0"+switched

	xbin = str(xbin)
	while len(xbin)<L:
		xbin = "0"+xbin

	#print "xbin and switched:"
	#print xbin, switched

	switched = list(switched)

	for n in xrange(L):
		if xbin[n]=="1":
			if switched[n]=="0":
				switched[n]="1"
			elif switched[n]=="1":
				switched[n]="0"

	switched = int(''.join(switched))

	return switched

def createTest(outlets, x, L):

	outcreate = outlets[:]
	xbin = toBaseTwo(x)

	#print "First x"
	#print outcreate, xbin

	for a in xrange(len(outcreate)):
		outcreate[a] = bitSwithcer(outcreate[a], xbin, L)

	#print "Then y"
	#print outcreate
	return outcreate

def matchDevices(outlets, devices):

	result = True

	#print outlets, devices

	for d in devices:
		if d not in outlets:
			result = False
			break

	return result



infile = open("A-small-attempt0.in", "r")
outfile = open("output.txt", "w")

numtests = int(infile.readline())

for T in range(numtests):

	#Input

	(N, L) = map(int, infile.readline().split(' '))
	outlets = map(int, infile.readline().split(' '))
	devices = map(int, infile.readline().split(' '))

	#Calculations

	possible = False
	lowest = L + 1

	#print T
	#print devices

	for x in xrange(pow(2,L)):
		outtest = createTest(outlets, x, L)
		if matchDevices(outtest, devices):
			lowest = min(countSwithces(x), lowest)
			possible = True

	#Output

	outfile.write("Case #"+str(T+1)+": ")
	if possible:
		outfile.write(str(lowest))
	else:
		outfile.write("NOT POSSIBLE")
	outfile.write("\n")