import sys
stdin = sys.stdin

INF = 2147483647

T = int(stdin.readline())
for icase in range(T):
    stdin.readline()
    xs = map(list, stdin.readline().strip().split())
    ys = map(list, stdin.readline().strip().split())
    xs = [[int(i) for i in x] for x in xs]
    ys = [[int(i) for i in y] for y in ys]
    candidates = set()
    for x in xs:
        for y in ys:
            xor = [a ^ b for (a, b) in zip(x, y)]
            candidates.add(tuple(xor))
    ys.sort()
    best = INF
    for cand in candidates:
        switched = []
        for x in xs:
            switched.append([a ^ b for (a, b) in zip(x, cand)])
        switched.sort()
        if switched == ys:
            best = min(best, sum(cand))

    if INF == best:
        re = "NOT POSSIBLE"
    else:
        re = str(best)

    print "Case #%d:" % (icase+1), re


