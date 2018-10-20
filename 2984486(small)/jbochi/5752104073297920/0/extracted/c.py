import sys

lines = [map(int, line.strip().split(' ')) for line in sys.stdin.readlines()]
T = lines[0][0]

line = 0

fixed = {}
f = []

for t in range(T):
    N = lines[line + 1][0]
    X = lines[line + 2]
    line += 2
    fix = sum([1 for i, x in enumerate(X) if i == x])
    fixed[t] = fix
    f.append([fix, t])

sol = {}

for k, tup in enumerate(sorted(f)):
    fix, i = tup
    if k < T/2:
        sol[i] = "BAD"
    else:
        sol[i] = "GOOD"

for t in range(T):
    print "Case #%d: %s" % (t + 1, sol[t])
