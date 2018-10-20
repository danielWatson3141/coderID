import sys
from collections import defaultdict

def enc(astr):
    return int(astr, base=2)

def bit_count(n):
    count = 0
    while n > 0:
        count += 1
        n = n & (n - 1)
    return count

f = open(sys.argv[1])
T = int(f.readline())
for t in xrange(1,T+1):
    n, l = map(int, f.readline().strip().split())
    outlets = map(enc, f.readline().strip().split())
    devices = map(enc, f.readline().strip().split())

    masks = defaultdict(int)
    for o in outlets:
        for d in devices:
            masks[o ^ d] += 1

    res = [m for m, c in masks.iteritems() if c == n]
    if res:
        res = min(bit_count(m) for m in res)
    else:
        res = "NOT POSSIBLE"

    print "Case #{0}: {1}".format(t, res)
