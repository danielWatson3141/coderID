import sys

def subtree(tree, visited, node):
    vs = set(visited)
    size = 0
    queue = [node]
    while queue:
        n = queue.pop()
        if n in vs:
            continue
        vs.add(n)
        size += 1
        queue.extend(c for c in tree[n] if c not in vs)
    return size

def deletes(tree, root, visited=None):
    visited = set(visited or [])
    queue = [root]
    deleted = 0
    while queue:
        node = queue.pop()
        if node in visited:
            continue
        children = tree[node]
        ch = len(children)
        if node != root:
            ch -= 1
        visited.add(node)

        if ch == 0:
            pass
        elif ch == 2:
            queue.extend(c for c in children if c not in visited)
        elif ch == 1: # delete all sub tree
            deleted += sum(subtree(tree, visited, c) for c in children if c not in visited)
        elif ch > 2: # delete all, leave 2 with least children
            counts = [deletes(tree, c, visited) for c in children if c not in visited]
            counts.sort()
            deleted += sum(counts[2:])
    return deleted

f = open(sys.argv[1])
T = int(f.readline())
for t in xrange(1,T+1):
    n = int(f.readline().strip())
    tree = [set() for i in xrange(n)]
    for i in xrange(n-1):
        x, y = map(int, f.readline().strip().split())
        x -= 1
        y -= 1
        tree[x].add(y)
        tree[y].add(x)

    res = min(deletes(tree, i) for i in xrange(n))

    print "Case #{0}: {1}".format(t, res)
