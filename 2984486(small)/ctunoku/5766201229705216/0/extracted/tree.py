class Node(object):
    def __init__(self, name):
        self.neighbors = []
        self.name = name

    def __str__(self):
        return str(self.name)

def subtree_size(root, parent):
    """Returns the size of the subtree rooted at ROOT with
    parent PARENT.
    """
    children = [c for c in root.neighbors if c is not parent]
    return 1 + sum(subtree_size(child, root) for child in children)

def best_subtree_with(root, children):
    """Returns the minimum number of nodes to delete in order
    to make the subtree rooted at ROOT with parent PARENT into
    a full binary tree.
    """
    #No children - already good.
    if len(children) == 0:
        return 0
    #1 child - must delete entire subtree.
    if len(children) == 1:
        return subtree_size(children[0], root)
    #More children - pick cheapest way to kill all except two
    costs = []
    for child in children:
        kill_cost = subtree_size(child, root)
        sub_cost = best_subtree(child, root)
        costs.append((kill_cost, sub_cost))
    costs.sort(key = lambda kill_sub: kill_sub[1] - kill_sub[0])
    sub_cost = sum(ks[1] for ks in costs[:2])
    kill_cost = sum(ks[0] for ks in costs[2:])

    # "Best subtree with %s: %s" % (root.name, sub_cost + kill_cost)
    return sub_cost + kill_cost

def best_subtree(root, parent):
    """Returns the minimum number of nodes to delete in order
    to make the subtree rooted at ROOT with parent PARENT into
    a full binary tree.
    """
    children = [c for c in root.neighbors if c is not parent]
    return best_subtree_with(root, children)

def best_tree(node_list):
    """Returns the minimum number of nodes to delete in order
    to make the subtree rooted at ROOT into a full binary tree.
    """
    min_tree = 10000
    for node in node_list:
        min_tree = min(min_tree, best_subtree_with(node, node.neighbors))
    return min_tree

def main():
    output = ''
    with open('test.in') as f:
        cases = int(f.readline()[:-1])
        for case in range(cases):
            N = int(f.readline()[:-1])

            nodes = {}
            for i in range(1, N + 1):
                nodes[i] = Node(i)

            for _ in range(N - 1):
                x, y = [int(i) for i in f.readline()[:-1].split()]
                nx, ny = nodes[x], nodes[y]
                nx.neighbors.append(ny)
                ny.neighbors.append(nx)

            ans = best_tree(n for i, n in nodes.items())
            output += 'Case #%s: %s\n' % (case + 1, ans)

    with open('test.out', 'w') as f:
        f.write(output)

#print chargeable([['01', '11', '10']], [['11', '00', '10']])
#print nice_chargeable(['01', '11', '10'], ['11', '00', '10'])
main()