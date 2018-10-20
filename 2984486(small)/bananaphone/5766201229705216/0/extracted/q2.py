def myfun((a,b), (c,d)):
	return (a-b)-(c-d)

def dfs(G, s, N):
	visited = range(N+1)
	keepcut = range(N+1)
	nodesbelow = range(N+1)

	def visit(node):
		visited[node] = 0
		keepcut[node] = 0
		nodesbelow[node] = 1
		cutlist = []
		for child in G[node]:
			if visited[child] != 0:
				visit(child)
				nodesbelow[node] += nodesbelow[child]
				cutlist.append((keepcut[child], nodesbelow[child]))
		if len(cutlist) < 2:
			keepcut[node] = nodesbelow[node]-1
		else:
			cutlist.sort(cmp = myfun)
			count = 0
			for k in xrange(len(cutlist)):
				if k in [0,1]:
					count += cutlist[k][0]
				else:
					count += cutlist[k][1]
			keepcut[node] = count
#		print node, cutlist
	visit(s)
#	for k in range(N):
#		print k+1, nodesbelow[k+1], keepcut[k+1]
	return keepcut[s]


T = int(raw_input())
for i in xrange(T):
	N = int(raw_input())
	G = {}
	for node in xrange(N):
		G[node+1] = []
	for j in xrange(N-1):
		xy = raw_input()
		(x,y) = xy.split()
		G[int(x)].append(int(y))
		G[int(y)].append(int(x))
	print "Case #" + str(i+1) + ": " + str(min([dfs(G, q, N) for q in range(1, N+1)]))


