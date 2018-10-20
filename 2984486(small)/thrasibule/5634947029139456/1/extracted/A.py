import sys
import pdb
with open(sys.argv[1]) as fh:
    T = int(fh.readline())
    for i in range(T):
        N, L = map(int, fh.readline().split(" "))
        a = [int(x,2) for x in fh.readline().split(" ")]
        b = [int(x,2) for x in fh.readline().split(" ")]
        a1 = set([x^a[0] for x in a[1:]])
        r = []
        for j in range(N):
            b1 = list(b)
            z = b1.pop(j)
            b1 = set([x^z for x in b1])
            if a1==b1:
                offset = a[0]^z
                r.append(bin(offset).count("1"))
        if r:
            print "Case #{0}: {1}".format(i+1, min(r))
        else:
            print "Case #{0}: {1}".format(i+1, "NOT POSSIBLE")
