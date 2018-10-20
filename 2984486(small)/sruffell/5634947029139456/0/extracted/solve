#!/usr/bin/env python
# vim: set filetype=python et sw=4 ts=4:

import sys
import collections

T = int(sys.stdin.readline())


def build_sorted_list(L):
    numbers = []
    for x in xrange(1,1<<L):
        numbers.append((x, collections.Counter([x for x in bin(x)])['1']))
    return sorted(numbers, key=lambda y: y[1])

sorted_numbers = build_sorted_list(10)

def try_bit(outlets, devices, mask):
    newoutlets = [(x ^ mask) for x in outlets]
    newoutlets.sort()
    if devices == newoutlets:
        return True
    else:
        return False

for case in xrange(T):
    N, L = [int(x) for x in sys.stdin.readline().split()]
    outlets = [int(x, base=2) for x in sys.stdin.readline().split()]
    devices = [int(x, base=2) for x in sys.stdin.readline().split()]
    outlets.sort()
    devices.sort()
    if outlets == devices:
        sys.stdout.write("Case #%d: 0\n" % (case + 1))
    else:
        found = False
        collections.Counter
        for x in (x[0] for x in sorted_numbers):
            if try_bit(outlets, devices, x):
                sys.stdout.write("Case #%d: %d\n" % (case + 1, collections.Counter([x for x in bin(x)])['1']))
                found = True
                break

        if not found:
                sys.stdout.write("Case #%d: NOT POSSIBLE\n" % (case + 1))
        
