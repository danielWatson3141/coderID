import os
import sys
from itertools import combinations

lines = sys.stdin.readlines()
num_cases = int(lines[0])
lines = lines[1:]

def match(n, l):
    n = list(n)
    l = list(l)

    if len(l) != len(n):
        return False

    for i in n:
        if i in l:
            l.remove(i)

    return len(l) == 0

for zz in range(1, num_cases+1):
    t = lines[0].split(" ")
    n = int(t[0])
    l = int(t[1])
    lines = lines[1:]

    items = lines[0].strip().split(" ")
    outlets = lines[1].strip().split(" ")

    # If they match, done
    if match(outlets, items):
        print "Case #%s: 0" % zz
    else:
        # Do stuff
        done = False
        # Iterate over all combinations
        for i in range(1, l+1):
            for c in combinations(range(l), i):
                global num_changes
                results = []
                for itemz in items:
                    item = list(itemz)
                    for i in c:
                        i = int(i)
                        item[i] = "1" if item[i] == "0" else "0"
                    item = ''.join(item)
                    results += [item]
                if match(outlets, results):
                    print "Case #%s: %s" % (zz, len(c))
                    done = True
                    break
            if done:
                break
        if not done:
            print "Case #%s: NOT POSSIBLE" % zz

    lines = lines[2:]
