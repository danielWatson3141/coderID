import sys
import itertools

sys.stdin = open('tree.in', 'r')
sys.stdout = open('tree.out', 'w')

def main():
    total_cases = int(input())
    for case_number in range(1, total_cases + 1):
        best = float('inf')
        node_count = int(input())
        edges = []
        for i in range(node_count-1):
            edge = [int(i)-1 for i in input().split()]
            edges.append(edge)
        tree = create_tree(edges, node_count)
        for i in range(node_count):
            agh = make_binary(i, tree, -1)
            if agh < best:
                best = agh
        print('Case #%d: %d' % (case_number, best))

def create_matrix(size):
    outer = [False] * size
    for i in range(len(outer)):
        outer[i] = [False] * size
    return outer

def create_tree(edges, node_count):
    tree = create_matrix(node_count)
    for edge in edges:
        i, j = edge
        tree[i][j] = True
        tree[j][i] = True
    return tree

# # returns number of deletions to make tree
def make_binary(root, tree, ignore):
    children = make_children(tree[root], ignore)
    if len(children) == 0:
        return 0
    elif len(children) == 1:
        return 1 + make_binary(children[0], tree, root)
    elif len(children) == 2:
        return make_binary(children[0], tree, root) + make_binary(children[1], tree, root)
    else: 
        deletions = len(children) - 2
        perms = [i for i in itertools.combinations(children, 2)]
        perm_deletions = []
        for perm in perms:
            perm_deletion = 0
            eat_children = list_remove_all(children, perm)
            for child in eat_children:
                perm_deletion += make_binary(child, tree, root)
            perm_deletions.append(perm_deletion)
        return deletions + min(perm_deletions)

def make_children(l, ignore):
    children = []
    for i in range(len(l)):
        if i == ignore:
            continue
        if l[i]:
            children.append(i)
    return children

def list_remove_all(l, l2):
    l = l[:]
    for i in l2:
        l.remove(i)
    return l

if __name__ == '__main__':
    main()