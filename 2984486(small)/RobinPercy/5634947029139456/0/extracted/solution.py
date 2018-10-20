#! /usr/bin/env pypy

N = int(raw_input())

def solve():
    (N, L) = [int(x) for x in raw_input().split()]
    outlets = [int(x,2) for x in raw_input().split()]
    devices = sorted([int(x,2) for x in raw_input().split()])
    switches = 0 

    min_change = find_min_change(0, switches, outlets, devices, 0, L) 
    if min_change == float("inf"):
        return "NOT POSSIBLE" 
    else:
        return min_change
        
def test_switches(switches, outlets, devices):
    modified_outlets = []
    for o in outlets:
        modified_outlets.append(switches ^ o)
#    print "Comparing %s == %s" % (sorted(modified_outlets), devices)
    works = sorted(modified_outlets) == devices 
#    print works
    return works

def find_min_change(i, switches, outlets, devices, num_changed, L):
    if i == L:
        #print "Testing pattern: %s" % bin(switches)
        if test_switches(switches, outlets, devices):
            return num_changed
        else:
            return float("inf") 

    off = find_min_change(i+1, switches, outlets, devices, num_changed, L)
    switches = switches | 1 << i
    on = find_min_change(i+1, switches, outlets, devices, num_changed + 1, L)
    return min(off, on) 



for i in range(1, N+1):
    print "Case #%s: %s" % (i, solve())

