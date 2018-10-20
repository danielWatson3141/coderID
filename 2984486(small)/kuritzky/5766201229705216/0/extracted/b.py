# -*- coding: utf-8 -*-
"""
Problem A. Bullseye
uses python 3.3

@author: Eric Kuritzky
"""
from collections import *
import itertools as itool
import operator as op
import functools as ft
from sys import argv, stdin, stdout, stderr
    
def errprt(*args, **kw):
    print(*args, file=stderr, **kw) 

def readcase():
    nvert = int(input())
    g = Graph(nvert)
    for _ in range(nvert-1):
        g.addedge(*readints())
    return g

def solvecase(g):
    if g.isfulltree():
        return 0
    best = len(g.edge)
    vtx = g.getunmarkedleaf()
    if vtx is None:
        return best
    g.markleaf(vtx)
    best = solvecase(g)
    g.unmarkleaf(vtx)
    g.delete(vtx)
    best = min(best, 1+solvecase(g))
    g.undelete(vtx)
    return best

class Graph(object):
    def __init__(self, nvert):
        self.edge = [None] + [[] for _ in range(nvert)]
        self.order = [0] * (nvert+1)
        self.delstack = []
        self.ordermap = Counter()
        self.ordermap[0] = nvert
        self.leafs = set()
        self.marked = set()
    def addedge(self, fro, to):
        self.edge[fro].append(to)
        self.edge[to].append(fro)
        for v in (to, fro):
            order = len(self.edge[v])
            self.ordermap[order-1] -= 1
            self.ordermap[order] += 1
            if order == 2:
                self.leafs.remove(v)
            elif order == 1:
                self.leafs.add(v)
    def isfulltree(self):
        for order, count in self.ordermap.items():
            if order>3 or order == 2 and count != 1:
                return False
        return True
    def getunmarkedleaf(self):
        for v in range(1, len(self.edge)):
            if len(self.edge[v]) == 1 and v not in self.marked:
                return v
        return None
    def markleaf(self, leaf):
        self.marked.add(leaf)
    def unmarkleaf(self, leaf):
        self.marked.remove(leaf)
    def delete(self, leaf):
        assert len(self.edge[leaf]) == 1
        assert leaf not in self.marked
        other = self.edge[leaf][0]
        self.delstack.append((leaf, other))
        self.edge[leaf].remove(other)
        self.edge[other].remove(leaf)
        for v in (leaf, other):
            order = len(self.edge[v])
            self.ordermap[order+1] -= 1
            self.ordermap[order] += 1
            if order == 0:
                self.leafs.remove(v)
            elif order == 1:
                self.leafs.add(v)
    def undelete(self, leaf):
        v1, v2 = self.delstack.pop()
        assert leaf == v1
        self.addedge(v1, v2)

def readints():
    return list(map(int, input().split(' ')))

def main():
        cases = int(input())
        for case in range(1, cases+1):
            print('Case #%d: %s' % (case, solvecase(readcase())))

main()
