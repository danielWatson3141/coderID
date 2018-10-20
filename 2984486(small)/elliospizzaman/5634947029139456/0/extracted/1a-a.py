from sys import argv
import itertools
fh = open(argv[1])
casecount = int(fh.readline())

for casenum in xrange(1, casecount+1):
	outletcount, flowlength = map(int, fh.readline().split())
	outlets = fh.readline().strip().split()
	sorteddevices = sorted(fh.readline().strip().split())

	minchanges = -1

	possiblechanges = itertools.product(range(2), repeat=flowlength)

	for changes in possiblechanges:
		testoutlets = outlets[:]
		
		for i in xrange(len(testoutlets)):
			for j in xrange(len(changes)):
				if changes[j]==1:
					if testoutlets[i][j]=="1":
						testoutlets[i] = testoutlets[i][:j] + "0" + testoutlets[i][j+1:]
					else:
						testoutlets[i] = testoutlets[i][:j] + "1" + testoutlets[i][j+1:]

		if sorted(testoutlets) == sorteddevices:
			changesmade = changes.count(1)
			if minchanges == -1 or minchanges > changesmade:
				minchanges = changesmade
	if minchanges == -1:
		print "Case #%i: NOT POSSIBLE"%casenum
	else:
		print "Case #%i: %i"%(casenum, minchanges)