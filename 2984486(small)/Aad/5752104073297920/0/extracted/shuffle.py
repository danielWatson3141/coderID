
from itertools import *
import sys
import random

debug = True

def log(*argv):
    if debug:
        print " ".join(imap(str, argv))

def main(f, case):
    N = int(f.readline())
    t = map(int, f.readline().split())
    p = 0
    for i,v in enumerate(t):
        if v > i and v < i+100:
            p += 1
    if p > 130:
        print "Case #" + str(case) + ":", "BAD"
    else:
        print "Case #" + str(case) + ":", "GOOD"



with open(sys.argv[1]) as f:
    N = int(f.readline())
    for i in xrange(N):
        main(f, i+1)
