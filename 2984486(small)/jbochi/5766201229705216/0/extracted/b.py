import sys
from collections import defaultdict

lines = [map(int, line.strip().split(' ')) for line in sys.stdin.readlines()]

T = lines[0][0]
i = 1

def todelete(N, nbs, root, visited):
    visited = visited.union([root])
    child = [d for d in nbs[root] if d not in visited]
    nchild = len(child)
    if nchild == 0:
        return 0
    elif nchild == 1:
        DESC = [desc(N, nbs, r, visited) for r in child]
        return sum(DESC)
    elif nchild == 2:
        TD = [todelete(N, nbs, r, visited) for r in child]
        return sum(TD)
    else:
        TD = [todelete(N, nbs, r, visited) for r in child]
        DESC = [desc(N, nbs, r, visited) for r in child]
        SAVE = sorted([(DESC[i] - TD[i], i) for i in range(nchild)])
        return sum(TD[i] for _, i in SAVE[-2:]) + sum(DESC[i] for _, i in SAVE[:-2])

def desc(N, nbs, root, visited):
    visited = visited.union([root])
    child = [d for d in nbs[root] if d not in visited]
    return 1 + sum([desc(N, nbs, r, visited) for r in child])

def solve(N, G):
    nbs = defaultdict(set)
    for i, j in G:
        nbs[i].add(j)
        nbs[j].add(i)

    dels = [todelete(N, nbs, root, frozenset()) for root in range(1, N + 1)]
    return min(dels)

for t in range(T):
    N = lines[i][0]
    G = lines[i + 1: i + N]
    i += N
    solution = solve(N, G)
    print "Case #%d: %s" % (t + 1, solution)
