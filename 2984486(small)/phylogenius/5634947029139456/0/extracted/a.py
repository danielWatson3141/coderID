import sys
from fractions import Fraction
from itertools import product
INF = float('inf')
T = int(sys.stdin.readline()[:-1])
counts = []
for t in xrange(T):
    N, L = map(int, sys.stdin.readline()[:-1].split())
    initial = map(lambda x: map(int, x), sys.stdin.readline()[:-1].split())
    required = map(lambda x: map(int, x), sys.stdin.readline()[:-1].split())
    count = 0
    forks = []
    for i in xrange(L):
        f_i = Fraction([x[i] for x in initial].count(1), N)
        f_r = Fraction([x[i] for x in required].count(1), N)
        if f_i == f_r:
            if f_i == 0.5:
                forks.append(i)
        elif f_i == 1 - f_r:
            for x in initial: x[i] = 1 - x[i]
            count += 1
        else:
            break
    required.sort()
    scores = []
    for p in product([0, 1], repeat=len(forks)):
        copy = [list(x) for x in initial]
        for x,i in zip(p,forks):
            if x == 1:
                for x in copy: x[i] = 1 - x[i]
        copy.sort()
        if required == copy:
            scores.append(count + p.count(1))
        else:
            scores.append(INF)
    minval = min(scores)
    if minval == INF:
        count = 'NOT POSSIBLE'
    else:
        count = minval
    print 'Case #{}: {}'.format(t+1, count)
    counts.append(count)
