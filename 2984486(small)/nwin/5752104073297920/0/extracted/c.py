T = int(raw_input())
d = []
for t in xrange(T):
    n = int(raw_input())
    a = map(int, raw_input().split())
    s = 0
    for i in xrange(n):
        if a[i] > 850:
            s += i
    d.append((s, t))
d.sort()
ans = [False] * T
for t in xrange(T/2):
    ans[d[t][1]] = True
for t in xrange(T):
    print "Case #%d:" % (t+1),
    print "GOOD" if ans[t] else "BAD"
