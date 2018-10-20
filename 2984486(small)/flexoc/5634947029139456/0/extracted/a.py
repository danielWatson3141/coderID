from collections import deque
T = input()
def flip(l,n):
	c = []
	for i in xrange(len(l)):
		j = l[i]
		c.append(list(j))
		if c[i][n] == "1":
			c[i][n] = "0"
		else:
			c[i][n] = "1"
	return sorted(c)
def s(l):
	return "".join("".join(c) for c in l)
class Node:
	def __init__(self,l,i):
		self.l = l
		self.i = i
for t in xrange(T):
	N, L = [int(_) for _ in raw_input().split()]
	flow = sorted([list(c) for c in raw_input().split()])
	charge = sorted([list(c) for c in raw_input().split()])
	# print flow, charge
	visited, queue = set(), deque([Node(flow,0)])
	while queue:
		v = queue.popleft()
		o = s(v.l)
		# print v.l
		if o not in visited:
			visited.add(o)
			if v.l == charge:
				print "Case #%d: %d" % (t+1,v.i)
				break
			for i in xrange(L):
				k = flip(v.l,i)
				if s(k) not in visited:
					queue.append(Node(k,v.i+1))
	else:
		print "Case #%d: NOT POSSIBLE" % (t+1)
    # return visited
