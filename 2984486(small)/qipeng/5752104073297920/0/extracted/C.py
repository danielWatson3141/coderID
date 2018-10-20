with open('C-small-attempt1 (1).in') as f:
	T = int(f.readline())

	for case in xrange(T):
		N = int(f.readline())
		d = [int(x) for x in f.readline().split()]

		count = 0
		for i in range(N):
			count += abs(i - d[i])

		if count <= N * N / 4:
			print "Case #%d: BAD" % (case + 1)
		else:
			print "Case #%d: GOOD" % (case + 1)