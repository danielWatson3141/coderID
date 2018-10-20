from collections import Counter

for T in xrange(int(raw_input())):
    N, L = map(int, raw_input().split())
    outlets = sorted([int(i, 2) for i in raw_input().split()])
    devices = sorted([int(j, 2) for j in raw_input().split()])
    if outlets == devices:
        print "Case #%d: 0" % (T+1)
        continue
    r = L+1
    for i in xrange(1, 2 ** L - 1):
        if sorted([ou ^ i for ou in outlets]) == devices:
            n = Counter(bin(i))["1"]
            r = min((r, n))
    print "Case #%d: %s" % (T+1, str(r) if r <= L else "NOT POSSIBLE")