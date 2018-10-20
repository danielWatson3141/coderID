import sys

def isSubBin(a, node, parent):
    subnodes = [x for x in a[node] if x != parent]
    if len(subnodes) != 2 and len(subnodes) != 0:
        return False
    for x in subnodes:
        if not isSubBin(a, x, node):
            return False
    return True


def isBin(a):
    n = [len(x) for x in a]
    if sum(n) == 0:
        return True
    b = [i for i in range(len(n)) if n[i] == 2]
    if len(b) != 1:
        return False
    return isSubBin(a, b[0], -1)

def convertGraph(a):
    b = [[] for i in range(len(a)+1)]
    for n1, n2 in a:
        #print n1, n2
        n1 -= 1
        n2 -= 1
        b[n1].append(n2)
        b[n2].append(n1)
    return b

cache = {}

def calcSub2(a, node, parent):
    if len(a[node]) == 1:
        return 1
    if len(a[node]) == 2:
        return 1
    res = [calcSub(a, x, node) for x in a[node] if x != parent]
    res.sort()
    return res[-1]+res[-2]+1

def calcSub(a, node, parent):
    if (node, parent) not in cache:
        res = calcSub2(a, node, parent)
        cache[(node, parent)] = res
    return cache[(node, parent)]

def calcRoot(a, i):
    if len(a[i]) == 1:
        return 1
    res = [calcSub(a, x, i) for x in a[i]]
    res.sort()
    return sum(res[-2:])+1

def foo(ifile):

    n = int(ifile.readline())
    a = convertGraph([[int(x) for  x in ifile.readline().split()] for i in range(n-1)])
    #print a
    cache.clear()
    res = 0
    for i in range(n):
        t = calcRoot(a, i)
        #print i, t
        res  = max(res, t)
    #print cache
    return n - res

def main(ifile):
    n = int(ifile.readline().strip())
    for i in range(n):
        print 'Case #%s: %s' % (i+1, foo(ifile))

main(sys.stdin)

