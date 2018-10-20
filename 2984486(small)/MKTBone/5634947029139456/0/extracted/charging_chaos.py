#!/usr/bin/python
import sys

# Charging Chaos

def valid(outlets, devices):
    for device in devices:
        if device not in outlets:
            return False
    return True

lines = [l.rstrip() for l in sys.stdin.readlines()]
for i in xrange(int(lines.pop(0))):
    n, l = [int(x) for x in lines[i*3].split(' ')]
    outlets = [int(x, 2) for x in lines[i*3+1].split(' ')]
    devices = sorted([int(x, 2) for x in lines[i*3+2].split(' ')])
    flips = l + 1
    for x in xrange(1 << l):
        if valid([outlet ^ x for outlet in outlets], devices):
            if bin(x).count('1') < flips:
                flips = bin(x).count('1')
    print "Case #%u: %s" % (i + 1, str(flips) if flips <= l else "NOT POSSIBLE")
