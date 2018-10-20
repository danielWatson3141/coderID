import sys
import math
lines = sys.stdin.readlines()
good = 0
bad = 0
for i in range(120):
    a = lines[2*i+2].split()
    s = 0
    for j in range(len(a)): s += math.pow(j-int(a[j]),2)
    if s < 162000000: 
        print "Case #"+str(i+1)+": BAD"
        bad += 1
    else: 
        print "Case #"+str(i+1)+": GOOD"
        good += 1

print good, bad

