import itertools as it
import copy

def flipdig(f, i):
    if (f >> i) % 2 == 0:
        return f + (1 << i)
    else:
        return f - (1 << i)

def flip(i, flows):
    return [flipdig(f, i) for f in flows]


def check(c, needs, flows):
    for i in c:
        flows = flip(i, flows)
    flows.sort()
    for i in xrange(len(flows)):
        if needs[i] != flows[i]:
            return False
    return True
    

def solve(case):
    n,l = map(int, case[0].split())
    needs = map(lambda x: int(x, 2), case[1].split())
    needs.sort()
    flows = map(lambda x: int(x, 2), case[2].split())
    n1s = [sum(map(lambda x: (x >> i) % 2, needs)) for i in xrange(l)]
    f1s = [sum(map(lambda x: (x >> i) % 2, flows)) for i in xrange(l)]
    ambig = []
    force = []
    for i in xrange(l):
        if n1s[i] + f1s[i] == n:
            ambig.append(i)
        elif n1s[i] == f1s[i]:
            force.append(i)
        else:
            return None
    for i in force:
        flows = flip(i, flows)
    for l in xrange(len(ambig)):
        for c in it.combinations(ambig, l):
            if check(c, copy.copy(needs), copy.copy(flows)):
                return l + len(force)
    return None

"""
    nflips = []
    fflips = []
    for i in force:
        flows = flip(i, flows)
    for i in ambig:
        if n1s[i] > l/2:
            needs = flip(i, needs)
            nflips.append(i)
        if f1s[i] > l/2:
            flows = flip(i, flows)
            fflips.append(i)
        if (f1s[i] == l/2) and (n1s[i] == l/2):
            print 'shit'
    needs.sort()
    flows.sort()
    for i in xrange(n):
        if needs[i] != flows[i]:
            return None
    return xorlist(fflips, nflips) + len(force)
"""
    
def xorlist(l1, l2):
    return len([j not in l1 for j in l2]) + len([i not in l2 for i in l1])





f = file('a.in', 'r')
lines = f.readlines()
t = int(lines[0])
f.close()

g = file('a.out', 'w')

for i in xrange(t):
    result = solve(lines[3*i + 1:3*i+4])
    if result == None:
        s = "NOT POSSIBLE"
    else:
        s = result
    g.write("Case #{}: {}\n".format(i+1, s))

g.close()
