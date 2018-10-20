import sys
from collections import defaultdict

sys.setrecursionlimit(10000)


def read_numbers(line=None):
    if line is None:
        line = sys.stdin.readline()
    return [int(x) for x in line.split()]


def full_binary_tree(graph, node, visited):
    visited.add(node)
    children = list(set(graph[node]) - visited)
    if len(children) == 0:
        return 0, 1
    elif len(children) == 1:
        min_removes, size = full_binary_tree(graph, children[0], visited)
        return size, size + 1
    elif len(children) == 2:
        min_removes_left, size_left = full_binary_tree(graph, children[0], visited)
        min_removes_right, size_right = full_binary_tree(graph, children[1], visited)
        return min_removes_left + min_removes_right, size_left + size_right + 1
    else:
        subresults = [full_binary_tree(graph, child, visited) for child in children]
        s = [(size - min_removes, min_removes, size) for (min_removes, size) in subresults]
        s.sort()
        min_removes = 0
        for sort_key, removes, size in s[:-2]:
            min_removes += size
        for sort_key, removes, size in s[-2:]:
            min_removes += removes
        size = sum(size for (sort_key, min_removes, size) in s)
        return min_removes, size + 1


def full_binary_tree_unrooted(graph):
    result = 10 ** 10
    for node in graph:
        min_removes, size = full_binary_tree(graph, node, set())
        # print min_removes, size, node
        result = min(result, min_removes)
    return result


if __name__ == '__main__':
    case_count = int(sys.stdin.readline()[:-1])
    for i in range(1, case_count + 1):
        n = read_numbers()[0]
        graph = defaultdict(list)
        for _ in range(n - 1):
            v, w = read_numbers()
            graph[v].append(w)
            graph[w].append(v)

        print "Case #%d: %d" % (i, full_binary_tree_unrooted(graph))
