#! /usr/bin/python

import sys, itertools

def getline():
    return sys.stdin.readline().strip()

DEBUG = False
def out(s):
    if DEBUG:
        sys.stderr.write(str(s) + '\n')

class Case:
    def __init__(self, casenum):
        self.casenum = casenum

    def done(self, answer):
        print 'Case #%d: %d' % (self.casenum, answer)

    def getEdges(self, n):
        edges = {i+1:set() for i in xrange(n)}
        for i in xrange(n - 1):
            x, y = getline().split()
            x = int(x)
            y = int(y)
            edges[x].add(y)
            edges[y].add(x)
        return edges

    def cut(self, node, ignores):
        return 1 + self.cuts(self.edges[node] - ignores,
                             ignores.union(set([node])))

    def cuts(self, nodes, ignores):
        return sum((self.cut(node, ignores) for node in nodes))

    def trims(self, root, ignores):
        nodes = self.edges[root]
        children = nodes - ignores
        if len(children) == 0:
            return 0

        if len(children) == 1:
            return self.cuts(children, ignores)

        return min(
            (self.cuts(children - set(pair), ignores.union(set(pair)))
             + self.trims(pair[0], ignores.union(set([pair[0]])))
             + self.trims(pair[1], ignores.union(set([pair[1]])))
             for pair in itertools.combinations(children, 2)))

    def solve(self):
        n = int(getline())
        self.edges = self.getEdges(n)

        self.done(min(self.trims(root, set((root,)))
                      for root in self.edges.keys()))

cases = int(getline())
for case in xrange(cases):
    Case(case + 1).solve()
