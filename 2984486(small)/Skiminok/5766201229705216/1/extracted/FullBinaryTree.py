#!/usr/bin/env python3
from collections import defaultdict
import multiprocessing
import sys

__author__ = 'polozov'


def main(*args):
    node_count, graph = args[0]
    dp = defaultdict(dict)

    def calc(root, v, par = None):
        if v in dp[root]: return dp[root][v]
        cutoff = -1 if root == v else 0
        if len(graph[v]) == 1 + cutoff:  # leaf
            dp[root][v] = (0, 1)
            return 0, 1
        elif len(graph[v]) == 2 + cutoff:  # single child
            child = graph[v][0] if v == root or graph[v][1] == par else graph[v][1]
            if_del = 1 + calc(root, child, par = v)[1]
            if_not_del = calc(root, child, par = v)[1]
            dp[root][v] = (if_not_del, if_del)
            return if_not_del, if_del
        else:
            child_results = sorted((calc(root, c, par = v) for c in graph[v] if c != par),
                                   key = lambda r: r[1],
                                   reverse = True)
            if_del = 1 + sum(res[1] for res in child_results)
            if_not_del = sum(res[1] for res in child_results[2:]) + child_results[0][0] + child_results[1][0]
            dp[root][v] = (if_not_del, if_del)
            return if_not_del, if_del

    ans = min(cnt for root in range(1, node_count + 1) for cnt in calc(root, root))
    return ans


if __name__ == '__main__':
    # with open('B-test.in', 'wt') as f:
    #     f.write('100\n')
    #     for i in range(100):
    #         f.write('1000\n')
    #         for i in range(1, 1000):
    #             f.write('{0} {1}\n'.format(i, i + 1))
    # sys.exit(0)
    sys.setrecursionlimit(2000)
    test_count = int(input())
    graphs = []
    counts = []
    for test in range(1, test_count + 1):
        graphs.append(defaultdict(list))
        counts.append(int(input()))
        for e in range(counts[-1] - 1):
            n1, n2 = map(int, input().split())
            graphs[-1][n1].append(n2)
            graphs[-1][n2].append(n1)
    pool = multiprocessing.Pool()
    results = pool.map(main, zip(counts, graphs))
    for i, res in enumerate(results):
        print('Case #{0}: {1}'.format(i + 1, res))