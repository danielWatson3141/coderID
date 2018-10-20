#!/usr/bin/env python
# -*- coding:utf-8 -*-
#
# Problem A. Charging Chaos
# https://code.google.com/codejam/contest/2984486/dashboard#s=p0
#

import sys
import itertools


def solve(outlets, require):
    L = len(outlets[0])
    outlets = [int(outlet, 2) for outlet in outlets]
    require = set(int(x, 2) for x in require)
    for count in range(L + 1):
        for switch in itertools.combinations(range(L), count):
            flip = int(''.join('01'[n in switch] for n in range(L)), 2)
            test = set(outlet ^ flip for outlet in outlets)
            if test == require:
                return count
    return 'NOT POSSIBLE'


def main(IN, OUT):
    T = int(IN.readline())
    for index in range(T):
        N, L = IN.readline().split()
        outlets = IN.readline().split()
        require = IN.readline().split()
        OUT.write('Case #%d: %s\n' % (index + 1, solve(outlets, require)))


def makesample(Nmax=10, Lmin=2, Lmax=10, T=100):
    import random

    print T
    for index in range(T):
        N = random.randint(1, Nmax)
        L = random.randint(Lmin, Lmax)
        print N, L
        print ' '.join(('0' * L + format(random.randint(1, 2 ** L), 'b'))[-L:] for i in range(N))
        print ' '.join(('0' * L + format(random.randint(1, 2 ** L), 'b'))[-L:] for i in range(N))


if __name__ == '__main__':
    if '-makesample' in sys.argv[1:]:
        makesample()
    else:
        main(sys.stdin, sys.stdout)

