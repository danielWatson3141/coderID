#!/usr/bin/env python
#coding:utf-8

def read():
    n = int(raw_input())
    adj = [[] for i in range(n)]
    for i in range(n - 1):
        s, t = map(int, raw_input().split())
        adj[s - 1].append(t - 1)
        adj[t - 1].append(s - 1)
    return adj


def rec(cur, pre, adj):
    child = [c for c in adj[cur] if c != pre]

    # (全部の子供, それを complete にするためのコスト)
    nchild_cost = [rec(c, cur, adj) for c in child]
    
    allChild = 0
    for (nchild, cost) in nchild_cost:
        allChild += nchild
    
    if len(child) >= 2:
        minV = 1<<20
        for i in range(len(child)):
            for j in range(i + 1, len(child)):
                minV = min(minV, allChild - nchild_cost[i][0] - nchild_cost[j][0] + \
                                          + nchild_cost[i][1] + nchild_cost[j][1])
        return (allChild + 1, minV)

    if len(child) == 1:
        return (allChild + 1, allChild)
    
    return (1, 0)


def work(cases, adj):
    minV = 1 << 20

    for root in range(len(adj)):
        minV = min(minV, rec(root, -1, adj)[1])
    
    print "Case #%d: %d" % (cases, minV)


if __name__ == "__main__":
    for i in range(int(raw_input())):
        work(i + 1, read())
