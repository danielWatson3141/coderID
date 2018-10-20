class Node:
	def __init__(self, value):
		self.value = value
		self.children = []

	def addSubtree(self, subtree):
		self.children.append(subtree)

	def size(self):
		return 1 + sum([x.size() for x in self.children])

	def __repr__(self):
		return str(self.value) + ': ' + str(self.children)

def makeTree(root, edges):
	tree = Node(root)

	for e in edges:
		if root in e:
			newEdges = list(edges)
			newEdges.remove(e)
			tree.addSubtree(makeTree(e[1 if e[0] == root else 0], newEdges))

	return tree

def fullBinaryTree(nodes, edges):
	minNodes = nodes
	#pick a root
	for root in range(1, nodes + 1):
		tree = makeTree(root, edges)
		minNodes = min(minNodes, helper(tree))
	return minNodes

def helper(tree):
	x = len(tree.children)

	if x == 0:
		return 0
	if x == 1:
		return tree.size() - 1
	if x == 2:
		return helper(tree.children[0]) + helper(tree.children[1])
	
	minNodes = tree.size()
	memo = {}

	for child in tree.children:
		memo[child] = helper(child)

	for child1 in tree.children:
		for child2 in tree.children:
			if child1 == child2:
				continue

			minNodes = min(minNodes, memo[child1] + memo[child2] + tree.size() - child1.size() - child2.size() - 1)

	return minNodes


from sys import stdin

input = stdin.read().split('\n')
line = 0

for t in range(int(input[0])):
	line += 1
	N = int(input[line])
	aList = {}
	edges = []

	for n in range(N - 1):
		line += 1
		x, y = input[line].split()
		edges.append((int(x), int(y)))

	print "Case #{0}: {1}".format(t+1, fullBinaryTree(N, edges))