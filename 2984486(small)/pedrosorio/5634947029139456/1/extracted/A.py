from collections import Counter

T = int(raw_input())

vals = {'0': 0, '1': 1}

for test in xrange(1,T+1):
	N, L = map(int,raw_input().split())
	outstr = raw_input().split()
	devstr = raw_input().split()
	outlets = [[vals[outstr[i][j]] for j in xrange(L)] for i in xrange(N)]
	devices = [[vals[devstr[i][j]] for j in xrange(L)] for i in xrange(N)]
	devcts = [sum([devices[i][j] for i in xrange(N)]) for j in xrange(L)]
	outpf = [[0 for j in xrange(N)] for i in xrange(L+1)]
	devpf = [[0 for j in xrange(N)] for i in xrange(L+1)]
	devcounters = [0 for i in xrange(L+1)]
	for i in xrange(1,L+1):
		for j in xrange(N):
			devpf[i][j] = devices[j][i-1] * 2**(i-1) + devpf[i-1][j]
		devcounters[i] = Counter(devpf[i])
	outcounters = [0 for i in xrange(L+1)]
	numflips = 0
	minflips = L+1
	whereflips = [0 for i in xrange(L+1)]
	i = 1
	while i > 0:
		if i == L+1:
			minflips = min(minflips, numflips)
			i -= 1
			continue
		#if test == 14:
		#	print i, whereflips[i]
		if whereflips[i] == 0:
			whereflips[i] = 1
			for j in xrange(N):
				outpf[i][j] = outlets[j][i-1] * 2**(i-1) + outpf[i-1][j]
			outcounters[i] = Counter(outpf[i])
			if (outcounters[i] == devcounters[i]):
				i += 1
			continue
		if whereflips[i] == 1:
			whereflips[i] = 2
			numflips += 1
			for j in xrange(N):
				outpf[i][j] = (1 - outlets[j][i-1]) * 2**(i-1) + outpf[i-1][j]
			outcounters[i] = Counter(outpf[i])
			if (outcounters[i] == devcounters[i]):
				i += 1
			continue
		if whereflips[i] == 2:
			whereflips[i] = 0
			numflips -= 1
			i -= 1
	if minflips == L+1:
		res = "NOT POSSIBLE"
	else:
		res = str(minflips)
	print "Case #" + str(test) + ": " + res
	#print ''.join(whereflips)