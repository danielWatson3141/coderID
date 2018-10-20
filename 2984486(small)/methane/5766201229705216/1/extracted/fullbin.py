from __future__ import print_function
import sys
from collections import defaultdict


class G(defaultdict):
    def __init__(self):
        defaultdict.__init__(self, list)
        self._cutcount_cache = {}

    def add(self, x, y):
        self[x].append(y)
        self[y].append(x)

    def remove(self, x, y):
        self[x].remove(y)
        self[y].remove(x)

    def size(self, node, parent):
        s = 1
        for c in self[node]:
            if c == parent:
                continue
            s += self.size(c, node)
        return s

    def cutcount(self, node, parent):
        if (node, parent) in self._cutcount_cache:
            return self._cutcount_cache[(node, parent)]
        count = self._cutcount(node, parent)
        self._cutcount_cache[(node, parent)] = count
        return count

    def _cutcount(self, node, parent):
        children = self[node][:]
        if parent is not None:
            children.remove(parent)
        S = len(children)
        if S == 0:
            return 0
        if S == 1:
            return self.size(children[0], node)
        if S == 2:
            return self.cutcount(children[0], node) + self.cutcount(children[1], node)

        sizes = [(self.size(n, node) - self.cutcount(n, node), n) for n in children]
        sizes.sort(reverse=True)
        C = sum(self.cutcount(c, node) for _, c in sizes[:2])
        return C + sum(self.size(c, node) for _, c in sizes[2:])


def solve(graph):
    minimum = len(graph)

    for root in graph:
        n = graph.cutcount(root, None)
        if n < minimum:
            minimum = n

    return minimum


def main():
    T = int(sys.stdin.readline())

    for t in range(1, T+1):
        N = int(sys.stdin.readline().strip())
        graph = G()
        for i in range(N-1):
            x, y = map(int, sys.stdin.readline().split())
            graph.add(x, y)

        y = solve(graph)
        if y is None:
            y = 'NOT POSSIBLE'
        print("Case #{}: {}".format(t, y))

#test()
main()
