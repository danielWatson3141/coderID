#/usr/local/bin/python

import sys
import math

T = int(sys.stdin.readline())

for caseno in xrange(T):
    N, L = [int(x) for x in sys.stdin.readline().split()]
    outlets = sorted([int(x, 2) for x in sys.stdin.readline().split()])
    devices  = sorted([int(x, 2) for x in sys.stdin.readline().split()])

    #print [bin(z) for z in outlets]
    #print [bin(z) for z in devices]

    ans = L + 1
    for x in xrange(2 ** L):
        o = outlets[:]
        o = sorted([xx ^ x for xx in o])
        #print bin(x), [bin(z) for z in o]
           
        if o == devices:
            ans = min(ans, bin(x).count("1"))
        
    if ans == L + 1:
        ans = "NOT POSSIBLE"
    
    print "Case #%d: %s" % (caseno + 1, ans)

