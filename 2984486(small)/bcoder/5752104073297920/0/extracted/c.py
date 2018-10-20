#!/usr/bin/env python
import sys

def solveCase(lines):
    s = map(int, lines[1].split())
    assert len(s) % 1000 == 0
    diag = 1 if (s[len(s) - 1] == len(s) - 1) else 0
    back = 0
    for i in range(0, len(s)-1):
        diag += 1 if (s[i] == i) else 0
        back += 1 if (s[i] == i+1) else 0
    #print "back = {} ... diag = {}".format(back, diag)
    if back >= 2:
        return "BAD"
    if back == 0:
        return "GOOD"
    if diag == 0:
        return "BAD"
    if diag >= 2:
        return "GOOD"
    return "GOOD"

lines = [line.strip() for line in sys.stdin]
T = int(lines.pop(0))
assert len(lines) == T*2
for i in range(0, T):
    print "Case #{}: {}".format(i+1, solveCase(lines[0:2]))
    lines = lines[2:]

