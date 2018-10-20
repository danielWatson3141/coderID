#!/usr/bin/python

import itertools

# filename = "sample.in"
filename = "A-small-attempt0.in"
# filename = "A-large.in"

inp = open(filename, "rU")

n = int(inp.readline().strip())

for case in range(1, n + 1):
    switches, length = map(int, inp.readline().strip().split(" "))
    outlets = list(map(lambda x: int(x, 2), inp.readline().strip().split(" ")))
    devices = list(map(lambda x: int(x, 2), inp.readline().strip().split(" ")))
    # print([bin(c) for c in outlets])
    mx = int(length * '1', 2) + 1
    outp = mx
    solved = False
    for i in range(mx):
        p = [x ^ i for x in outlets]
        # print(sorted(p), sorted(devices))
        if sorted(p) == sorted(devices):
            solved = True
            tmp = sum([int(x) for x in bin(i)[2:]])
            if tmp < outp:
                outp = tmp
    if not solved:
        outp = "NOT POSSIBLE"

    print("Case #{}: {}".format(case, outp))
