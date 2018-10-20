from sys import stdin
rl = stdin.readline
T = int(rl())

def solve(otl, swt):
    if swt == L:
        if device == sorted(otl):
            return 0
        else:
            return 1600

    result = 1600 
    for i in xrange(2):
        result = min(result, i + solve(otl, swt + 1))
        otl = flip(otl, swt)

    return result 

def flip(otl, swt):
    return [o ^ switch[swt] for o in otl]

for t in xrange(T):
    N, L = map(int, rl().split())
    switch = []
    for i in xrange(L):
        s = list('0' * L)
        s[i] = '1'  
        switch.append(int(''.join(s), 2))

    outlet = sorted([int(ou, 2) for ou in rl().split()])
    device = sorted([int(de, 2) for de in rl().split()])
    
    r = solve(outlet, 0)
    if r == 1600:
        print 'Case #%d: %s' % (t + 1, 'NOT POSSIBLE')
    else:
        print 'Case #%d: %d' % (t + 1, r)

  
