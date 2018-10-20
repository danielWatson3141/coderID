def root_tree (root, G, boss=-1, rooted=None):
	#print ("Root tree - ", root, boss)
	if rooted is None:
		rooted = [list() for x in range(len(G))]

	rooted[root] = [i for i in G[root] if i!=boss]
	
	for i in rooted[root]:
		root_tree(i, G, root, rooted)

	return rooted

def get_size (x, tree):
	if tree[x] == []: return 1
	return sum([get_size(i, tree) for i in tree[x]]) + 1

def get_min_remove (x, tree):
	size = len(tree[x])

	if size == 0: return 0
	if size == 1: return get_size(tree[x][0], tree)
	if size == 2: return get_min_remove(tree[x][0], tree) + get_min_remove(tree[x][1], tree)
	if size >  2: 
		rem = sum(sorted([get_size(i, tree) - get_min_remove(i, tree) for i in tree[x]], reverse=True)[:2])
		count = sum([get_size(i, tree) for i in tree[x]])

		return count - rem

# G = [
# [1],
# [0, 2, 3, 4],
# [1],
# [1],
# [1, 6],
# [6],
# [5, 4, 7],
# [6]
# ]

# G = [
# [1, 2],
# [0, 3],
# [0, 6],
# [1, 4, 5],
# [3],
# [3],
# [2]
# ]

# G = [
# [1, 2, 3, 4],
# [0, 5, 6],
# [7, 8, 0],
# [9, 10, 0],
# [15, 0],
# [11, 12, 1],
# [1],
# [2],
# [2],
# [3, 13, 14],
# [3], 
# [5],
# [5],
# [9],
# [9],
# [4]
# ]



# N = len(G)


T = int(input())
# T = 1
for case in range (T):
	N = int(input())
	
	G = [list() for x in range (N)]
	for i in range (N-1):
		x, y = [int(x) for x in input().strip().split()]
	
		G[x-1] += [y-1]
		G[y-1] += [x-1]

	m = 999999999999999999999
	for root in range(N):
		tree = root_tree(root, G)
		m = min(get_min_remove(root, tree), m)
		
		# print (*tree, sep="\n")
		# print ()
		# print (get_min_remove(root, tree))

	print ("Case #{}: {}".format(case+1, m))