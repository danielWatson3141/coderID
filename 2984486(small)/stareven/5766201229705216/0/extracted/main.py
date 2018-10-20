import sys

def addEdge(edges, u, v):
    if u not in edges: edges[u] = [v]
    else: edges[u].append(v)

def ReadIn():
    cases = int(input().strip())
    for c in range(1, cases + 1):
        n = int(input().strip())
        edges = {}
        for i in range(n - 1):
            u, v = [int(x) for x in input().split()]
            addEdge(edges, u, v)
            addEdge(edges, v, u)
        yield c, edges

def countSon(v, p, edges, sons):
    sons[v] = 1
    for s in edges[v]:
        if s != p:
            sons[v] += countSon(s, v, edges, sons)
    return sons[v]

def asRoot(v, p, edges, sons):
    son = len(edges[v])
    if p in edges[v]: son -= 1
    if son == 0: return 0
    if son == 1:
        for s in edges[v]:
            if p != s:
                return sons[s]
    if son == 2:
        ret = 0
        for s in edges[v]:
            if p != s:
                ret += asRoot(s, v, edges, sons)
        return ret
    cuts = {}
    for s in edges[v]:
        if p != s:
            cuts[s] = asRoot(s, v, edges, sons)
    ret = len(edges)
    for x in edges[v]:
        if x != p:
            for y in edges[v]:
                if y != p and y != x:
                    tmp = cuts[x] + cuts[y]
                    for z in edges[v]:
                        if z != p and z != x and z != y:
                            tmp += sons[z]
                    ret = min(ret, tmp)
    return ret

def Solve(edges):
    ret = len(edges)
    for root in edges:
        sons = {}
        countSon(root, -1, edges, sons)
        ret = min(ret, asRoot(root, -1, edges, sons))
    return ret

if __name__ == '__main__':
    for case, edges in ReadIn():
        print('Case #%d: %d' % (case, Solve(edges)))