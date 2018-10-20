import sys
import numpy as np

def toint(x, l):
    b = np.array([ 2**i for i in range(l) ])
    c = np.array(x)
    return sum(c*b)

def bw(x):
    r = 0
    while x != 0:
        if x % 2 == 1:
            x, r = (x/2, r+1)
        else: 
            x = x/2
    return r


idata = [line for line in sys.stdin ]
T = int(idata[0].rstrip())
for t in range(T):
    N, L = [int(e) for e in idata[3*t+1].rstrip().split(' ')]
    o = [ [int(e) for e in x ] for x in idata[3*t+2].rstrip().split(' ')]
    d = [ [int(e) for e in x ] for x in idata[3*t+3].rstrip().split(' ')]
    min_bw = L+1
    possible = False

    oi = map(toint, o, [L]*N)
    dsi = sorted(map(toint, d, [L]*N))
    for g in range(2**L):
        osi = sorted([ e ^ g for e in oi ])
        if osi == dsi and bw(g) < min_bw:
            min_bw = bw(g)
            possible = True
        
    # print oi
    if possible:
        print 'Case #%d: %d' % (t+1, min_bw)
    else:
        print 'Case #%d: NOT POSSIBLE' % (t+1)
