#!/usr/bin/env python
import sys
import copy
import itertools as it

def solveCase(lines):
    (N, L) = map(int, lines[0].split())
    efo = map(str, lines[1].split())
    efd = map(str, lines[2].split())
    
    def isAMatch(ef):
        defo = {}
        for i in ef:
            if i in defo:
                defo[i] += 1
            else:
                defo[i] = 1
        for i in efd:
            if i not in defo:
                return False
            if defo[i] == 0:
                return False
            defo[i] -= 1
        return True
    if isAMatch(efo):
        return 0
     
    for i in range(1, L + 1):
        for cmb in it.combinations(range(0, L), i):
            scmb = set(cmb)
            tefo = copy.deepcopy(efo)
            for j in range(0, len(tefo)):
                finalStr = ""
                for k in range(0, len(tefo[j])):
                    if k in scmb:
                        finalStr += "1" if tefo[j][k] == "0" else "0"
                    else:
                        finalStr += tefo[j][k]
                assert len(tefo[j]) == len(finalStr)
                tefo[j] = finalStr
            if isAMatch(tefo):
                return i
    return "NOT POSSIBLE"

lines = [line.strip() for line in sys.stdin]
T = int(lines.pop(0))
caseLine = 3
assert len(lines) == T*caseLine
for i in range(0, T):
    print "Case #{}: {}".format(i+1, solveCase(lines[0:caseLine]))
    lines = lines[caseLine:]
