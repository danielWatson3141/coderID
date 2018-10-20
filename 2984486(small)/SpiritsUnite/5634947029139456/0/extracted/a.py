t = int(raw_input().strip())


for c in xrange(t):
    ans = 100000
    n, l = map(int, raw_input().strip().split())

    inp = raw_input().strip().split()
    out = sorted(raw_input().strip().split(), key=lambda x: int(x, 2))

    for i in xrange(2**l - 1):
        ninp = sorted([bin(int(j, 2) ^ i)[2:].zfill(l) for j in inp], key=lambda x: int(x, 2))
        if out == ninp:
            ans = min(ans, bin(i).count('1'))

    print "Case #%d:" % (c + 1),
    if ans == 100000:
        print "NOT POSSIBLE"
    else:
        print ans

