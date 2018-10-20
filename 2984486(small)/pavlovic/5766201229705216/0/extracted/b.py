import sys

def subtree_size(root, children):
	res = 1
	for child in children[root]:
		res += subtree_size(child, children)
	return res

def solve(root, children):
	if len(children[root]) == 0:
		return 0
	if len(children[root]) == 1:
		return subtree_size(children[root][0], children)
	if len(children[root]) == 2:
		return solve(children[root][0], children) + solve(children[root][1], children)

	child1_index = 0
	child2_index = 1
	min_res = -1
	while True:
		child1 = children[root][child1_index]
		child2 = children[root][child2_index]
		
		res = subtree_size(root, children) - subtree_size(child1, children) - subtree_size(child2, children) - 1 + solve(child1, children) + solve(child2, children)
		
		if (min_res == -1) or (res < min_res):
			min_res = res
			
		child2_index += 1
		if child2_index >= len(children[root]):
			child1_index += 1
			child2_index = child1_index + 1
			
		if child2_index >= len(children[root]):
			break
			
	return min_res
	
t = int(sys.stdin.readline().strip())

for i in range(t):
	print "Case #" + str(i + 1) + ":",

	n = int(sys.stdin.readline().strip())

	edges = []
	for i in range(n - 1):
		x, y = sys.stdin.readline().strip().split()
		edges.append([int(x) - 1, int(y) - 1])
		
	min_res = -1
	for root in range(n):
		children = []
		for j in range(n):
			children.append([])
			
		processed_nodes = set()
		processing_nodes = set([root])
		while len(processing_nodes) > 0:
			processing_node = processing_nodes.pop()

			for edge in edges:
				if (edge[0] == processing_node) and (edge[1] not in processed_nodes):
					children[processing_node].append(edge[1])
					processing_nodes.add(edge[1])
					
				if (edge[1] == processing_node) and (edge[0] not in processed_nodes):
					children[processing_node].append(edge[0])
					processing_nodes.add(edge[0])
					
			processed_nodes.add(processing_node)
	
		res = solve(root, children)
		if (min_res == -1) or (res < min_res):
			min_res = res

	print min_res		
