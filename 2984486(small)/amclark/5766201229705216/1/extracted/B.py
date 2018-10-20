import sys

def rl():
    return sys.stdin.readline().strip()

def levels(g, n, p=None):
    if (p is None and len(g[n]) < 2) or (p is not None and len(g[n]) <= 2):
        return 1
    x = []
    for n2 in g[n]:
        if n2 != p:
            x.append(levels(g, n2, n))
    x.sort()
    return 1 + x[-1] + x[-2]

def main():
    T = int(rl())
    for c in range(1, T+1):
        N = int(rl())
        g = {}
        for i in range(N-1):
            a, b = map(int, rl().split())
            g.setdefault(a, []).append(b)
            g.setdefault(b, []).append(a)
        nodes = max(levels(g, n) for n in g)
        print 'Case #%d: %d' % (c, N - nodes)

if __name__ == '__main__':
    main()
