import random as r

def gengood():
    a = range(1000)
    for i in xrange(1000):
        p = r.randrange(i, 1000)
        z = a[i]
        a[i] = a[p]
        a[p] = z
    return a

def genbad():
    a = range(1000)
    for i in xrange(1000):
        p = r.randrange(1000)
        z = a[i]
        a[i] = a[p]
        a[p] = z
    return a

def avdist(a):
    c = 0
    for i in xrange(1000):
        if a[i] >900:
            c += abs(a[i]- i)
    return c/10

def countcycles(a):
    ccount = [0] * 1000
    notchecked = dict(zip(range(1000), [0] * 1000))
    while notchecked:
        c = 1
        init, _ = notchecked.popitem()
        curr = a[init]
        while curr != init:
            c += 1
            del notchecked[curr]
            curr = a[curr]
        ccount[c] += 1
    t = 0
    for i in xrange(300):
        t += i * ccount[i]
    return t
        

def fps(a):
    c = 0
    for i in xrange(10000):
        if a[i] == i:
            c += 1
    return c

def flips(a):
    c=0
    for i in xrange(1000):
        if i > a[i]:
            c += 1
    return c/10

def nonhalfflips(a):
    c = 0
    for i in xrange(900,1000):
        if a[i] > 900:
            c += 1
    return c/5


goodfps = [0] * 1000
badfps = [0] * 1000

for i in xrange(1000):
    goodfps[flips(gengood())] += 1
    badfps[flips(genbad())] += 1
#print goodfps[:100]
#print badfps[:100]
#print sum(map(max, zip(goodfps, badfps)))


f = file('c.in', 'r')
lines = f.readlines()

g = file('c.out','w')
for i in xrange(120):
    perm = map(int, lines[2 + 2*i].split())
    d = flips(perm)
    if goodfps[d] > badfps[d]:
        s = 'GOOD'
    else:
        s = 'BAD'
    g.write("Case #{}: {}\n".format(i+1, s))
g.close()

