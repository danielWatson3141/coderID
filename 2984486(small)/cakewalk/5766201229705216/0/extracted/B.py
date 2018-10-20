from sys import stdin
readline = stdin.readline

T = int(readline())
for t in xrange(1, T+1):
	N = int(readline())
	AdjList = [[] for i in xrange(N)]
	Edges = []
	for i in xrange(N-1):
		x, y = map(int, readline().strip().split())
		AdjList[x-1].append(y-1)
		AdjList[y-1].append(x-1)
#		Edges.append[(min(x,y),max(x,y))]
#	Parent = [None for i in xrange(N)]
#	Children = [[] for i in xrange(N)]
#	WeightBelow = [[0]*N for i in xrange(N)]
#	toVisit = [0]
#	Visited = []
#	while toVisit != []:
#		visiting = toVisit.pop()
#		Visited.append(visiting)
#		for i in AdjList[visiting]:
#			if i != Parent[visiting]:
#				toVisit.append(i)
#				Children[visiting].append(i)
#				Parent[i] = visiting
#	
#	for i in xrange(N-1, -1, -1):
#		for j in Children[Visited[i]]:
#			WeightBelow[Visited[i]] += (WeightBelow[j]+1)
#	
#	EdgeWeight = [[[None]]*N for i in xrange(N)]
#	
#	for x in Edges:
#		if Parent[x[0]] != x[1]:
#			x[1],x[0] = x[0],x[1]
#		EdgeWeight[x[1]][x[0]] = WeightBelow[x[0]] + 1
#		EdgeWeight[x[0]][x[1]] = N - EdgeWeight[x[1]][x[0]]
#	
	ans = N-1
	for root in xrange(N):
		Parent = [None for i in xrange(N)]
		Children = [[] for i in xrange(N)]
		AnsBelow = [[None]*N for i in xrange(N)]
		WeightBelow = [[None]*N for i in xrange(N)]
		toVisit = [root]
		Visited = []
		while toVisit != []:
			visiting = toVisit.pop()
			Visited.append(visiting)
			for i in AdjList[visiting]:
				if i != Parent[visiting]:
					toVisit.append(i)
					Children[visiting].append(i)
					Parent[i] = visiting
		for i in xrange(N-1, -1, -1):
			WeightBelow[Visited[i]] = 0
			for j in Children[Visited[i]]:
				WeightBelow[Visited[i]] += (WeightBelow[j]+1)
			
			l = len(Children[Visited[i]])
			if l == 0:
				AnsBelow[Visited[i]] = 0
			if l == 2:
				tmp = AnsBelow[Children[Visited[i]][0]] + AnsBelow[Children[Visited[i]][1]]
				AnsBelow[Visited[i]] = min(WeightBelow[Visited[i]], tmp)
			if l == 1:
				AnsBelow[Visited[i]] = WeightBelow[Visited[i]]
			if l > 2:
				tmp = [WeightBelow[k]+1-AnsBelow[k] for k in Children[Visited[i]]]
				tmp.sort()
				AnsBelow[Visited[i]] = WeightBelow[Visited[i]] - tmp[-1] - tmp[-2]
		ans = min(AnsBelow[root], ans)
	
	print 'Case #%d: %d' % (t, ans)
				
