def max_nodes(edges, used, n, level):
    mnodes = 1
    for i in range(1, len(used)):
        if used[i]: continue
        if not edges[n][i]: continue
        used[i] = True
        nodes1 = max_nodes(edges, used, i, level + 1)
        for j in range(1, i):
            if used[j]: continue
            if not edges[n][j]: continue
            used[j] = True
            nodes2 = max_nodes(edges, used, j, level + 1) + 1
            used[j] = False
            if nodes1 + nodes2 > mnodes:
                mnodes = nodes1 + nodes2
        used[i] = False
    return mnodes

def main():
    T = int(raw_input())
    for i in range(T):
        N = int(raw_input())
        cnt = [0 for a in range(N+1)]
        edges = [ [False] * (N+1) for _ in range(N+1)]
        for j in range(N-1):
            (X, Y) = [int(x) for x in raw_input().split()]
            edges[X][Y] = True
            edges[Y][X] = True

        mnodes = 0
        used = [False for a in range(N+1)]
        for n in range(N):
            used[n+1] = True
            nodes = max_nodes(edges, used, n+1, 0)
            used[n+1] = False
            if nodes > mnodes:
                mnodes = nodes;
        print "Case #{0}: {1}".format(i + 1, N - mnodes)

if __name__ == '__main__':
    main()
