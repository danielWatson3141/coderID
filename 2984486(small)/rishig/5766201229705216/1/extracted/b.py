import sys
sys.path.insert(0, '/home/rishig/codejam/')
from library import *
sys.setrecursionlimit(10000)
from collections import defaultdict

def solvecase(case):
    N = readint(ff)
    E = [readints(ff) for i in range(N-1)]
    A = defaultdict(set)
    for i,j in E:
        A[i].add(j)
        A[j].add(i)

    w = {}
    def weight(i,j):
        if (i,j) in w:
            return w[(i,j)]
        w[(i,j)] = 1 + sum(weight(j,k) for k in A[j] if k != i)
        return w[(i,j)]
    f = {}
    def fix(i,j):
        if (i,j) in f:
            return f[(i,j)]
        if (len(A[j]) < 3 and i >=0) or (len(A[j]) < 2):
            return sum(weight(j,k) for k in A[j] if k != i)
        saves = [weight(j,k)-fix(j,k) for k in A[j] if k != i]
        saves.sort()
        assert len(saves) >= 2
        f[(i,j)] = weight(i,j) -1 - saves[-1] - saves[-2]
        return f[(i,j)]

    m = min(fix(-1,i) for i in A)
    return m


if __name__ == '__main__':
    ff = file(sys.argv[1])
    T = readint(ff)
    for case in range(1,T+1):
        ans = solvecase(case)
        print 'Case #%d: %s' % (case, ans)
