import sys
import itertools
import math
import collections
import functools

sys.setrecursionlimit(1000)

nodes = []

class Node:
    def __init__(self, k):
        self.k = k
        self.next = []
        self.deleted = False
    def link(self, other):
        self.next.append([other, nodes[other].getSubtreeSizesMinus(self.k)])
    def getSubtreeSizesMinus(self, k):
        r = 1
        for n in self.next:
            if n[0] != k:
                r += n[1]
        return r
    def nextCount(self):
        return len(self.next)

    def removeSmallestSubtree(self):
        m = 0
        for i in xrange(1, len(self.next)):
            if self.next[i][1] < self.next[m][1]:
                m = i
        self.deleted = True
        res = nodes[self.next[m][0]].remove()
        self.next.pop(m)
        self.deleted = False
        return res

    def remove(self):
        if self.deleted:
            return 0
        deleted = 1
        self.deleted = True
        for v in self.next:
            deleted += nodes[v[0]].remove()
        return deleted

    def getSmallestTree(self):
        m = 0
        for i in xrange(1, len(self.next)):
            if self.next[i][1] < self.next[m][1]:
                m = i
        return [m, self.next[m][1]]
        


def solve(N, i, roots):
    # Assume [0 .. i-1] are correct.
    
    if i == N:
        return finalize(N, roots)
    
    if nodes[i].deleted:
        return solve(N, i+1, roots)

    n = nodes[i].nextCount()
    removed = 0
    while n > 3:
        removed += nodes[i].removeSmallestSubtree()
        n -= 1
    
    if n == 2:
        roots.append(i)

    return removed + solve(N, i+1, roots)


def finalize(N, roots):
    if len(roots) == 1:
        return 0
    if len(roots) == 0:
        return 0

    minTree = False
    for r in roots:
        m = nodes[r].getSmallestTree()
        if minTree == False or m[1] < minTree[2]:
            minTree = [r, m[0], m[1]]

    removed = nodes[minTree[0]].removeSmallestSubtree()
    roots2 = []
    for r in roots:
        if r != minTree[0] and not nodes[r].deleted:
            roots2.append(r)
    return removed + finalize(N, roots2)
        

T = int(raw_input())
for testId in range(T):
    N = int(raw_input())
    nodes = []
    for i in xrange(N):
        nodes.append(Node(i))

    for n in xrange(N-1):
        x, y = map(int, raw_input().split())
        x -= 1
        y -= 1
        nodes[x].link(y)
        nodes[y].link(x)

    res = solve(N, 0, [])

    print "Case #{:d}: {:d}".format(testId+1, res)
