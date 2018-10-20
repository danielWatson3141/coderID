#!/usr/bin/python
import sys

class Node:
    def __init__(self, i):
        self.connected = set()
        self.treeConnected = list()
        self.index = i
        self.size = 1

# Build a tree of Nodes
def buildTree(root, parent):
    if parent is not None:
        root.treeConnected = list(root.connected - set([parent]))
    else:
        root.treeConnected = list(root.connected)
    map(lambda node: buildTree(node, root), root.treeConnected)

# Augment tree with sizes
def augmentTree(root):
    if len(root.treeConnected) == 0:
        root.size = 1
    else:
        root.size = 1 + sum(map(augmentTree, root.treeConnected))
    return root.size

# Returns cost of making binary tree
def makeBinaryTree(root):
    children = len(root.treeConnected)
    if children == 0:
        return 0
    elif children == 2:
        return makeBinaryTree(root.treeConnected[0]) + makeBinaryTree(root.treeConnected[1])
    elif children == 1:
        return root.treeConnected[0].size
    else:
        tcList = root.treeConnected
        sizes = map(lambda node: node.size, tcList)
        maxSize = 0
        maxIndex = None
        nextMaxSize = 0
        nextMaxIndex = None
        for j in xrange(len(sizes)):
            size = sizes[j]
            if size > maxSize:
                nextMaxSize = maxSize
                nextMaxIndex = maxIndex
                maxSize = size
                maxIndex = j
            elif size > nextMaxSize:
                nextMaxSize = size
                nextMaxIndex = j
        #print "Delete case:", root.index, (maxSize, maxIndex), (nextMaxSize, nextMaxIndex)
        cost = 0
        for j in xrange(len(tcList)):
            if j == maxIndex or j == nextMaxIndex:
                cost += makeBinaryTree(tcList[j])
            else:
                cost += tcList[j].size
        return cost
            
T = int(sys.stdin.readline())
for i in xrange(T):
    print "Case #%d:" % (i+1),
    N = int(sys.stdin.readline())
    nodes = []
    for j in xrange(N):
        nodes.append(Node(j+1))
    for j in xrange(N-1):
        start, end = map(int, sys.stdin.readline().split(" "))
        nodes[start-1].connected.add(nodes[end-1])
        nodes[end-1].connected.add(nodes[start-1])
    minCost = float("inf")
    root = None
    for j in xrange(N):
        # Try root at each node
        buildTree(nodes[j], None)
        augmentTree(nodes[j])
        # DEBUG
        # print "TREE"
        # for k in xrange(N):
        #     print k+1, map(lambda n: n.index, nodes[k].treeConnected), nodes[k].size
        cost = makeBinaryTree(nodes[j])
        #print cost
        if cost < minCost:
            minCost = cost
            root = j
    print minCost
