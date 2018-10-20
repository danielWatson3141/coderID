#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
"""

impossiburu = "NOT POSSIBLE"
opposite = {'0': '1', '1': '0'}

def count_digit(flows, pos):
    zeroes = 0
    ones = 0
    for flow in flows:
        if flow[pos] == '0':
            zeroes += 1
        else:
            ones += 1
    return [zeroes, ones]

def feasable(flows, devices):
    for i in range(len(flows[0])):
        if min(count_digit(flows, i)) != min(count_digit(devices, i)):
            return False
    return True

def fill_dic(flows, i):
    dic = {}
    for flow in flows:
        f = flow[:i+1]
        dic[f] = dic.get(f, 0) + 1
    return dic

def match_so_far(flows, devices, i):
    f = fill_dic(flows, i)
    d = fill_dic(devices, i)
    return f == d

def immut_flip(flows, i):
    n = [x[:i] + opposite[x[i]] + x[i+1:] for x in flows]
    return n

def flipping(flows, devices, L, flipped, step):
    if step == L:
        if match_so_far(flows, devices, step-1):
            return flipped
        else:
            return impossiburu
    i = step

    f_zeroes, f_ones = count_digit(flows, i)
    d_zeroes, d_ones = count_digit(devices, i)
    if f_zeroes != d_zeroes:
        new_flows = immut_flip(flows, i)
        if not match_so_far(new_flows, devices, i):
            return impossiburu
        return flipping(new_flows, devices, L, flipped+1, i+1)
    elif f_zeroes != f_ones:
        if not match_so_far(flows, devices, i):
            return impossiburu
        return flipping(flows, devices, L, flipped, i+1)
    else:
        ret = flipping(flows, devices, L, flipped, i+1)
        new_flows = immut_flip(flows, i)
        ret2 = flipping(new_flows, devices, L, flipped+1, i+1)
        return min(ret, ret2)

def solve(flows, devices):
    L = len(flows[0])
    if not feasable(flows, devices):
        return impossiburu
    ret = flipping(flows, devices, L, 0, 0)
    return ret

def main():
    T = int(raw_input())
    for i in range(1, T + 1):
        NL = raw_input()
        flows = raw_input().split()
        devices = raw_input().split()
        res = solve(flows, devices)
        print "Case #{}: {}".format(i, res)

def test():
    pass

if __name__ == '__main__':
    # test()
    main()
