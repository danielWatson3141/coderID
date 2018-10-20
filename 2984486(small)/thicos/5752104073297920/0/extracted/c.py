T = int(raw_input())

for t in range(T):
	N = int(raw_input())
	g = ["%d"%(i) for i in range(N)]
	p = raw_input().split()
	eq = 0
	for i in range(len(g)):
		if (g[i] == p[i]):
			eq+=1
	if (eq >= N/2):
		print "Case #%d: BAD"%(t+1)
	else:
		print "Case #%d: GOOD"%(t+1)