#/usr/local/bin/python

import sys
import math

sys.setrecursionlimit(2000)

def count(tree, root, parent):
    children = [x for x in tree[root] if x != parent]
    ans = 1;
    ans += sum([count(tree, x, root) for x in children])
    return ans
    
def min_tree(tree, root, parent=None):
    children = [x for x in tree[root] if x != parent]
    
    if len(children) == 0:
        return 0;

    if len(children) == 1:
        return count(tree, children[0], root)

    mt  = dict()
    cld = dict()
    
    for x in children:
        mt[x] = min_tree(tree, x, root)
        cld[x] = count(tree, x, root)

    num = sum(cld.values())
    
    ans = num
    for i in xrange(len(children)):
        for j in xrange(i + 1, len(children)):
            x = children[i]
            y = children[j]
            ans = min(ans, mt[x] + mt[y] + sum([cld[z] for z in cld.keys() if z != x and z != y]))
    return ans

T = int(sys.stdin.readline())
for caseno in xrange(T):
    N = int(sys.stdin.readline())
    tree = dict()
    for x in xrange(N - 1):
        a, b = [int(y) for y in sys.stdin.readline().split()]
        children = tree.get(a - 1, [ ]) 
        children.append(b - 1)
        tree[a - 1] = children

        children = tree.get(b - 1, [ ]) 
        children.append(a - 1)
        tree[b - 1] = children
        
    #print tree
    
    ans = N - 1
    for x in xrange(N):
        ans = min(ans, min_tree(tree, x))
        #print x, ans
    print "Case #%d: %s" % (caseno + 1, ans)

