import sys
sys.path.insert(0, '/home/rishig/codejam/')
from library import *

anss = []

def solvecase(case):
    N = readint(f)
    A = readints(f)
    sumsss = sum(i*A[i] for i in range(N))
    anss.append(sumsss)
    return

    if sum(i*A[i] for i in range(N)) > 251856278:
        return 'BAD'
    return 'GOOD'

if __name__ == '__main__':
    f = file(sys.argv[1])
    T = readint(f)
    for case in range(1,T+1):
        ans = solvecase(case)
        # print 'Case #%d: %s' % (case, ans)

    aanss = anss[:]
    aanss.sort()
    mid = aanss[60]-1
    ans = []
    for a in anss:
        if a > mid:
            ans.append('BAD')
        else:
            ans.append('GOOD')
    for case in range(1,T+1):
        print 'Case #%d: %s' % (case, ans[case-1])

