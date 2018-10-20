N = 0

def prune(el, i, visited):
	global N

	t = 0;
	d = 0;
	visited.add(i)
	for j in range(N):
		if j not in visited and el[i][j]:
			d += 1

	if d == 0:
		visited.remove(i)
		return 0
	elif d == 2:
		t = 0
		for j in range(N):
			if j not in visited and el[i][j]:
				t += prune(el, j, visited)

		visited.remove(i)
		return t
	elif d == 1:
		for j in range(N):
			if j not in visited and el[i][j]:
				c = count(el, j, visited)
				break

		visited.remove(i)
		return c
	else:
		p = []
		c = []
		for j in range(N):
			if j not in visited and el[i][j]:
				c += [count(el, j, visited)]
				p += [prune(el, j, visited)]

		visited.remove(i)
		
		mii = N+1
		for j in range(len(p)-1):
			for k in range(j+1,len(p)):
				t = p[j]+p[k]
				for l in range(len(p)):
					if (l != j and l != k):
						t += c[l]
				if (t < mii):
					mii = t

		return mii


def count(el, i, visited):
	t = 1;
	visited.add(i)
	for j in range(N):
		if j not in visited and el[i][j]:
			t += count(el, j, visited)

	visited.remove(i)
	return t

with open('B-small-attempt0.in') as f:
	T = int(f.readline())

	for case in xrange(T):
		N = int(f.readline())
		el = [[0]*N for i in range(N)]

		for t in range(N-1):
			data = [int(x) for x in f.readline().split()]
			i = data[0]-1; j = data[1]-1
			el[i][j] = 1; el[j][i] = 1;

		T = N+1
		for i in range(N):
			t = prune(el, i, set());
			if (t < T):
				T = t

		print "Case #%d: %d" % (case+1, T)