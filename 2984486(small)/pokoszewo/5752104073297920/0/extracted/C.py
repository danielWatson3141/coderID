if __name__ == '__main__':
	cases = []
	q = int(raw_input())
	for i in xrange(q):
		n = int(raw_input())
		t = map(int, raw_input().split())
		factor = 0
		for j in xrange(n):
			factor += (t[j]-j)**8
		cases.append((factor, i))
	
	cases.sort()

	answerYes = set()

	for i in xrange(q/2):
		answerYes.add(cases[i][1])

	for i in xrange(0, q):
		print "Case #%d:" % (i+1),
		if i in answerYes:
			print "BAD"
		else:
			print "GOOD"
