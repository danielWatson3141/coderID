import sys
from collections import defaultdict
sys.setrecursionlimit(1200)

def dfs(G, v, prev):
    t = []
    s = 0
    for x in G[v]:
        if x == prev: continue
        tmp = dfs(G, x, v)
        s += tmp[1]
        t.append(tmp[0] - tmp[1])
        t.sort()
        t = t[:2]
    if len(t) < 2:
        return (s, s+1)
    return (s + t[0] + t[1], s+1)

def solve():
    read_ints = lambda: map(int, sys.stdin.readline().split())
    n = int(sys.stdin.readline())
    G = defaultdict(list)
    for _ in xrange(n-1):
        x, y = read_ints()
        x, y = x-1, y-1
        G[x].append(y)
        G[y].append(x)
    return min(dfs(G, i, -1)[0] for i in xrange(n))

for t in xrange(int(sys.stdin.readline())):
    print "Case #%d:" % (t + 1),
    print solve()
