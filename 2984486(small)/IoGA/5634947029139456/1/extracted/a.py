#!/usr/bin/python

import sys

def s_to_bits(s):
    def inner():
        for c in s:
            if c == '1':
                yield True
            elif c == '0':
                yield False
            else:
                raise ValueError
    return list(inner())

def read_case(f):
    N, L = map(int, f.readline().strip().split())
    outlets = map(s_to_bits, f.readline().strip().split())
    devices = map(s_to_bits, f.readline().strip().split())
    assert(len(outlets) == len(devices) == N)
    assert(len(outlets[0]) == L)
    return outlets, devices


def count_ith(ll, i):
    return sum(l[i] for l in ll)

NOT_POSSIBLE = "NOT POSSIBLE"

def solve(outlets, devices):
    L = len(outlets[0])
    N = len(outlets)

    flips = {tuple(): {i: range(N) for i in range(N)}}

    for i in range(L):
        o_count_true = count_ith(outlets, i)
        devices_count_true = count_ith(devices, i)

        if o_count_true != devices_count_true and o_count_true != N - devices_count_true:
            return NOT_POSSIBLE

        new_flips = {}

        if o_count_true == devices_count_true:
            # No bitflip is needed here.
            for k, v in flips.iteritems():
                nk = list(k)
                nk.append(False)
                nv = {oi: [di for di in dis if devices[di][i] == outlets[oi][i]] for (oi, dis) in v.iteritems()}
                if all(len(nvv) > 0 for nvv in nv.values()):
                    new_flips[tuple(nk)] = nv

        if o_count_true == N - devices_count_true:
            # Then we need a bitflip.
            for k, v in flips.iteritems():
                nk = list(k)
                nk.append(True)
                nv = {oi: [di for di in dis if devices[di][i] != outlets[oi][i]] for (oi, dis) in v.iteritems()}
                if all(len(nvv) > 0 for nvv in nv.values()):
                    new_flips[tuple(nk)] = nv

        flips = new_flips
        if len(flips) == 0:
            return NOT_POSSIBLE

    return min(sum(flip_config) for flip_config in flips)

def main(filename):
    with open(filename) as f:
        for case_num in range(int(f.readline())):
            result = solve(*read_case(f))
            print 'Case #{}: {}'.format(case_num + 1, result)

if __name__ == "__main__":
    main(sys.argv[1])
