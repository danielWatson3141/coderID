import sys
from collections import defaultdict

infile = sys.stdin
#infile = open('input')

case_num = int(infile.readline())

def check(outlet, device):
    L = len(outlet)
    assert len(outlet) == len(device)
    ret = list()
    for i in xrange(L):
        if outlet[i] != device[i]:
            ret.append(i)
    return tuple(ret)

def solve(N, L, outlet, device):
    # print N, L
    # print outlet
    # print device
    switches = [None] * (L + 1)
    for i in xrange(L+1):
        switches[i] = defaultdict(int)
    for out in outlet:
        for dev in device:
            switch = check(out, dev)
            switches[len(switch)][switch] += 1

    for l in xrange(L+1):
        for s in switches[l]:
            if switches[l][s] == N:
                #print s, len(s), l
                return l

    return 'NOT POSSIBLE'

for case in xrange(case_num):
    N, L = [int(v) for v in infile.readline().split()]
    outlet = infile.readline().split()
    device = infile.readline().split()
    print "Case #%d: %s" % (case + 1, str(solve(N, L, outlet, device)))
