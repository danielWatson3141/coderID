from sys import argv
fh = open(argv[1])
casecount = int(fh.readline())

for casenum in xrange(1, casecount+1):
	n = int(fh.readline()) #Always equals 1000
	perm = map(int, fh.readline().strip().split())
	algorithm = "GOOD"
	for num in xrange(n):
		if num == perm[num]:
			algorithm = "BAD"
	print "Case #%i: %s"%(casenum, algorithm)