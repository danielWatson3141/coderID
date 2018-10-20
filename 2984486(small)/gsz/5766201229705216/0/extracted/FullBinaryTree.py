#!/usr/bin/env python

from __future__ import print_function
from itertools import *

def isFullBinaryRooted(graph, root, removed):
    if len(graph[root] - removed) == 0:
        return True
    if len(graph[root] - removed) == 2:
        children = list(graph[root] - removed)
        return (isFullBinaryRooted(graph, children[0], removed | {root}) and
                isFullBinaryRooted(graph, children[1], removed | {root}))
    return False

def isFullBinary(graph, removed):
    if len(removed) == len(graph):
        return True
    for i in xrange(len(graph)):
        if i in removed:
            continue
        if isFullBinaryRooted(graph, i, removed):
            return True
    return False

def isConnected(graph, removed):
    if not (set(range(len(graph))) - removed):
        return True
    s = (set(range(len(graph))) - removed).pop()
    q = [s]
    reachable = set()
    while q:
        v = q.pop()
        reachable.add(v)
        q.extend(list(graph[v] - removed - reachable))
    return len(reachable) == len(graph) - len(removed)

def readSolveCase():
    N = int(raw_input())
    graph = [set() for n in xrange(N)]
    for i in xrange(N-1):
        Xi, Yi = (int(s) - 1 for s in raw_input().split())
        graph[Xi].add(Yi)
        graph[Yi].add(Xi)
    for numRemoved in xrange(N+1):
        for c in combinations(range(N), numRemoved):
            if isConnected(graph, set(c)) and isFullBinary(graph, set(c)):
                return numRemoved

def main():
    T = int(raw_input())
    for t in xrange(1, T+1):
        print('Case #{}: {}'.format(t, readSolveCase()))

if __name__ == "__main__":
    main()
