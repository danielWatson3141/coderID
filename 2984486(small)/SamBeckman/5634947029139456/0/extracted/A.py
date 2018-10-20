from itertools import permutations, product
import functools
debug = False

out = open('Aout.txt', 'w')
lines = open('A-small-attempt0.in').read().splitlines()

def invert(outlets, switches):
    re = []
    for outlet in outlets:
        re.append(switches ^ outlet)
        if debug: print outlet, "xor", switches, "=", re[-1]
    return re

T = int(lines[0])
for case in xrange(0, T):
    if debug: print "case", case, "----------------------------------------"
    N, L = map(int, lines[case*3+1].split())
    outlets = map(functools.partial(int, base=2), lines[case*3+2].split())
    devices = set(map(functools.partial(int, base=2), lines[case*3+3].split()))
    
    if debug: print N, L, outlets, devices
    #############################################
    
    min_flips = 999999999
    max_val = 2**L
    for flips in xrange(max_val):
        flip_count = bin(flips).count('1')
        result = invert(outlets, flips)
        if debug: print result, list(devices)
        if debug: print outlets
        if set(result) == devices and flip_count < min_flips:
            min_flips = flip_count
            if min_flips == 0 or min_flips == 1: break
    
    
    re = min_flips
    if re == 999999999: re = "NOT POSSIBLE"
    out.write("Case #%d: " % (case+1) + str(re) + "\n")

print "DONE"
out.close()


# count switches
# bin(n).count('1')