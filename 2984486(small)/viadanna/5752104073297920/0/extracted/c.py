for t in xrange(int(raw_input())):
    N = int(raw_input())
    badness = [1 for i, n in enumerate(raw_input().split())
        if int(n) == i]
    print "Case #%d: %s" % (t+1, "GOOD" if len(badness) == 0 else "BAD")