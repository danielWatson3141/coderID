#!/usr/bin/python
import sys, collections

data = file(sys.argv[1]).read().splitlines()

T = int(data.pop(0))

def valid(switch,dev):
    for d in dev:
        match = 0
        for si in xrange(0,len(switch)):
            if d == switch[si]:
                match = 1
                break
        if match == 0:
            return False
    return True
            

def brute(switch,dev):
    min = 44
    d = dev[0]
    for si in xrange(0,len(switch)):
        curswitch = list(switch)
        v = switch[si] ^ d
        numbits = 0
        for i in xrange(0,41):
            if v & (1 << i):
                numbits = numbits + 1
                for ss in xrange(0,len(switch)):
                    curswitch[ss] = curswitch[ss] ^ (1 << i)
        if valid(curswitch,dev):
            if numbits < min:
                min = numbits
    return min

                        

for numcase in xrange(1,T+1):
    print 'Case #%d:' % numcase,
    (N, L) = [int(x) for x in data.pop(0).split()]
#    print N, L
    switch = [int(x,2) for x  in data.pop(0).split()]
    dev = [int(x,2) for x in data.pop(0).split()]
#    print switch
#    print dev
    v = brute(switch,dev)
    if v == 44:
        print 'NOT POSSIBLE'
    else:
        print v


    

    

