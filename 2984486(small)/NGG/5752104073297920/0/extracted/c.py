import sys
data = [line.split() for line in sys.stdin.readlines()]
tn = int(data[0][0])
list = []
sol = []
for ti in xrange(tn):
	n = int(data[2*ti+1][0])
	p = map(int, data[2*ti+2])
	s = [i for i in xrange(n)]
	for db in xrange(6):
		for i in xrange(n):
			s[i] = p[s[i]]
	cyc = [None for i in xrange(n)]
	db = 0
	for i in xrange(n):
		if cyc[i] == None:
			db += 1
			j = i
			while cyc[j] == None:
				cyc[j] = db
				j = p[j]
	fix = 0
	fixs = 0
	inv = 0
	for i in xrange(n):
		if p[i] == i:
			fix += 1
		if s[i] == i:
			fixs += 1
		for j in xrange(i+1, n):
			if p[i] > p[j]:
				inv += 1
	list.append((abs(6.9-db)/6.9 + abs(1.0-fix) + abs(4.0-fixs)/4.0 + abs(float(inv)-float(n)*float(n-1)*0.25)/(float(n)*float(n-1)*0.25), ti, db, fix))
	sol.append("BAD")
sorted = sorted(list)
for i in xrange(tn/2):
	sol[sorted[i][1]] = "GOOD"
for i in xrange(tn):
	print "Case #%d:" % (i+1), sol[i] #, list[i]
print >>sys.stderr, sorted