#!/usr/bin/env python
from itertools import combinations
import sys


def problem(j, fi):
    fi.readline()
    outlets = set([s for s in fi.readline().strip().split(' ')])
    devices = set([s for s in fi.readline().strip().split(' ')])
    return outlets, devices


def switch(outlets, bits):
    new_outlets = set()
    for o in outlets:
        chars = list(o)
        for b in bits:
            chars[b] = '0' if chars[b] == '1' else '1'
        new_outlets.add(''.join(chars))
    return new_outlets


def solve(params, fo, i):
    outlets, devices = params

    l = len(outlets.__iter__().next())

    for i in xrange(0, l + 1):
        for comb in combinations(range(l), i):
            if switch(outlets, comb) == devices:
                return i

    return 'NOT POSSIBLE'

if __name__ == '__main__':
    with open(sys.argv[1]) as fi, open(sys.argv[2], 'w') as fo:
        total = int(fi.readline().strip())
        for i in range(total):
            res = solve(problem(i, fi), fo, i)
            fo.write('Case #{0}: {1}\n'.format(i + 1, res))
            fo.flush()
