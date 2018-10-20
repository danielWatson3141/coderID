import sys, itertools, collections
sys.setrecursionlimit(10000)

read_ints = lambda: map(int, raw_input().split())
read_int  = input

def gao(root_node, from_node, adj):
    cand = []
    for to_node in adj[root_node]:
        if to_node == from_node:
            continue
        cand.append(gao(to_node, root_node, adj))

    cand.sort(reverse=True)
    if len(cand) >= 2:
        return 1 + cand[0] + cand[1]
    return 1

for no_t in xrange(1, read_int() + 1):
    n = read_int()
    adj = collections.defaultdict(list)
    for _ in xrange(n - 1):
        x, y = read_ints()
        adj[x].append(y)
        adj[y].append(x)

    best = max(gao(root_node, -1, adj) for root_node in adj.keys())
    ans = n - best
    print 'Case #%d: %s' % (no_t, ans)
