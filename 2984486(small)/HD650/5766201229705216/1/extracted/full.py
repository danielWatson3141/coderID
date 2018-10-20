import sys
from collections import defaultdict

infile = sys.stdin
#infile = open('input')



class Node(object):
    def __init__(self, name):
        self.name = name
        self.edges = set()
        self.visited = False

    def __str__(self):
        return "name: %d, edges: %s" % (self.name, self.edges)

def solve(nodes, N):
    # for i in xrange(N):
    #     print nodes[i]
    ret = 0
    for root in xrange(N):
        ret = max(ret, trav(nodes[root], nodes))
    return N - ret

def trav(node, nodes):
    if len(node.edges) <= 1:
        return 1

    count = list()
    for c in node.edges:
        child = nodes[c]
        child.edges.remove(node.name)
        count.append(trav(child, nodes))
        child.edges.add(node.name)

    count = sorted(count, key = lambda x: -x)
    return count[0] + count[1] + 1


case_num = int(infile.readline())
for case in xrange(case_num):
    N = int(infile.readline())
    nodes = list()
    for i in xrange(N):
        nodes.append(Node(i))
    for i in xrange(N-1):
        a, b = [int(v) for v in infile.readline().split()]
        a -= 1
        b -= 1
        nodes[a].edges.add(b)
        nodes[b].edges.add(a)
    print "Case #%d: %d" % (case + 1, solve(nodes, N))
