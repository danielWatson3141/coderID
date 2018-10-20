T = int(raw_input())
adj = []
nadj = []
contt = []
roott = []

def cont(p, n):
	global adj, nadj, contt
	if (contt[p][n] != -1): return contt[p][n]
	res = 0
	for i in adj[n]:
		if i == p: 
			continue
		res += cont(n, i)
	contt[p][n] = res+1
	return contt[p][n]

def root(p, n):
	global adj, nadj, roott
	if (roott[p][n] != -1): return roott[p][n]
	if (nadj[n] == 1): 
		roott[p][n] = 0
		return 0
	if (nadj[n] == 2):
		roott[p][n] = cont(n, adj[n][0]) if adj[n][0] != p else cont(n,adj[n][1])
		return roott[p][n]
	res = 0
	if (nadj[n] == 3):
		for i in adj[n]:
			if i == p: continue
			res += root(n, i)
		roott[p][n] = res
		return res
	r1=[]
	r2=[]
	s = 0
	t = 0
	m = 1000000
	for j in adj[n]:
		if j == p: continue
		t = cont(n,j)
		s += t
		r1.append(t)
		r2.append(root(n,j))
	for j in range(len(adj[n])-1):
		for k in range(len(adj[n])-1):
			if j == k: continue
			t = s-r1[j]-r1[k]+r2[j]+r2[k]
			m = min(m, t)
	roott[p][n] = m
	return m
	
	
line = raw_input()
for t in range(T):	
	N = int(line)
	adj = [[] for i in range(N)]
	nadj = [0 for i in range(N)]
	roott = [[-1 for i in range(N)] for i in range(N)]
	contt = [[-1 for i in range(N)] for i in range(N)]
	for i in range(N):
		try:
			line = raw_input().split()
		except (EOFError):
			break
		if (len(line) == 1):
			line = line[0]
			break
		a = int(line[0])-1
		b = int(line[1])-1
		adj[a].append(b)
		adj[b].append(a)
		nadj[a] += 1
		nadj[b] += 1
	res = [0 for i in range(N)]
	for i in range(N):
		if nadj[i] == 1:
			res[i] = N-1
		if nadj[i] == 2:
			res[i] += root(i, adj[i][0])
			res[i] += root(i, adj[i][1])
		if nadj[i] >= 3:
			r1=[]
			r2=[]
			s = 0
			te = 0
			m = 1000000
			for j in adj[i]:
				te = cont(i,j)
				s += te
				r1.append(te)
				r2.append(root(i,j))
			for j in range(len(adj[i])):
				for k in range(len(adj[i])):
					if j == k: continue
					te = s-r1[j]-r1[k]+r2[j]+r2[k]
					m = min(m, te)
			res[i] = m
		#print "%d %d  %d"%(i,nadj[i], res[i])
	res.sort()
	print "Case #%d: %d"%(t+1, res[0])	
		