# def sol(n, l, S, F):
#     D = {}
#     dc = [0] * (l + 1)
#     M = [[None] * n for i in xrange(n)]
#
#     for s in S:
#         for f in F:
#             d, bits = diff(s, f)
#             M[i][j] = (d, bits)
#             st = D.setdefault(s, set())
#             if d not in st:
#                 dc[d] += 1
#                 st.add(d)
#     gr = l + 1
#     gbits = None
#     for d in xrange(l + 1):
#         if dc[d] >= n and d < gr:
#             gr = d
#             gbits = bits

def count(x):
    r = 0
    while x > 0:
        r += 1
        x = x & (x - 1)
    return r


def sol(n, l, S, F):
    ff = set(F)
    for i in xrange((1 << l)):
        ss = set(s ^ i for s in S)
        if ss == ff:
            return count(i)
    return "NOT POSSIBLE"

    

import sys
readline = sys.stdin.readline

line = readline()
tn = int(line)
for i in xrange(1, tn + 1):
    line = readline()
    n, l = map(int, line.split(" "))
    S = map(lambda s: int(s, 2), readline().split(" "))
    F = map(lambda s: int(s, 2), readline().split(" "))
    print 'Case #{}: {}'.format(i, sol(n, l, S, F))
