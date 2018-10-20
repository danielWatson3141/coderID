#!/usr/bin/env python

import itertools

def get_min_switch_flips(switches, devices, L):
    if switches == devices:
        return 0

    switch_board = [i for i in range(1, L + 1)]
    flips = []
    for i in range(1, L + 1):
        flips.extend(itertools.combinations(switch_board, i)) 

    for f in flips:
        new_config = set()
        for x in switches:
            nx = x
            for fn in f:
                if nx[fn - 1] == '1':
                    nx = nx[:fn - 1] + '0' + nx[fn:]
                else:
                    nx = nx[:fn - 1] + '1' + nx[fn:]
            new_config.add(nx)
        if new_config == devices:
            return len(f)
    return 'NOT POSSIBLE'

if __name__ == '__main__':
    tc = int(raw_input().strip())
    for i in range(tc):
        N, L = map(int, raw_input().split())
        switches = set(raw_input().split())
        devices = set(raw_input().split())
        print 'Case #%d: %s' % (i + 1, get_min_switch_flips(switches, devices, L)) 
