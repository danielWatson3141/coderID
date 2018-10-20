import pickle
import sys
import math
with open("data") as fh:
    z= pickle.load(fh)

with open(sys.argv[1]) as fh:
    T = int(fh.readline())
    badlogl = []
    goodlogl = []
    for i in range(T):
        N = int(fh.readline())
        p = map(int, fh.readline().split(" "))
        badlogl.append(sum([z[i][x] for i, x in enumerate(p)]))
        goodlogl.append(-N*math.log(N))

bad = set(sorted(range(T), key=lambda k: badlogl[k], reverse=True)[:11])
for i in range(T):
    if i in bad:
        print "Case #{0}: BAD".format(i+1)
    else:
        print "Case #{0}: GOOD".format(i+1)
