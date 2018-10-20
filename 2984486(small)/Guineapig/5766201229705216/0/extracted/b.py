
def costs_(N, edges, node, parent):
	nbs = edges[node]
	css = sorted([costs(N, edges, nb, node) for nb in nbs if nb != parent])
	ncs = len(css)
	if ncs == 0:
		return (0, 1)
	cost_to_delete = sum(cs[1] for cs in css)
	if len(css) == 1:
		return (cost_to_delete, cost_to_delete + 1)
	costs_to_fix = []
	for i1 in range(ncs):
		for i2 in range(i1+1, ncs):
			costs_to_fix.append(cost_to_delete - css[i1][1] - css[i2][1] + css[i1][0] + css[i2][0])
	return min(costs_to_fix), cost_to_delete + 1


cache = {}

def costs(N, edges, node, parent):
	key = (node, parent)
	# if cache.has_key(key):
	# 	return cache[key]
	res = costs_(N, edges, node, parent)
	# print parent, ' -> ', node, ' = ', res
	cache[key] = res
	return res


def solve(N, edges):
	cache = {}
	# print edges
	costs_per_root = [costs(N, edges, r, -1) for r in range(N)]
	# print (costs_per_root)
	return min([cf for cf, cd in costs_per_root])
	


################################################################################


def read_ints(f):
	return [int(w) for w in f.readline().strip().split()]

def read_int(f):
	return int(f.readline().strip())


from sys import argv

f = open(argv[1])

T = read_int(f);

for t in range(1, T+1):
	N = read_int(f)
	edges = [[] for _ in range(N)]
	for _ in range(N-1):
		n1, n2 = read_ints(f)
		edges[n1-1].append(n2-1)
		edges[n2-1].append(n1-1)
	for i in range(N):
		edges[i].sort()
	res = solve(N, edges)
	print 'Case #%s: %s' % (t, res)
