def nodes_num(graph, root, parent):
    if len(graph[root]) == 1:
        return 1
    else:
        to_strip = graph[root][:]
        to_strip.remove(parent)
        deleted = 1
        for node in to_strip:
            deleted += nodes_num(graph, node, root)
        return deleted


def try_subtree(graph, parent, grantparent):
    deleted = 0
    for node in graph[parent]:
        if node == grantparent:
            continue
        # leaf
        if graph[node] == [parent]:
            continue
        # single child
        elif len(graph[node]) == 2:
            if graph[node][0] == parent:
                deleted += nodes_num(graph, graph[node][1], node)
            else:
                deleted += nodes_num(graph, graph[node][0], node)
        # iterate
        elif len(graph[node]) == 3:
            try_subtree(graph, node, parent)
    return deleted


def try_tree(graph):
    results = []
    for key in graph.iterkeys():
        if len(graph[key]) == 1:
            continue
        else:
            results.append(try_subtree(graph, key, None))
    if not results:
        return 0
    return min(results)


for i in range(int(raw_input())):
    N = int(raw_input())
    graph = {}
    for j in range(N - 1):
        a, b = raw_input().split()
        graph.setdefault(a, list()).append(b)
        graph.setdefault(b, list()).append(a)
    print('Case #%s: %s' % (i + 1, try_tree(graph)))

