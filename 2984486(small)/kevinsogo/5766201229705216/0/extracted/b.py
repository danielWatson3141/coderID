
class Tree(object):
	def __init__(self, i):
		self.i = i
		self.sons = []
		super(Tree, self).__init__()

	def size(self):
		return sum(s.size() for s in self.sons) + 1

	def ans(self):
		if len(self.sons) in [0,2]:
			return sum(s.ans() for s in self.sons)
		if len(self.sons) == 1:
			return self.sons[0].size()
		size = sum(s.size() for s in self.sons)
		anses = sorted(s.size() - s.ans() for s in self.sons)
		return size - sum(anses[-2:])

	def __str__(self):
		return "{%s: %s}" % (self.i, self.sons)

	__repr__ = __str__

def rootat(i):
	vis[i] = 1
	t = Tree(i)
	for j in adj[i]:
		if not vis[j]:
			t.sons.append(rootat(j))
	return t

for cas in xrange(1,input()+1):
	n = input()
	adj = [[] for i in xrange(n)]
	vis = [0]*n
	for i in xrange(n-1):
		x, y = map(int, raw_input().strip().split())
		x -= 1
		y -= 1
		adj[x].append(y)
		adj[y].append(x)
	l = n-1
	for i in xrange(n):
		for j in xrange(n):
			vis[j] = 0
		t = rootat(i)
		m = t.ans()
		#print i, t, m
		if l > m:
			l = m
	print "Case #%s: %s" % (cas, l)

