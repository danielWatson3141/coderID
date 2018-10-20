#!/usr/bin/env python
# -*- coding: utf-8 -*-

from collections import Counter


def verify(n, l, outlet_states, devices, switch, si):
    if si == l:
        o = map(lambda o: ''.join(o), outlet_states)
        if set(o) == set(devices):
            return sum(switch)
        return None

    #print outlet_states
    s = switch[si]

    if s is False or s is None:
        switch[si] = False
        result = verify(n, l, outlet_states, devices, switch, si+1)
        if result is not None:
            return result

    if s is True or s is None:
        switch[si] = True
        for i in xrange(n):
            outlet_states[i][si] = '1' if outlet_states[i][si] == '0' else '0'

        result = verify(n, l, outlet_states, devices, switch, si+1)
        if result is not None:
            return result

        for i in xrange(n):
            outlet_states[i][si] = '1' if outlet_states[i][si] == '0' else '0'

    switch[si] = s
    return None


    #print switch, map(lambda o: ''.join(o), outlet_states)

def solve(n, l):
    switch = l * [None]
    outlet_states = raw_input().split()
    devices = raw_input().split()
    oz = zip(*outlet_states)
    dz = zip(*devices)
    #print outlet_states, devices
    outlet_states = map(list, outlet_states)
    for i in xrange(l):
        oc = Counter(oz[i])
        dc = Counter(dz[i])
        if (oc['0'] == dc['0'] and oc['1'] == dc['1']):
            if oc['0'] == oc['1']:
                switch[i] = None
            else:
                switch[i] = False
        elif (oc['0'] == dc['1'] and oc['1'] == dc['0']):
            switch[i] = True
        else:
            return 'NOT POSSIBLE'
    return verify(n, l, outlet_states, devices, switch, 0)
    #pass



if __name__ == "__main__":
    testcases = input()
    for case_n in xrange(1, testcases+1):
        #print("Case #%i: %s" % (case_n, solve()))
        case_data = map(int, raw_input().split())
        print("Case #%i: %s" % (case_n, solve(*case_data)))

