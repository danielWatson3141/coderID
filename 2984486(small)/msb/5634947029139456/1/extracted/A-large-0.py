#!/usr/bin/env python

max_switches = 1000

def xor_bit(current, devices, bit):
    mask = 1 << bit
    for i in xrange(devices):
        current[i] ^= mask

def bit_matches(current, final, devices, bit):
    mask = 1 << bit
    for i in xrange(devices):
        if current[i] & mask != final[i] & mask:
            return False
    return True

def rewire(current, final, devices, bits):
    if bits == 0:
        return 0
    switchesA = max_switches
    switchesB = max_switches
    final.sort()
    current.sort()
    if bit_matches(current, final, devices, bits - 1):
        switchesA = rewire(current[:], final[:], devices, bits - 1)
    xor_bit(current, devices, bits - 1)
    current.sort()
    if bit_matches(current, final, devices, bits - 1):
        switchesB = 1 + rewire(current[:], final[:], devices, bits - 1)    
    if (switchesA < switchesB):
        return switchesA
    else:
        return switchesB

for case in xrange(int(raw_input())):
    devices, bits = map(int, raw_input().split())
    current = [int(x, 2) for x in raw_input().split()]
    final = [int(x, 2) for x in raw_input().split()]
    print "Case #%d:" % (case+1),
    switches = rewire(current, final, devices, bits)
    if switches == max_switches:
        print "NOT POSSIBLE"
    else:
        print switches
    #convert(number, source, target)
