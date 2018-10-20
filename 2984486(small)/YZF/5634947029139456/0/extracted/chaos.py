def solveit():
    N, L = [int(x) for x in f.readline().split()]

    outlets = [int(x, 2) for x in f.readline().split()]
    devices = set([int(x, 2) for x in f.readline().split()])
    minswitches = L+1
    for i in xrange(0, 2**L-1):
        newoutlets = set([x ^ i for x in outlets])
        if newoutlets==devices:
            minswitches = min(bin(i).count("1"), minswitches)

    if minswitches == L + 1:
        return "NOT POSSIBLE"
    return minswitches

outfile = open("results.txt", "w")
with open("test.txt") as f:
    testcases = int(f.readline())

    for i in xrange(0, testcases):
        outcome = solveit()
        # print "Case #%d:" % (i + 1,), outcome
        print >> outfile, "Case #%d:" % (i + 1,), outcome
