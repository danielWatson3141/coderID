def dfs(x):
	global parent,child
	visit[x] = True
	size[x] = 1
	for i in edge[x]:
		if(not visit[i]):
			child[x].append(i)
			parent[i] = x
			dfs(i)
			size[x] += size[i]

def solve(x):
	global parent,child,size
	if(len(child[x]) == 0):
		return 0
	if(len(child[x]) == 1):
		tmp = size[child[x][0]]
		child[x] = []
		return tmp
	if(len(child[x]) == 2):
		return (solve(child[x][0]) + solve(child[x][1]))
	ret = 0
	ch_del = []
	if(len(child[x]) > 2):
		for i in child[x]:
			ch_del.append((size[i],i))
			ch_del.sort()
		for ch in range(len(ch_del)-2):
			ret += ch_del[ch][0]
			child[x].remove(ch_del[ch][1])
			#print ch_del,child[x],ch_del[ch][1]
	return (ret + (solve(child[x][0]) + solve(child[x][1])))

cc = int(raw_input().strip())

for ccc in range(1,cc+1):
	print 'Case #' + str(ccc) + ':',
	N = int(raw_input().strip())
	edge = {}
	visit = {}
	for i in range(N):
		edge[i+1] = []
	for i in range(N-1):
		a,b = raw_input().strip().split()
		a = int(a)
		b = int(b)
		edge[a].append(b)
		edge[b].append(a)
	ans = N
	for r in range(1,N+1):
		for i in range(N):
			visit[i+1] = False
		root = r
		parent = {}
		child = {}
		size = {}
		for i in range(N):
			child[i+1] = []
		parent[root] = root
		dfs(r)
		#print '####',
		#print child
		tt = solve(root)
		ans = min(ans,tt)
		#print '****',
		#print root,tt,ans
	print ans
