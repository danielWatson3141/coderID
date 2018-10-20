def solve():
    n, L = map(int, raw_input().split())
    outlet = [int(x, 2) for x in raw_input().split()]
    dev = [int(x, 2) for x in raw_input().split()]
    ans = L + 10
    for x in outlet:
        xs = set(t ^ x for t in outlet)
        for i in xrange(n):
            y = dev[i]
            ys = set(t ^ y for t in dev)
            if xs == ys:
                ans = min(ans, bin(x ^ y).count('1'))
    if ans > L:
        return "NOT POSSIBLE"
    else:
        return ans

for t in xrange(int(raw_input())):
    print "Case #%d:" % (t + 1),
    print solve()
