import sys
import copy
from itertools import combinations

def build_tree(edges):
	tree =  {}
	for edge in edges:
		if edge[0] not in tree:
			tree[edge[0]] = set()
		if edge[1] not in tree:
			tree[edge[1]] = set()
		
		tree[edge[0]].add(edge[1])
		tree[edge[1]].add(edge[0])
	return tree
def count_childs(tree, root):
	
	s = 0
	tree_copy = copy.deepcopy(tree)
	orig_tree, tree = tree, tree_copy
	
	s += len(tree[root])
	for node in tree[root]:
		tree[node].remove(root)
		s += count_childs(tree, node)
	#print 'count_childs (root=%d) -> %d' % (root, s)
	return s

def make_bin_tree(tree, root):
	if len(tree[root]) == 0:
		# already a binary tree
		return 0
	
	# copy tree, so we can safely remove edges later and restore them easily
	tree_copy = copy.deepcopy(tree)
	orig_tree, tree = tree, tree_copy
	
	nodes = list(tree[root])
	# detach childs from root
	for node in nodes:
		tree[root].remove(node)
		tree[node].remove(root)
	
	#print 'root (%d) childs: %d' % (root, len(nodes))
	if len(nodes) == 1:
		# need to remove child + its' childs
		return 1 + count_childs(tree, nodes[0])
	else:
		# try every 2 childs
		nodes_child_count = [count_childs(tree, node) for node in nodes]
		min_found = len(tree)
		for node1_i, node2_i in combinations(range(len(nodes)), 2):
			node1 = nodes[node1_i]
			node2 = nodes[node2_i]
			
			x = make_bin_tree(tree, node1)
			#print 'min_removes = %d (node=%d)' % (x, node1)
			min_removes = x
			
			x = make_bin_tree(tree, node2)
			min_removes += x
			#print 'min_removes += %d (node=%d)' % (x, node2)
			
			x = sum([(nodes_child_count[i]+1) for i in range(len(nodes)) if i not in (node1_i, node2_i)])
			min_removes += x
			#print 'min_removes += %d (childs %s of node %d except childs %d, %d)' % (x, nodes, root, node1, node2)
			
			#print 'min_removes: %d, min_found: %d' % (min_removes, min_found)
			if min_removes < min_found:
				min_found = min_removes

		return min_found
def get_min(edges):
	tree = build_tree(edges)
	min_found = len(tree)
	for node in tree:
		#print 'trying node %d (get_min)' % (node)
		root = node
		# make a binary tree
		min_removes = make_bin_tree(tree, root)
		#print 'min_removes: %d, min_found: %d (get_min)' % (min_removes, min_found)
		if min_removes < min_found:
			min_found = min_removes
	return min_found

def main():
	T = int(sys.stdin.readline().strip())
	for i in range(T):
		N = int(raw_input())
		edges = [map(int, raw_input().split()) for j in range(N-1)]
		#print edges
		m = get_min(edges)
		print 'Case #%d: %d' % (i+1, m)

if __name__ == '__main__':
	main()
