#!/usr/bin/env python

def guess(p, N):
    # N = 1000
    n = sum(i < p[i] < i + 200 for i in range(N))
    return 'BAD' if n > 200 else 'GOOD'

T = int(raw_input().strip())
for t in range(T):
    N = int(raw_input().strip())
    p = map(int, raw_input().strip().split())
    print 'Case #%d: %s' % (t+1, guess(p, N))
