#!/usr/bin/python
import sys, string, math

#solve case function
def solve_case(bit_length, outlets, devices, case_number):
    outlets.sort()
    devices.sort()
    levers = int(math.pow(2, bit_length))
    lever_candidates = []
    for lever in range(0, levers):
        levered_outlets = map(lambda x: x ^ lever, outlets[:])
        levered_outlets.sort()
        if (levered_outlets == devices):
            lever_candidates.append(lever)

    if (len(lever_candidates) < 1):
        print "Case #%d: NOT POSSIBLE" % case_number
        return

    print "Case #%d: %d" % (case_number, min(map(lambda x: bin(x).count("1"), lever_candidates)))

    #main
r = sys.stdin

if len(sys.argv) > 1:
    r = open(sys.argv[1], 'r')

total_cases = r.readline()
for case_number in range(1, int(total_cases) + 1):
    b = int(r.readline().split(' ')[1])
    o = map(lambda x: int(x, 2), r.readline().split(' '))
    d = map(lambda x: int(x, 2), r.readline().split(' '))
    solve_case(b, o, d, case_number)
