import sys
import itertools

def solve(c):
    print 'Case #%d:' % c,
    N, L = [int(i) for i in sys.stdin.readline().split()]
    ini = sorted([list(s) for s in sys.stdin.readline().split()])
    req = sorted([list(s) for s in sys.stdin.readline().split()])

    if ini == req:
        print 0
        return

    for i in xrange(L):
        for seq in itertools.combinations(xrange(L), i+1):
            n = []
            for s in ini:
                s1 = list(s)
                for p in seq:
                    s1[p] = '0' if s1[p] == '1' else '1'
                n.append(s1)
            if sorted(n) == req:
                print i+1
                return
    print 'NOT POSSIBLE'



N = int(sys.stdin.readline())
for c in xrange(1, N+1):
    solve(c)
