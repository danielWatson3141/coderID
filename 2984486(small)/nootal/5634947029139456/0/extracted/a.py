#!/usr/bin/env pypy
import sys, os

outfile = open("%s.out" % sys.argv[1], "w")
case_number = 1

def flip(l, flows, devices, avoid, remaining):
    # print "\nRemaining", remaining
    if remaining == 0:
        return set(flows) == devices
    else:
        for flipped in range(l):
            if flipped in avoid:
                continue
            # print flows
            # print flipped
            new_flows = [flow[:flipped] + str(int(flow[flipped]) ^ 1) + flow[flipped+1:] for flow in flows]
            # print new_flows
            if flip(l, new_flows, devices, avoid + [flipped], remaining - 1):
                return True
        
def solving(n, l, flows, devices):
    global case_number
    print "case: ", case_number
    devices = set(devices)
    # print "flows", flows

    result = None
    # for to_flip in range(l + 1):
    for to_flip in range(l):
        if flip(l, flows, devices, [], to_flip):
            result = to_flip
            break

    if result is None: result = "NOT POSSIBLE"
    outfile.write("Case #%d: %s\n" % (case_number, result))
    case_number += 1
    print ""
    
with open(sys.argv[1]) as infile:
    for index, l in enumerate(infile.readlines()[1:]):
        if index % 3 == 0:
            n, ll = map(int, l.split())
        else:
            numbers = l.split()
            if index % 3 == 1:
                flows = numbers
            else:
                solving(n, ll, flows, numbers)
outfile.close()
