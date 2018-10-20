#!/usr/bin/env python
# -*- coding: utf-8 -*-


def count_size(g, node, parent):
    size = 1
    for n in g[node]:
        if n['node'] == parent:
            continue
        edge_size = count_size(g, n['node'], node)
        n['size'] = edge_size
        for bn in g[n['node']]:
            if bn['node'] == node:
                bn['size'] = len(g) - edge_size
                break
        size += edge_size
    return size

def count_cut(g, node, parent):
    childs = len(g[node])
    if parent is not None:
        childs -= 1
    if childs == 0:
        return 0
    if childs == 1:
        for n in g[node]:
            if n['node'] != parent:
                return n['size']
        raise "Err"
    cuts = []
    for n in g[node]:
        if n['node'] == parent:
            continue
        c = count_cut(g, n['node'], node)
        cuts.append(dict(cut=c, size=n['size'], ben=n['size']-c))
        #n['size'] - cuts.append(count_cut(g, n['node'], node))
    cuts.sort(key=lambda x: x['ben'])
    #print cuts
    r = sum(map(lambda x: x['size'], cuts[:-2]))
    r += cuts[-1]['cut']
    r += cuts[-2]['cut']
    r += len(cuts) - 2
    return r
    #return sum(cuts[:-2]) + len(cuts) - 2


def solve(n):
    g = []
    for i in xrange(n):
        g.append([])

    for i in xrange(n-1):
        a, b = map(int, raw_input().split())
        a -= 1
        b -= 1
        g[a].append(dict(node=b, size=None))
        g[b].append(dict(node=a, size=None))
    count_size(g, 0, None)
    #print g

    min_cut = len(g)
    for i in xrange(n):
        c = count_cut(g, i, None)
        #print c
        if c < min_cut:
            min_cut = c
        # if min_cut == 0:
        #     return 0
    return min_cut

if __name__ == "__main__":
    testcases = input()
    for case_n in xrange(1, testcases+1):
        #print("Case #%i: %s" % (case_n, solve()))
        #case_data = map(int, raw_input().split())
        print("Case #%i: %s" % (case_n, solve(input())))

