#!/usr/bin/env python3
# coding: utf-8

from copy import deepcopy

INF = 10000

def conv(tmp):
    ret = [[0 for i in range(L)] for j in range(N)]

    for i in range(N):
        for j in range(L):
            ret[i][j] = int(tmp[i][j])

    return ret

def solve():
    s = 0
    ans = INF

    LB.sort()

    for t in range(N):
        l = deepcopy(LA)
        cnt = 0

        for i in range(L):
            if l[s][i] != LB[t][i]:
                for j in range(N):
                    l[j][i] = 1 - l[j][i]
                cnt += 1

        l.sort()

        if l == LB:
            ans = min(ans, cnt)

    return ans if ans != INF else 'NOT POSSIBLE'

for case in range(int(input())):
    N, L = map(int, input().split(' '))
    A = list(input().split(' '))
    B = list(input().split(' '))
    LA = conv(A)
    LB = conv(B)
    print('Case #{}: {}'.format(case + 1, solve()))
