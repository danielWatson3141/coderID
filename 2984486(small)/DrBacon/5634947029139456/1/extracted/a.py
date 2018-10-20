#!/usr/bin/env python

import fileinput
import sys
import math

def read_cases():
    fh = fileinput.input()
    T = int(fh.readline().strip())
    cases = []
    for t in range(T):
        case = {}
        case["N"], case["L"] = map(int, fh.readline().strip().split(" "))
        case["outlets"] = fh.readline().strip().split(" ")
        case["devices"] = fh.readline().strip().split(" ")
        cases += [case]
    if fh.readline().strip() !="":
        raise Exception
    return cases



def process_case(case):
    outlets = case["outlets"]
    devices = case["devices"]
    #outlets = [[i=="1" for i in o] for o in outlets]
    #devices = [[i=="1" for i in d] for d in devices]
    N = case["N"]
    L = case["L"]
    remaing_ds = sorted(devices[1:])
    best = None
    for m , match in enumerate(outlets):
        switches = [match[i]!=devices[0][i] for i in range(L)]
        remaining_os = [outlets[i] for i in range(N) if i != m]
        remaining_os = ["".join([["1","0"][o[i]=="1"] if s else o[i] for i, s in enumerate(switches)]) for o in remaining_os]
        remaining_os.sort()
        if remaining_os == remaing_ds:
            changes = sum(switches)
            if best is None:
                best = changes
            else:
                if best > changes:
                    best = changes
    if best is not None:
        return best
    return "NOT POSSIBLE"

if __name__ == "__main__":
    cases = read_cases()
    #print cases

    for i, case in enumerate(cases[:]):
        result = process_case(case)
        print "Case #%s:" % (i+1, ) , result
        #sys.stderr.write("Progress: %d/%d (%d%%) \r" % (i+1, len(cases), int(100.*(i+1)/len(cases) ) ) )
        #sys.stderr.flush()
