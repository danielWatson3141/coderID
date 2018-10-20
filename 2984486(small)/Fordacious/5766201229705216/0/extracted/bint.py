class node ():
	def __init__ (self):
		self.edges = [];
		self.degree = 0;

def getint ():
	return int(raw_input())

def printCase(c, s):
	print "Case #" + str(c) + ": " + str(s)

def goDownNode (node, camefrom):
	t = 1
	if node.degree == 3:
		if node.edges[0] != camefrom:
			t += goDownNode(node.edges[0], node)
		if node.edges[1] != camefrom:
			t += goDownNode(node.edges[1], node)
		if node.edges[2] != camefrom:
			t += goDownNode(node.edges[2], node)
	return t

def traverse (node):
	return 1 + goDownNode(node.edges[0], node) + goDownNode(node.edges[1], node)

for i in range(getint()):
	numnodes = getint();
	nodes = dict()
	nodesl = []
	possibleroots = []
	for j in range(numnodes - 1):
		edge = map(int,raw_input().split(' '));
		n1 = None
		n2 = None
		if edge[0] not in nodes:
			nodes[edge[0]] = node()
			nodesl.append(nodes[edge[0]])
		if edge[1] not in nodes:
			nodes[edge[1]] = node()
			nodesl.append(nodes[edge[1]])
		n1 = nodes[edge[0]]
		n2 = nodes[edge[1]]
		n1.edges.append(n2)
		n2.edges.append(n1)
		n1.degree += 1
		n2.degree += 1

	for j in nodesl:
		if j.degree == 2:
			possibleroots.append(j)

	mincut = 0
	for j in possibleroots:
		cutforroot = traverse(j)
		mincut = max(cutforroot,mincut)

	printCase(i + 1, len(nodesl) - mincut)