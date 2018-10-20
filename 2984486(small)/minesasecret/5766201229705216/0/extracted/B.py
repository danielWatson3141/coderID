from collections import deque
def main():
    T = int(raw_input())
    for t in xrange(T):
        N = int(raw_input())
        matrix = [[0]*N for i in xrange(N)]
        for n in xrange(N-1):
            (x,y) = (int(i) for i in raw_input().split())
            x = x-1
            y = y-1
            matrix[x][y] = matrix[y][x] = 1
        roots = find_roots(matrix)
        root = roots[0]
        smallest = count_deletions(make_tree(matrix, root), root)
        for root in roots:
            tree = make_tree(matrix, root)
            temp = count_deletions(tree, root)
            smallest = min(temp, smallest)
        print "Case #" + str(t+1) + ": " + str(smallest)

def find_roots(matrix):
    ret = []
    for i in xrange(len(matrix)):
        row = matrix[i]
        total = 0
        for r in row:
            total += r
        #root can have at most 2 neighbors(both children)
        if total <= 2:
            ret.append(i)
    return ret

def make_tree(matrix, root):
    ret = [[0]*len(matrix) for i in xrange(len(matrix))]
    #insert from left, pop from right
    q = deque()
    q.appendleft(root)
    visited = set([root])
    while len(q) > 0:
        node = q.pop()
        for i in xrange(len(matrix[node])):
            #only add if not to parent
            if ret[i][node] == 0 and matrix[node][i] != 0:
                ret[node][i] = matrix[node][i]
                if i not in visited:
                    q.appendleft(i)
                    visited.add(i)
    return ret

def count_deletions(tree, root):
    current = [root]
    correct_len = 1
    while len(current) == correct_len:
        temp = []
        for node in current:
            for i in xrange(len(tree[node])):
                if tree[node][i] != 0:
                    temp.append(i)
        current = temp
        correct_len = correct_len * 2
    #delete all nodes in current
    ret = 0
    for node in current:
        ret += count_subtree(tree, node)
    return ret

def count_subtree(tree, root):
    """counts subtree of tree starting at root"""
    q = deque()
    q.appendleft(root)
    ret = 0
    while len(q) > 0:
        ret += 1
        node = q.pop()
        for i in xrange(len(tree[node])):
            if tree[node][i] != 0:
                q.appendleft(i)
    return ret

if __name__ == "__main__":
    main()
