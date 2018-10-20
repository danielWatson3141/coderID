#!/usr/bin/env python

import sys, os, re
import collections
import itertools

#---------------------------------------------------
# Variable 
#---------------------------------------------------

#---------------------------------------------------
# Function 
#---------------------------------------------------
def all_masks(L):
    vlist = [ (1<<i) for i in range(L)]
    for bit in range(1,L+1):
        for v in itertools.combinations(vlist, bit):
            yield sum(v), bit

def test_power (switch, power, L, N):
    if switch == power:
        return 0

    if sorted(switch.values()) != sorted(power.values()):
        return None

    for msk,bit in all_masks(L):
        switch1 = {}
        for k,v in switch.items():
            switch1[k^msk] = v 
        if switch1 == power:
            return bit
    return None

def load_file(filename):
    dict = {'X':'X won', 'O': 'O won', None:'Game has not completed', 'D':'Draw'}
    with open(filename, 'rU') as f:
        number = int(f.readline())
        for n in range(number):
            N, L = [ int(s) for s in f.readline().strip().split(' ')[:2]]
            switch = [ int(s,2) for s in f.readline().strip().split(' ')[:N]]
            power  = [ int(s,2) for s in f.readline().strip().split(' ')[:N]]
            switch = collections.Counter(switch)
            power  = collections.Counter(power)

            result = test_power(switch, power, L, N)

            if result == None:
                print "Case #%d: NOT POSSIBLE" % (n+1)
            else:
                print "Case #%d: %d" % (n+1, result)
    return

#---------------------------------------------------
# Entry Point 
#---------------------------------------------------
def main():
    load_file (sys.argv[1])

    return

#---------------------------------------------------
# Unit Test Entry 
#---------------------------------------------------
if __name__ == '__main__':
    main()


