import sys

def solve(x):
    def count_sizes(v, par):
        if len(g[v]) == 1 and g[v][0] == par:
            cs[v] = 1
            return 1
        tmp = 1
        for i in g[v]:
            if i != par:
                tmp += count_sizes(i, v)
        cs[v] = tmp
        return tmp

    def cost(v, par):
        sons = [u for u in g[v] if u != par]
        sons_sizes = sorted([(cs[u], u) for u in sons])
        tmp, k = 0, 0
        while not ((len(sons)-k) == 0 or (len(sons)-k == 2)):
            size, u = sons_sizes[k]
            tmp += size
            k += 1
        sons = [b for a, b in sons_sizes[k:]]
        if len(sons) == 2:
            tmp += cost(sons[0], v)
            tmp += cost(sons[1], v)
        return tmp

    N = int(raw_input())
    g = []
    cs = [0] * N
    for i in xrange(N):
        g.append([])
    for i in xrange(N-1):
        X, Y = (int(a) for a in raw_input().split(' '))
        g[X-1].append(Y-1)
        g[Y-1].append(X-1)
    mn = N
    for i in xrange(N):
        cs = [0] * N
        count_sizes(i, -1)
        tmp = cost(i, -1)
        if tmp < mn:
            mn = tmp
    print "Case #%d: %d" % (x, mn)

sys.setrecursionlimit(150000000)
T = int(raw_input())
for i in xrange(T):
    solve(i+1)
