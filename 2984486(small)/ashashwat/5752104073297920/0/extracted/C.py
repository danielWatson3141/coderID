#!/usr/bin/env python
#-*- coding: utf-8 -*-

from collections import defaultdict
from math import factorial as f
from random import random, randint

def algo1 (l):
    for k in range (len (l)):
        p = randint (k, len (l) - 1)
        l [k], l [p] = l [p], l [k]
    return "".join (str (i) for i in l)

def algo2 (l):
    for k in range (len (l)):
        p = randint (0, len (l) - 1)
        l [k], l [p] = l [p], l [k]
    return "".join (str (i) for i in l)

d = {}
def solve (l):
    for i in range (10):
        l1 = algo1 (l)
        l2 = algo2 (l)
        d [l1] = d.get (l1, 0) + 1
        d [l2] = d.get (l2, 0) - 1

T = int (raw_input ())
for t in range (1, T + 1):
    N = int (raw_input ())
    l = [int (i) for i in raw_input ().split ()]
    solve (l)
    s = "".join (str (i) for i in l)
    if (d.get (s, 0) >= 0): print "Case #{0}: BAD".format (t)
    else: print "Case #{0}: GOOD".format (t)

#print d
#print l1, l2




