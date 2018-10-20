T = input()


seen = {}
def dfs(i, top=True):
	global seen
	if top:
		seen = {}
	if i not in seen:
		seen[i] = 1
		return 1 + sum(dfs(j,top=False) for j in adj[i] if j not in seen and j not in rseen)
	return 0
	
rseen = set()
def root(i):
	global adj, rseen
	rseen.add(i)
	ch = [j for j in adj[i] if j not in rseen]
	if len(ch) == 0:
		return 0
	if len(ch) == 1:
		return dfs(i) - 1
	if len(ch) >= 2:
		sizes = {}
		prunes = {}
		for j in ch:
			sizes[j] = dfs(j)
		for j in ch:
			prunes[j] = root(j)
		metrics = [(sizes[j] - prunes[j], j) for j in ch]
		metrics = sorted(metrics)[::-1]
		a, b = metrics[0][1], metrics[1][1]
		s = prunes[a] + prunes[b] + sum(sizes[j] for j in ch if j not in [a, b])
		# print i, sizes, prunes, metrics
		return s



for case in range(1, T + 1):
	# print "	====NEW CASE===="
	N = input()
	adj = [[] for i in range(N)]
	for i in range(N - 1):
		a, b = map(int, raw_input().split())
		a -= 1
		b -= 1
		adj[a].append(b)
		adj[b].append(a)
	rseen = set()
	l = N - 1
	for i in range(N):
		# print '+++', i, '+++'
		rseen = set()
		
		l = min(l, root(i))
		# print 'root', i, l
	print 'Case #%d:' % case, l