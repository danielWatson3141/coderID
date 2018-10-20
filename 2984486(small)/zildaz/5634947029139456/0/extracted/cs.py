inputfile = open('A-small-attempt3.in')
outputfile = open('result2.txt','w')

no_of_tests = int(inputfile.readline())

for t in range(no_of_tests):
	a1 = map(long,inputfile.readline().split())
	b1s = inputfile.readline().split()
	b2s = inputfile.readline().split()
	N=int(a1[0])
	N=int(a1[1])

	b1 = []
	b2 = []
	
	for b in b1s:
		b1.append(long(b,2))

	for b in b2s:
		b2.append(long(b,2))


	b1.sort()
	b2.sort()
	

	match = -1
	lowest = -1
	for nn in range(2**N):
		test = []
		for nb in b1:
			test.append(nb^nn)
		test.sort()
		match =1
		for i in range(len(test)):
			if test[i]!=b2[i]:
				match =-1
		if match ==1:
			bb = bin(nn).count("1")
			if lowest==-1 or bb<lowest:
				lowest = bb

	if lowest==-1:
		print  >>outputfile,"Case #%d: NOT POSSIBLE"  % (t+1)
	else:
		print  >>outputfile,"Case #%d: %d"  % (t+1,lowest)


outputfile.close()