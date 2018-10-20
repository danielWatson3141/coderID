#!/usr/bin/python

import sys
import itertools

def flipper(item, perm):
    flip = []
    for i in range(len(perm)):
        if perm[i] == '1' and item[i] == '0':
            flip.append('1')
        elif perm[i] == '1' and item[i] == '1':
            flip.append('0')
        elif perm[i] == '0':
            flip.append(item[i])
    return ''.join(flip)

def count(perm):
    c = 0
    for i in range(len(perm)):
        if perm[i] == '1':
            c += 1
    return c

f = open(sys.argv[1])
o = open(sys.argv[2], 'w')
cases = int(f.readline())
for i in xrange(cases):
    N, L = map(int, f.readline().split())
    have = sorted(f.readline().split())
    want = sorted(f.readline().split())
    done = False
    if have == want:
        done = True
        o.write("Case #" + str(i+1) + ": 0\n")
        continue

    seq = [''.join(seq) for seq in itertools.product('01', repeat=L)]
    for j in range(1,L+1):
        cur = [x for x in seq if count(x) == j]
        for perm in cur:
            flip = []
            for item in have:
                flip.append(flipper(item, perm))
            if sorted(flip) == want:
                done = True
                o.write("Case #" + str(i+1) + ": " + str(j) + "\n")
                break
        if done:
            break

    if not done:
        o.write("Case #" + str(i+1) + ': NOT POSSIBLE\n')


o.close()
print "Done, output written"
 
