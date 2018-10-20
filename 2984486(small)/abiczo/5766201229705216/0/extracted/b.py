from collections import defaultdict

def tree_size(root, nodes, edges):
    out_edges = list(edges[root].intersection(nodes))
    nodes2 = nodes.difference(set([root]))

    ret = 1
    for u in out_edges:
        ret += tree_size(u, nodes2, edges)

    return ret

def solve(root, nodes, edges):
    out_edges = list(edges[root].intersection(nodes))
    if not out_edges:
        return 0

    nodes2 = nodes.difference(set([root]))

    sizes = {}
    for u in out_edges:
        sizes[u] = tree_size(u, nodes2, edges)

    remove_all = sum(sizes.values())
    best = remove_all
    for i in xrange(0, len(out_edges) - 1):
        for j in xrange(i + 1, len(out_edges)):
            u = out_edges[i]
            v = out_edges[j]
            cost = solve(u, nodes2, edges) + solve(v, nodes2, edges) + remove_all - sizes[u] - sizes[v]
            if cost < best:
                best = cost

    return best


if __name__ == '__main__':
    for caseno in xrange(int(raw_input())):
        N = int(raw_input())
        edges = defaultdict(set)
        nodes = set()
        for _ in xrange(N - 1):
            a, b = [s for s in raw_input().split()]
            if a == b:
                continue
            edges[a].add(b)
            edges[b].add(a)
            nodes.add(a)
            nodes.add(b)

        sol = min(solve(root, nodes, edges) for root in nodes)

        print 'Case #%d: %d' % (caseno + 1, sol)
