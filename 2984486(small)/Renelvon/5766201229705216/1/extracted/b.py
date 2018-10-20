import collections

def solve(N, edges):
    G = buildgraph(N, edges)
    return min(solveaux(N, G, i) for i in range(1, N + 1))

def solveaux(N, G, i):
    bfslist = []
    curlist = [i]
    nextlist = []
    while curlist:
        for n in curlist:
            nextlist.extend(G[n])
        bfslist.extend(curlist)
        curlist = list(set(nextlist) - set(bfslist))
        nextlist.clear()

    mark = [False for n in range(N + 1)]
    score = [None for n in range(N + 1)]
    size = [0 for n in range(N + 1)]

    bfslist.reverse()
    for u in bfslist:
        mark[u] = True
        childs = [v for v in G[u] if mark[v]]
        sizes = [size[v] for v in childs]
        size[u] = sum(sizes) + 1

        childscores = [score[v] for v in childs]

        if len(childscores) == 0:
            score[u] = 0
        elif len(childscores) == 1:
            score[u] = size[childs[0]]
        elif len(childscores) == 2:
            score[u] = sum(childscores)
        else:
            mix_scores = [(size[v] - score[v], v) for v in childs]
            mix_scores.sort(reverse=True)
            cur = 0
            for s, v in mix_scores[2:]:
                cur += size[v]
            cur += score[mix_scores[0][1]] + score[mix_scores[1][1]]
            score[u] = cur

    return score[i]

def buildgraph(N, edges):
    G = collections.defaultdict(list)
    for u, v in edges:
        G[u].append(v)
        G[v].append(u)
    return G

def main():
    T = int(input())
    edges = []
    for i in range(1, T + 1):
        N = int(input())
        edges.clear()
        for k in range(N - 1):
            u, v = [int(s) for s in input().strip().split()]
            edges.append((u, v))
        res = solve(N, edges)
        print('Case #', i, ': ', res, sep='')

if __name__ == "__main__":
    main()
