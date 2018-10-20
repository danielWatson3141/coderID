import collections


def get_ints():
    return map(int, raw_input().split())


n_cases = input()
for case in xrange(1, n_cases + 1):
    node_count, = get_ints()
    edges = collections.defaultdict(list)
    for _ in xrange(node_count - 1):
        a, b = get_ints()
        edges[a].append(b)
        edges[b].append(a)

    def countnodes(root, parent):
        return 1 + sum(countnodes(node, root)
                       for node in edges[root] if node != parent)

    def trimcount(root, parent):
        children = [node for node in edges[root] if node != parent]
        if len(children) == 0:
            return 0
        elif len(children) == 1:
            return countnodes(children[0], root)
        elif len(children) == 2:
            return trimcount(children[0], root) + trimcount(children[1], root)
        else:
            # minimize total
            trimdata = [(countnodes(child, root), trimcount(child, root))
                        for child in children]
            trimdata.sort(key=lambda (delete, trim): delete - trim)
            delsum = sum(delete for delete, trim in trimdata[:-2])
            trimsum = sum(trim for delete, trim in trimdata[-2:])
            #print "wat", root, parent, trimdata, delsum, trimsum
            return delsum + trimsum

    #print list(edges.iteritems())

    result = node_count + 1
    for root in xrange(1, node_count + 1):
        result = min(result, trimcount(root, None))

    print "Case #%d: %s" % (case, result)
