#!/usr/bin/python

import sys

T = int(sys.stdin.readline())

for c in xrange(0,T):
# for c,line in enumerate(sys.stdin):
    print 'Case #{}:'.format(c+1),    
    
    N = int(sys.stdin.readline().strip())
    
    n = map(int, sys.stdin.readline().strip().split())
    
    counter = 0
    
    maxx = sum( [i*i for i in xrange(N)] )
    
    # print >>sys.stderr, maxx, (1-0.109)*maxx,[i+i for i in xrange(N)] 
    
    for cc, nc in enumerate(n):
        counter += cc*nc
        # if cc == nc:
        #     counter += N-cc
            
    print >>sys.stderr, counter
    
    # if counter > 300:
    #     print 'BAD'
    # else:
    #     print 'GOOD'
    
    # Choosen empirically %)
    if counter >= (1-0.2420)*maxx:
        print 'BAD'
    else:
        print 'GOOD'
