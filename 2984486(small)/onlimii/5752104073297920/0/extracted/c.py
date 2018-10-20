#!/usr/bin/env python
#import time
#import random
#
#def good(n):
#    a = range(1, n+1)
#    for i in xrange(n):
#        p = random.randint(i, n-1)
#        a[i], a[p] = a[p], a[i]
#    return tuple(a)
#
#def bad(n):
#    a = range(1, n+1)
#    for i in xrange(n):
#        p = random.randint(0, n-1)
#        a[i], a[p] = a[p], a[i]
#    return tuple(a)
#
#def judge():
#    good_sample = {}
#    for i in xrange(10000):
#        b = bad(4);
#        if b not in good_sample:
#            good_sample[b] = 0
#        else:
#            good_sample[b] = good_sample[b]+1
#    for k in good_sample.keys():
#        good_sample[k] = good_sample[k] / 10000.0 * 100
#    print good_sample.items()
#
#judge()

with open("C-small-attempt5.in", "r") as fin:
    N = int(fin.readline())
    fout = open("C-small-attempt5.out", "w")
    total = 0
    for i in xrange(N):
        dt = 0
        l = int(fin.readline())
        a = map(int, fin.readline().split())
        for q,n in enumerate(a):
            dt = dt + abs(q-n)
        print dt
        total += dt
        if (dt >= 326000):
            fout.write("Case #"+str(i+1)+": GOOD\n")
        else:
            fout.write("Case #"+str(i+1)+": BAD\n")
    print total / 120.0
fin.close()
fout.close()