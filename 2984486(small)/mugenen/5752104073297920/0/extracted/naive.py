import sys
import collections
import random

T = int(raw_input())
for t in xrange(1, T + 1):
    raw_input()
    a = map(int, raw_input().split())
    count = 0
    for i in xrange(len(a)):
        if i + 1 == a[i]:
            count += 1
    if count >= 400:
        print "Case #{0}: {1}".format(t, 'GOOD')
    else:
        print "Case #{0}: {1}".format(t, ['BAD', 'GOOD'][random.randint(0, 1)])
