import sys
stdin = sys.stdin

sys.setrecursionlimit(3000)

INF = 2147483647


def prune(root, parent, alist):
    children = [nei for nei in alist[root] if nei != parent]
    full_costs_and_partial = [prune(ch, root, alist) for ch in children]
    full_cost = sum([f for (f,p) in full_costs_and_partial]) + len(children)
    partial = full_cost
    if len(children) >= 2:
        costs = zip(full_costs_and_partial, children)
        costs.sort()
        costs.reverse()
        goodbye = costs[2:]
        partial = sum([fp[0] for fp,index in goodbye]) + len(goodbye) \
                + costs[0][0][1] \
                + costs[1][0][1]

    return (full_cost, partial)
    
    

T = int(stdin.readline())
for icase in range(T):
    N = int(stdin.readline())
    edges = []
    for i in range(N-1):
        edges.append(map(int, stdin.readline().strip().split()))

    alist = [[] for i in range(N)]
    for ed in edges:
        a, b = ed
        a -= 1
        b -= 1

        alist[a].append(b)
        alist[b].append(a)
    #if max([len(al) for al in alist]) <= 2:
    #    continue

    best = INF
    for root in range(N):
        full_partial = prune(root, -1, alist)
        cost = full_partial[1]
        #print root+1, cost
        best = min(best, cost)

    #print edges, best

    print "Case #%d:" % (icase+1), best
