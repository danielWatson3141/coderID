from collections import defaultdict


def out(case_num, st):
    print("Case #%d: %s" % (case_num, st))


def add_nodes(tree, old_tree, start_node, exclude):
    tree[start_node]
    for connected in old_tree[start_node]:
        if connected == exclude:
            continue
        tree[start_node].append(connected)
        add_nodes(tree, old_tree, connected, start_node)


def tree_from_node(tree, start_node, exclude):
    new_tree = defaultdict(list)
    add_nodes(new_tree, tree, start_node, exclude)
    return new_tree


def how_many_deletions(tree, root):
    if len(tree) <= 1:
        return 0

    if len(tree[root]) < 2:
        # only one or less connections, delete them all
        return len(tree) - 1

    if len(tree[root]) == 2:
        # good, it has exactly two
        return (
            how_many_deletions(
                tree_from_node(tree, tree[root][0], root), tree[root][0]) +
            how_many_deletions(
                tree_from_node(tree, tree[root][1], root), tree[root][1]))

    if len(tree[root]) > 2:
        options = sorted(tree[root])

        options_values = defaultdict(tuple)

        for opt in options:
            opt_tree = tree_from_node(tree, opt, root)
            options_values[opt] = (len(opt_tree),
                                   how_many_deletions(opt_tree, opt))

        min_deletions = 2000
        for opt_1_idx in range(len(options)):
            opt_1 = options[opt_1_idx]
            for opt_2_idx in range(len(options) - opt_1_idx - 1):
                opt_2 = options[opt_1_idx + opt_2_idx + 1]

                num_deletions = 0
                for opt in options:
                    if opt == opt_1 or opt == opt_2:
                        num_deletions += options_values[opt][1]
                    else:
                        num_deletions += options_values[opt][0]

                min_deletions = min(min_deletions, num_deletions)

        return min_deletions

    return 2000


def run_case(case_num, input):
    N = int(input.readline())
    links = [[int(x) for x in input.readline().rstrip("\n").split(" ")]
             for i in range(N - 1)]

    tree = defaultdict(list)

    for link in links:
        tree[link[0] - 1].append(link[1] - 1)
        tree[link[1] - 1].append(link[0] - 1)

    min_deletions = N
    for node in range(N):
        ans = how_many_deletions(tree, node)
        min_deletions = min(ans, min_deletions)

    out(case_num, min_deletions)

# GCJ boiler plate...call run_case for each case given
if __name__ == '__main__':
    import sys
    sys.setrecursionlimit(10000)
    with sys.stdin as f:
        [run_case(i + 1, f) for i in range(int(f.readline()))]
