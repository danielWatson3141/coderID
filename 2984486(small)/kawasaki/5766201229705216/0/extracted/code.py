# -*- coding: utf-8 -*-

import sys


def bitcount(n):
    return bin(n).count('1')


def is_fully_binary_tree(conn):
    for root in xrange(len(conn)):
        num_edge = conn[root].count(True)
        if num_edge != 2:
            continue
        done = set([root])
        stack = [i for i, b in enumerate(conn[root]) if b]
        while stack:
            node = stack.pop(0)
            done.add(node)
            num_edge = conn[node].count(True)
            if num_edge == 1:
                continue
            elif num_edge == 2:
                break
            elif 3 < num_edge:
                break
            stack.extend([i for i, b in enumerate(conn[node]) if b and i not in done])
        else:
            if len(done) == len(conn):
                return True
    return False


T = int(raw_input())
for test_case in xrange(1, T + 1):
    N = int(raw_input())
    CONNECTION = [[False for i in xrange(N)] for j in xrange(N)]
    for i in xrange(N - 1):
        x, y = map(int, raw_input().split())
        CONNECTION[x - 1][y - 1] = CONNECTION[y - 1][x - 1] = True

    best = N - 1
    for i in xrange(2 ** N):
        conn = [
            [CONNECTION[y][x] for x in xrange(N) if (1 << x) & i == 0]
            for y in xrange(N) if (1 << y) & i == 0
        ]
        if is_fully_binary_tree(conn):
            best = min(best, bitcount(i))

    answer = best
    print 'Case #{}: {}'.format(test_case, answer)
    sys.stdout.flush()
