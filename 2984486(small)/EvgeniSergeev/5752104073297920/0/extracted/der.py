from random import *

def estimate_prob():
    der = [1, 0]
    for i in range(2, 1005):
        der.append((i-1)*(der[i-1]+der[i-2]))

    perms = [1]
    for i in range(1, 1005):
        perms.append(perms[-1]*i)

    probs = [(p*1000000)/d for p,d in zip(perms, der)[2:]]
    print probs[1002]/1000000.0


import sys
stdin = sys.stdin
T = int(stdin.readline())
for icase in range(T):
    N = int(stdin.readline())
    p = map(int, stdin.readline().strip().split())
    ks = 0
    for a, b in zip(p, range(N)):
        if a == b:
            ks += 1

    print "Case #%d:" % (icase+1), 
    bad = False
    if ks >= 4:
        bad = True
    elif ks == 3:
        bad = (random() < 0.6)
    elif ks == 2:
        bad = (random() > 0.15)
    if bad:
        print "BAD"
    else:
        print "GOOD"
    
