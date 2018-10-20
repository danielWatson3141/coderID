#!/usr/bin/python

import sys

def maxtree(root, edges, exclude, dic):
    if((root, exclude) in dic):
        return dic[(root, exclude)]
    children = [e for e in edges if (root in e) and (exclude not in e)]
    if len(children) < 2:
        dic[(root,exclude)] = 1
        return 1
    maxkidtree = []
    kids = [list(e - set([root]))[0] for e in children]
    for kid in kids:
        maxkidtree.append(maxtree(kid, edges, root, dic))
    maxkidtree.sort()
    dic[(root,exclude)] = 1 + maxkidtree[-2] + maxkidtree[-1]
    return 1 + maxkidtree[-2] + maxkidtree[-1]

cases = int(sys.stdin.readline())

for casenum in range(1, cases+1):
    nodenum = int(sys.stdin.readline())
    edges = []
    nodes = set([])
    dic = {}
    for _ in range(nodenum - 1):
        i,j = map(int, sys.stdin.readline().split())
        nodes.add(i)
        nodes.add(j)
        edges.append(set([i, j]))

    maxx = 0
    for root in nodes:
        maxx = max(maxtree(root, edges, -1, dic), maxx)

    print 'Case #{}: {}'.format(casenum, nodenum - maxx)
    
