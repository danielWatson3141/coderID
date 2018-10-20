from itertools import permutations

def diff(s1, s2):
    diffs = []
    for i in range(l):
        if (s1[i] != s2[i]):
            diffs += [i]
    #print(diffs)
    return diffs

def helper(wy, mini):
    numdiff = diff(wy[0], device[0])
    if len(numdiff) > mini:
        return 42
    for i in range(1, n):
        if diff(wy[i], device[i]) != numdiff:
            return 42
    return len(numdiff)

t = int(raw_input())

for case in range(1, t + 1):
    n, l = (int(x) for x in raw_input().split())
    flow = raw_input().split()
    device = raw_input().split()
    min_flip = 42
    for way in permutations(flow):
        result = helper(way, min_flip)
        if result != 42:
            min_flip = result
    if min_flip == 42:
        print "Case #%d: NOT POSSIBLE" % case
    else:
        print "Case #%d: %d" % (case, min_flip)

