# -*- coding: utf-8 -*-

import copy


def bitcount(n):
    return bin(n).count('1')


T = int(raw_input())
for test_case in xrange(1, T + 1):
    N, L = map(int, raw_input().split())
    F = [int(x, 2) for x in raw_input().split()]
    D = [int(x, 2) for x in raw_input().split()]
    assert all(0 <= x < 2 ** L for x in F)
    assert all(0 <= x < 2 ** L for x in D)

    best = L + 1
    for i in xrange(2 ** L):
        flows = [x ^ i for x in F]
        if all(x in flows for x in D):
            best = min(best, bitcount(i))

    answer = 'NOT POSSIBLE' if L < best else best
    print 'Case #{}: {}'.format(test_case, answer)
