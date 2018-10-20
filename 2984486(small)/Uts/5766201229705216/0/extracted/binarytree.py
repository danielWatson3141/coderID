import networkx as nx
import sys
def trial():
	N = int(raw_input())
	G = nx.Graph()
	for i in range(N-1):
		edge = [int(j) for j in raw_input().split()]
		G.add_edge(edge[0], edge[1])
	p = nx.shortest_path(G)
	d = 0
	for i in range(1, N+1):
		for j in range(1, i):
			if len(p[i][j])-1 > d:
				isBinary = True
				hasRoot = False
				for v in p[i][j][1:-1]:
					if G.degree(v) == 2:
						if hasRoot:
							isBinary = False
							break
						else:
							hasRoot = True
				if isBinary:
					d = len(p[i][j]) - 1
	if d == 1:
		return N - 2
	return N - 2*d + 1


	hasRoot = False
	deletedNodes = 0
	for degree in degrees:
		if not hasRoot:
			if degree >= 2:
				deletedNodes+= degree-2
				hasRoot = True
		else:
			if degree == 2:
				deletedNodes += 1
			if degree > 3:
				deletedNodes += degree - 3
	return deletedNodes

T = int(raw_input())
for t in range(1,T+1):
	print "Case #%d:" % t,
	print trial()
