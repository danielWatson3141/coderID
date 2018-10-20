#!/usr/bin/env python

from sys import stdin

tt = stdin.readline()

tt = eval(tt)

res = {}

score = []

for cc in range(1, tt + 1):
    n = eval(stdin.readline())
    tmp = stdin.readline()
    tmp = tmp.split()
    for i in range(0, n):
        tmp[i] = eval(tmp[i])
    val = 0
    for i in range(0, n):
        val += tmp[i] * (n - i)
    score.append((val, cc))

score = sorted(score)

for i in range(0, 70):
    res[score[i][1]] = 'GOOD'

for i in range(1, tt + 1):
    if i in res:
        print "Case #%d: GOOD" % (i)
    else:
        print "Case #%d: BAD" % (i)
