from itertools import product
from copy import deepcopy
def solve(wanted, have):
    wanted.sort()
    have.sort()
    if (have == wanted):
        return 0
    best = -1
    for bstr in product([0,1], repeat=len(have[0])):
        havedone=deepcopy(have)
        for bitind in range(len(bstr)):
            if (bstr[bitind] == 1):
                for string in havedone:
                    string[bitind] = 1 - string[bitind]
        done = True
        for blah in wanted:
            if blah not in havedone:
                done = False
        count = bstr.count(1)
        if done and (count < best or best == -1):
            best = count
    return best

T = int(input())
for t in range(1,T+1):
    N, L = [int(x) for x in input().split()]
    wanted = [[int(x) for x in y] for y in input().split()]
    have = [[int(x) for x in y] for y in input().split()]
    b = solve(wanted, have)
    out = "NOT POSSIBLE"
    if b != -1:
        out = b
    print("Case #{0}: {1}".format(t,out))
