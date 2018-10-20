import random

def al1(n):
    a = [k for k in range(n)]
    for k in range(n):
        p = random.randint(k, n-1)
        a[k], a[p] = a[p], a[k]
    return a

def al2(n):
    a = [k for k in range(n)]
    for k in range(n):
        p = random.randint(0, n-1)
        a[k], a[p] = a[p], a[k]
    return a

def dist(a, b):
#    return minEditDistR(a, b)
    s = 0
    for i in range(len(a)):
        s += (a[i] == b[i])
    return s

def substCost(x, y):
    if x == y: return 0
    else : return 2

def minEditDistR(target, source):
    """ Minimum edit distance. Straight from the recurrence. """
    
    i = len(target); j = len(source)
    
    if i == 0:  return j
    elif j == 0: return i
    
    return(min(minEditDistR(target[:i-1],source)+1,
               minEditDistR(target, source[:j-1])+1,
               minEditDistR(target[:i-1], source[:j-1])+substCost(source[j-1], target[i-1])))


f = file('in.txt') 
ls = f.readlines()

t = int(ls[0])

for Case in range(t):
    n = int(ls[2*Case+1])
    target = map(lambda e: int(e), ls[2*Case+2].split())
#    print n
#    print target

    t = 10000 if n < 20 else 100

    s1 = 0

    for i in range(t):
        r1 = al1(n)
        s1 += dist(r1, target)

    s1 /= float(t)

    s2 = 0
    for i in range(t):
        r2 = al2(n)
        s2 += dist(r2, target)
    s2 /= float(t)

#    print s1, s2

    if (abs(s1-s2) > 0.05):
        ret = "BAD"
    else:
        ret = "GOOD"
    print "Case #%d: %s" % (Case+1, ret)
