#! /usr/bin/env python2

T = int(raw_input())

for t in xrange(1, T + 1):
    n, l = tuple(int(x) for x in raw_input().split())
    a, b = list(int(x, 2) for x in raw_input().split()), set(int(x, 2) for x in raw_input().split())
    B = set(b)
    best = -1
    for pattern in xrange(1 << l):
        A = set(a[i] ^ pattern for i in xrange(n))
        if A == B:
            current = sum(1 if pattern & (1 << j) != 0 else 0 for j in xrange(l))
            if best == -1 or best > current:
                best = current
    print "Case #{}: {}".format(t, "NOT POSSIBLE" if best == -1 else best)
