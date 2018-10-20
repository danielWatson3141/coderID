
# def dfs(s, G):
#     print '=' * 40
#     q = [s]
#     v = set()
#     # adj = G.get(s, [])
#     # if len(adj) in (0, 2):
#     #     q.append(s)
#     # r = 0
#     while len(q):
#         u = q.pop()
#         if u in v:
#             continue
#         print u
#         v.add(u)
#         adj = [x for x in G.get(u, []) if x not in v]
#         if len(adj) in (0, 2):
#             q.extend(adj)
#     
#     return len(v)

def sol(n, G):
    V = set()

    def bfs(u):
        V.add(u)
        r = []
        adj = [x for x in G.get(u, []) if x not in V]
        # print u, adj
        if len(adj) < 2:
            return 1
        for v in adj:
            r.append(bfs(v))
        r.sort(reverse=True)
        return 1 + r[0] + r[1]

    r = 1000000
    for i in xrange(n):
        # print "=" * 40
        V.clear()
        r = min(r, n - bfs(i))
    return r
    

import sys
readline = sys.stdin.readline

line = readline()
tn = int(line)
for i in xrange(1, tn + 1):
    line = readline()
    n = int(line)
    G = {}
    for j in xrange(n - 1):
        line = readline()
        u, v = map(int, line.split(" "))
        G.setdefault(u - 1, []).append(v - 1)
        G.setdefault(v - 1, []).append(u - 1)
    print 'Case #{}: {}'.format(i, sol(n, G))
