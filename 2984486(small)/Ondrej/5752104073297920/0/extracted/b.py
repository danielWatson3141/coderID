from random import randrange
from numpy import empty, array, average, arange, fromstring

def reconstruct(a):
    r = []
    b = [0]*N
    for k in range(N):
        b[k] = k
    for k in range(N):
        p = b.index(a[k])
        r.append(p)
        b[k], b[p] = b[p], b[k]
    return r

f = open("small.in")
T = int(f.readline())
assert T == 120
for i in range(T):
    N = int(f.readline())
    assert N == 1000
    a = fromstring(f.readline(), sep=" ", dtype="int")
    r = reconstruct(a)
    Xx = arange(N/2-0.5, N, 0.5)[:-1]
    if sum(r > Xx) < 480:
        print "Case #%d: BAD" % (i+1)
    else:
        print "Case #%d: GOOD" % (i+1)
