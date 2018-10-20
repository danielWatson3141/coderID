import sys

lines = [line.strip().split(' ') for line in sys.stdin.readlines()]

T = int(lines[0][0])

for t in range(T):
    N, L = map(int, lines[t*3+1])
    outlets = sorted(map(lambda x: int(x, 2), lines[t*3+2]))
    flow = map(lambda x: int(x, 2), lines[t*3+3])

    frst = flow[0]
    best = 9999
    for outlet in outlets:
        changes = frst^outlet
        nchanges = len([c for c in bin(changes)[2:] if c == '1'])
        if nchanges < best:
            result = sorted([changes^f for f in flow])
            if outlets == result:
                best = nchanges

    print "Case #%d: %s" % (t + 1, "NOT POSSIBLE" if best == 9999 else best)

