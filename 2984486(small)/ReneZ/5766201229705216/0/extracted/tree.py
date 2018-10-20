from util import *

class Node(object):
    def __init__(self):
        self.adj = []

def edge(a, b):
    a.adj.append(b)
    b.adj.append(a)

def size(node, parent=None):
    s = 1
    for n in node.adj:
        if n != parent:
            s += size(n, node)
    return s

def fixcost(node, parent=None):
    if len(node.adj) - (parent is not None) == 0:
        return 0
    elif len(node.adj) - (parent is not None) == 1:
        if len(node.adj) == 1:
            return size(node.adj[0], node)
        else:
            n = node.adj[0 if node.adj[0] != parent else 1]
            return size(n, node)
    minimum = None
    for i in node.adj:
        for j in node.adj:
            if i != j and i != parent and j != parent:
                remainder = [x for x in node.adj if x != i and x != j and x != parent]
                cost = fixcost(i, node) + fixcost(j, node) + sum(map(lambda x: size(x, node), remainder))
                if minimum is None:
                    minimum = cost
                else:
                    minimum = min(minimum, cost)
    return minimum

def main():
    r = reader("input")
    num = int(r.next())
    ans = []
    for i in xrange(num):
        N = int(r.next())
        nodes = [Node() for i in xrange(N)]
        for j in xrange(N-1):
            e = map(int, r.next().split(" "))
            edge(nodes[e[0] - 1], nodes[e[1] - 1])

        minimum = None
        for n in nodes:
            if minimum is None:
                minimum = fixcost(n)
            else:
                minimum = min(minimum, fixcost(n))
        ans.append(minimum)
    write("output", ans)

if __name__ == '__main__':
    main()
