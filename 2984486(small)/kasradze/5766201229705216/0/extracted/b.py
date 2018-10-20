__author__ = 'Levan Kasradze'

from collections import deque

fin = open('b.in')
fout = open('b.out', 'w')
T = int(fin.readline())
for t in range(1, T + 1):
    fout.write('Case #' + str(t) + ': ')
    n = int(fin.readline())
    g = [[] for i in range(n+1)]
    degree = [0 for i in range(n+1)]
    for i in range(n-1):
        line = fin.readline().strip().split()
        u = int(line[0])
        v = int(line[1])
        g[u].append(v)
        g[v].append(u)
        degree[u] += 1
        degree[v] += 1

    cnt = n-1
    for i in range(1, n+1):
        if degree[i] > 1:
            visited = [False for j in range(n+1)]
            t1 = 0
            q = deque([i])
            while len(q) > 0:
                u = q.popleft()
                visited[u] = True
                c = []
                for v in g[u]:
                    if not visited[v]:
                        c.append(v)

                if len(c) == 1 or len(c) > 2:
                    subtree = []
                    for j in c:
                        t2 = 0
                        qq = deque([j])
                        while len(qq) > 0:
                            t2 += 1
                            uu = qq.popleft()
                            visited[uu] = True
                            for vv in g[uu]:
                                if not visited[vv]:
                                    qq.append(vv)
                        subtree.append(t2)

                    if len(c) == 1:
                        t1 += subtree[0]
                    else:
                        subtree.sort()
                        for j in range(2, len(subtree)):
                            t1 += subtree[j]
                elif len(c) == 2:
                    q.extend(c)
            cnt = min(cnt, t1)

    fout.write(str(cnt) + '\n')
fin.close()
fout.close()
