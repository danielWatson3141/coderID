

def traverse(g, u):
	global p, desc
	children = 0
	last_child = -1
	for v in g[u]:
		if v != p[u]:
			p[v] = u
			children += 1
			last_child = v
			traverse(g, v)
	# children traversed
	if children >= 2:
		rank = [(desc[v], v) for v in g[u] if v != p[u]]
		rank.sort()
		desc[u] += desc[rank[-1][1]] + desc[rank[-2][1]]

t = input()
for k in xrange(t):
	n = input()
	g = [[] for _ in xrange(n)]
	for _ in xrange(n - 1):
		x, y  = [int(z) for z in raw_input().split()]
		x -= 1
		y -= 1
		g[x].append(y)
		g[y].append(x)
	m = n + 1
	for root in xrange(n):
		global p, desc
		p = [-1 for _ in xrange(n)]
		desc = [1 for _ in xrange(n)]
		p[root] = root
		traverse(g, root)
		m = min(m, n - desc[root])
	print 'Case #{0}: {1}'.format(k + 1, m)
