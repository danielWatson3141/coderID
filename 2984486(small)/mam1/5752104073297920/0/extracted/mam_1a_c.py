#MAM, Google Code Jam - Round 1A, Problem C

infile = open("C-small-attempt5.in", "r")
outfile = open("output.txt", "w")

numtests = int(infile.readline())

for T in range(numtests):

	#Input

	N = int(infile.readline())
	#N = 1000
	mylist = map(int, infile.readline().split(' '))

	#Calculations

	total = 0.0
	count = 250
	average = N/2
	threshold = 20

	for n in xrange(count):
		total += average - mylist[n]

	total = total*1.0 / count
	BadAlgo = False
	print "%.2f" %total
	if total > threshold:
		BadAlgo = True


	#Output

	outfile.write("Case #"+str(T+1)+": ")
	if BadAlgo:
		outfile.write("BAD")
	else:
		outfile.write("GOOD")
	outfile.write("\n")