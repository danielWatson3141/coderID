from itertools import product

getints = lambda : map(int, raw_input().split())

def flip(outlets, pos):
    for o in outlets:
        for p in pos:
            o[p] = abs(o[p] - 1)

def makeset(lol):
    s = set()
    for l in lol:
        s.add(tuple(l))
    return s

for t in range(input()):
    n, l = getints()
    outlets = map(lambda x: map(int, list(x)), raw_input().split())
    devices = map(lambda x: map(int, list(x)), raw_input().split())

    lengths = []

    device_set = makeset(devices)

    for i in product(range(2), repeat=l):
        pos = []
        for index, tf in enumerate(i):
            if tf:
                pos.append(index)
        flip(outlets, pos)
        if makeset(outlets) == device_set:
            lengths.append(len(pos))
        flip(outlets, pos)


    if len(lengths) == 0:
        res = "NOT POSSIBLE"
    else:
        res = str(min(lengths))
    print "Case #{}: {}".format(t+1, res)
