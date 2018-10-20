import sys


def deleteCount(v, E, V):
    V[v] = 1
    count = 1
    for child in E[v]:
        if not V[child]:
            count += deleteCount(child, E, V)
    return count


def solve2(v, E, V):
    V[v] = 1
    childrenCount = len(E[v])
    isRoot = not any([V[_] for _ in E[v]])
    if not isRoot:
        childrenCount -= 1
    if childrenCount == 0:
        return 0, 1
    elif childrenCount == 1:
        child = E[v][0]
        child = child if not V[child] else E[v][1]
        deletes = deleteCount(child, E, V)
        return deletes, deletes + 1
    counts = []
    for child in E[v]:
        if not V[child]:
            counts.append(solve2(child, E, V))
    deletes = 0
    for m, d in counts:
        deletes += d
    best = deletes
    for k in range(len(counts)):
        for l in range(len(counts)):
            if k == l: continue
            m0, d0 = counts[k]
            m1, d1 = counts[l]
            cur = deletes - d0 + m0 - d1 + m1
            best = min(best, cur)

    return best, deletes + 1


def solve(f):
    N = int(f.readline())
    E = []
    for i in range(N+1):
        E.append([])
    for i in range(N-1):
        x, y = [int(_) for _ in f.readline().split()]
        E[x].append(y)
        E[y].append(x)
    best = N
    for i in range(1, N+1):
        cur, deletes = solve2(i, E, [0]*(N+1))
        best = min(best, cur)
    return best


def main(f):
    T = int(f.readline())
    for t in range(1, T+1):
        result = solve(f)
        print("Case #%d: %d" % (t, result))

if __name__ == '__main__':
    main(open(sys.argv[1]) if len(sys.argv) > 1 else sys.stdin)
