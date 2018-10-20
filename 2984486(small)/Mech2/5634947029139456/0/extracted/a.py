#!/usr/bin/env python

import os, sys, math
from itertools import permutations

chunk = lambda ulist, step:  map(lambda i: ulist[i:i+step],  xrange(0, len(ulist), step))

def solve( N, L, outlets, devices ):
    outletsb = eval( "0b" + "".join(outlets) )

    #devicesb = set()
    #for x in permutations(devices):
    #    devicesb.add( eval( "0b" + "".join( x ) ) )
    devicesb = set(devices)

    switchp = int( math.pow( 2, L ) )
    switchp = [ bin(x)[2:].zfill(L) for x in range( switchp) ]

    minres = None
    for s in switchp:
        sp = eval( "0b" + ( s * N ) )
        res = outletsb ^ sp
        res = set( chunk(bin(res)[2:].zfill(N*L), L) )
        if res == devicesb:
            if minres == None:
                minres = s.count("1")
            else:
                minres = min( s.count("1"), minres )

    if minres != None:
        return minres

    return "NOT POSSIBLE"

fd = sys.stdin

line = fd.readline()
sets = int( line )+1

for case in range(1, sets):
    N, L = ( int( x ) for x in fd.readline().split() )
    outlets = [ x for x in fd.readline().split()]
    devices = [ x for x in fd.readline().split()]
    nline = solve( N, L, outlets, devices )
    print "Case #%s: %s" % (case, nline)

fd.close()
