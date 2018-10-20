import sys

def count(edges, root, parent):
    childs = []
    for n in edges[root]:
        if n == parent:
            continue
        childs.append(count(edges, n, root))
    childs.sort(reverse=True)
    if len(childs) >= 2:
        return 1 + sum(childs[0:2])
    return 1

def fullBinaryTree(N, edges):
    ret = 100000
    for i in range(N):
        c = count(edges, i, None)
        ret = min(ret, N - c)
    return ret

if __name__ == "__main__":
    sys.setrecursionlimit(1500)
    T = input()
    for c in range(1, T + 1):
        N = int(raw_input())
        edges = [[] for i in range(N)]
        for i in range(N - 1):
            [s, e] = map(int, raw_input().split(" "))
            edges[s - 1].append(e - 1)
            edges[e - 1].append(s - 1)
        print 'Case #%d: %s' % (c, fullBinaryTree(N, edges))
