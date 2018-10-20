from functools import reduce
from sys import stdin

file = stdin

def read_line():
    return file.readline()

def read_int():
    return int(read_line())

def lst2int(x):
    return [int(e) for e in x]
cases = read_int()
for case_no in range(1, cases + 1):
    [N, L] = map(int, read_line().split())
    flows = [x for x in map(lambda x: int(x, 2), read_line().split())]
    devices = map(lambda x: int(x, 2), read_line().split())
    all_set = []
    for device in devices:
        xr = set([])
        for flow in flows:
            xr.add(device ^ flow)
        all_set.append(xr)
    common = reduce(lambda a, b: a.intersection(b), all_set)
    lst = [lst2int(list(bin(c))[2:]) for c in list(common)]
    lst = [reduce(lambda x, y: x+y, l)for l in lst]
    out = ""
    if len(lst) == 0:
        out = "NOT POSSIBLE"
    else:
        out = min(lst)
    print("Case #{0}: {1}".format(case_no, out))