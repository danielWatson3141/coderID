import sys, string
from copy import copy, deepcopy

def readlist():
	return [int(x) for x in sys.stdin.readline().strip().split(" ")]

def readbinlist():
	return [int(x,2) for x in sys.stdin.readline().strip().split(" ")]

def readint():
	return int(sys.stdin.readline())

T = readint()

def flip(cfg, bit):
    new = []
    for c in cfg:
        new.append(c ^ (1 << bit))
    return sorted(new)

def expand(cfg, nbits):
    cfgs = []
    for b in range(nbits):
        cfgs.append(flip(cfg, b))
    return cfgs
    
for t in range(T):
    N, L = readlist()
    init = readbinlist()
    goal = readbinlist()
    init = sorted(init)
    goal = sorted(goal)
    
    print ("Case #%d:" % (t+1)),
    #~ print N,L,init,goal
    
    if init == goal:
        print "0"
        continue

    Q = [init]
    S = [0]
    i = 0
    solved = False
    while i < len(Q) and not solved:
        cfg = Q[i]
        s = S[i]
        for c in expand(cfg, L):
            if c == goal:
                print s+1
                #~ print c
                solved = True
                break
            if c not in Q:
                Q.append(c)
                S.append(s+1)
        #~ print Q
        
        i += 1
    if not solved:
        print "NOT POSSIBLE"
