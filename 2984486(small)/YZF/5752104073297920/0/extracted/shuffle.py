# for k in 0 .. N-1:
#   a[k] = k
# for k in 0 .. N-1:
#   p = randint(0 .. N-1)
#   swap(a[k], a[p])

import random

N = 1000
counts = {}
countf = {}

def good():
    t = range(0, N)

    for k in range(0, N):
        p = random.randint(k, N - 1)
        t[k], t[p] = t[p], t[k]

    return t

def bad():
    t = range(0, N)

    for k in range(0, N):
        p = random.randint(0, N - 1)
        t[k], t[p] = t[p], t[k]

    return t

p = {}
for i in xrange(0, N):
    p[i] = {}
    for j in xrange(0, N):
        p[i][j] = 1.0

for ttt in xrange(0, 40000):
    t = bad()

    for i, j in enumerate(t):
        p[i][j] = p[i][j] - 0.0000002

def check(t, threshold):
    badness = 1
    for i, j in enumerate(t):
        badness = badness * p[i][j]

    if badness < threshold:
        return "BAD"
    else:
        return "GOOD"

def solveit():
    f.readline()
    t = [int(x) for x in f.readline().split()]
    return check(t, 0.991965020215)

# threshold = 0.991982020215
# for of in xrange(-1000, 1000, 1):
#     offs = of / 1000000.0
#     ga = 0
#     for i in xrange(0, 120):
#         if random.randint(0, 1):
#             t = good()
#             if check(t, threshold+offs) == "GOOD":
#                 ga = ga + 1
#         else:
#             t = bad()
#             if check(t, threshold+offs) == "BAD":
#                 ga = ga + 1
#
#     print threshold+offs, ga

outfile = open("results.txt", "w")
with open("test.txt") as f:
    testcases = int(f.readline())

    for i in xrange(0, testcases):
        outcome = solveit()
        # print "Case #%d:" % (i + 1,), outcome
        print >> outfile, "Case #%d:" % (i + 1,), outcome

