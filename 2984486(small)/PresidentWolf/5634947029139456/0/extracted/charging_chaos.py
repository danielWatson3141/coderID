#! /usr/bin/python

import sys
import itertools

def test_flips(flip_seq, outlets):
    ret = list(outlets)
    for idx, flip in enumerate(flip_seq):
        if flip == '1':
            for idy, outlet in enumerate(ret):
                tmp = list(outlet)
                if outlet[idx] == '0':
                    tmp[idx] = '1'
                else:
                    tmp[idx] = '0'
                ret[idy] = ''.join(tmp)
    return ret

trials = int(sys.stdin.readline())

for rnd in range(trials):
    N, L = [ int(x) for x in sys.stdin.readline().split(" ") ]
    initial = sys.stdin.readline().strip().split(" ")
    shota = set(sys.stdin.readline().strip().split(" "))
    val = -1
    for flips in itertools.product("01", repeat=L):
        test = set(test_flips(flips, initial))

        if len(shota.difference(test)) == 0:
            val = flips.count('1')
            break
    if val == -1:
        print "Case #%d: NOT POSSIBLE" % (rnd + 1)
    else:
        print "Case #%d: %d" % ( rnd + 1, val)
