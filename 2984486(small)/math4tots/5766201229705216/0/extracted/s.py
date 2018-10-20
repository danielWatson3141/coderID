from sys import setrecursionlimit
setrecursionlimit(10000)

class Node(object):
	def __init__(self,i):
		self.i = i
		self.neighbors = []
	
	def __repr__(self):
		return str(self.i)

def solve(root):
	for n in nodes:
		n.visited = False
	ret = N - rec(root)
	return ret

def rec(node):
	node.visited = True
	children = tuple(n for n in node.neighbors if not n.visited)
	return 1 if len(children) < 2 else (1+sum(tuple(sorted(map(rec,children)))[-2:]))
	
T = int(input())
for t in range(1,T+1):
	N = int(input())
	nodes = [Node(i) for i in range(N)]
	
	for _ in range(N-1):
		X, Y = map(int,input().split())
		nodes[X-1].neighbors.append(nodes[Y-1])
		nodes[Y-1].neighbors.append(nodes[X-1])
	
	print('Case #%d: %d' % (t,min(solve(root) for root in nodes)))
