#!/usr/bin/python
import sys

sys.setrecursionlimit(10000)

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
    for node in root.treeConnected:
        buildTree(node, root)

# Augment tree with sizes
def augmentTree(root):
    if len(root.treeConnected) == 0:
        root.size = 1
    else:
        root.size = 1 + sum(map(augmentTree, root.treeConnected))
    return root.size

sizeMemo = {}
def treeSize(root, parent):
    if (root,parent) in sizeMemo:
        return sizeMemo[(root,parent)]
    ans = 1
    for node in root.connected:
        if node != parent:
            ans += treeSize(node, root)
    sizeMemo[(root,parent)] = ans
    return ans

# Returns cost of making binary tree
memo = {}
def makeBinaryTree(root, parent):
    if (root,parent) in memo:
        return memo[(root,parent)]
    if parent is not None:
        treeConnected = list(root.connected - set([parent]))
    else:
        treeConnected = list(root.connected)
    children = len(treeConnected)
    if children == 0:
        ans = 0
    elif children == 2:
        ans = makeBinaryTree(treeConnected[0], root) + makeBinaryTree(treeConnected[1], root)
    elif children == 1:
        ans = treeSize(treeConnected[0], root)
    else:
        tcList = treeConnected
        sizes = map(lambda node: treeSize(node, root), tcList)
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
                cost += makeBinaryTree(tcList[j], root)
            else:
                cost += treeSize(tcList[j], root)
        ans = cost
    memo[(root, parent)] = ans
    # print root.index, children, ans
    return ans
            
T = int(sys.stdin.readline())
for i in xrange(T):
    print "Case #%d:" % (i+1),
    memo ={}
    sizeMemo = {}
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
        #buildTree(nodes[j], None)
        #augmentTree(nodes[j])
        # DEBUG
        # print "TREE"
        # for k in xrange(N):
        #     print k+1, map(lambda n: n.index, nodes[k].treeConnected), nodes[k].size
        cost = makeBinaryTree(nodes[j], None)
        #print cost
        if cost < minCost:
            minCost = cost
            root = j
    print minCost
