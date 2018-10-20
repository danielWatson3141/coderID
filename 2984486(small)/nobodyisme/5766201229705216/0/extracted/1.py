#!/usr/bin/env python
from itertools import combinations
import sys


def problem(j, fi):

    adj = {}
    idx = {}

    r1 = int(fi.readline().strip())
    for i in xrange(r1 - 1):
        edge = [int(c) for c in fi.readline().strip().split(' ')]
        adj.setdefault(edge[0], set()).add(edge[1])
        adj.setdefault(edge[1], set()).add(edge[0])

    for node, adjs in adj.iteritems():
        idx.setdefault(len(adjs), set()).add(node)

    return adj, idx


cache = {}


def count_subtree(adj, child, parent=None):
    if cache.get(child, {}).get(parent):
        return cache[child][parent]

    max_nodes = 1
    for children in combinations(adj[child] - set([parent]), 2):
        max_nodes = max(max_nodes,
            count_subtree(adj, children[0], child) + count_subtree(adj, children[1], child) + 1)

    cache.setdefault(child, {})[parent] = max_nodes
    return max_nodes


def solve(params, fo, i):
    global cache
    cache = {}

    adj, idx = params

    max_nodes = 1
    for node in adj:
        max_nodes = max(max_nodes, count_subtree(adj, node))

    # print cache

    return len(adj) - max_nodes

if __name__ == '__main__':
    with open(sys.argv[1]) as fi, open(sys.argv[2], 'w') as fo:
        total = int(fi.readline().strip())
        for i in range(total):
            res = solve(problem(i, fi), fo, i)
            fo.write('Case #{0}: {1}\n'.format(i + 1, res))
            fo.flush()
