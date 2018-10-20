L = 0; N = 0

def search(hamming, i, idx, ids, v):
	global L, N

	if (i == N-1 and hamming[i][idx] == v):
		return v
	else:
		if (hamming[i][idx] != v):
			return L+1
		
		ids.add(idx)
		t = L+1

		for idx1 in range(N):
			if (idx1 in ids): continue
			tt = search(hamming, i+1, idx1, ids, v)
			if (tt < t):
				t = tt

		ids.remove(idx)
		return t

with open('A-small-attempt1.in') as f:
	T = int(f.readline())

	for case in xrange(T):
		data = [int(x) for x in f.readline().split()]
		N = data[0]; L = data[1];

		o = [x for x in f.readline().split()]
		d = [x for x in f.readline().split()]

		hamming = [[0] * N for i in range(N)]

		for i in range(N):
			for j in range(N):
				for k in range(L):
					if (o[i][k] != d[j][k]):
						hamming[j][i] += 1

		T = L+1;

		for i in range(N):
			t = search(hamming, 0, i, set(), hamming[0][i])
			if t < T:
				T = t

		cando = (T <= L); switch = T

		if not cando:
			print "Case #%d: NOT POSSIBLE" % (case+1)
		else:
			print "Case #%d: %d" % (case+1, switch)
