def hamming(n):
    return bin(n).count('1')

def solve(testnum):
    n,l = [int(x) for x in input().split()]
    a = [int(x,2) for x in input().split()]
    b = [int(x,2) for x in input().split()]
    sets = [set([bi ^ ai for ai in a]) for bi in b]
    poss = sets[0]
    for s in sets[1:]:
        poss.intersection_update(s)
    if len(poss) == 0:
        print("Case #%d: NOT POSSIBLE"%testnum)
    else:
        best = -1
        bestcount = l+1
        for p in poss:
            count = hamming(p)
            if count < bestcount:
                best = p
                bestcount = count
        print("Case #%d: %d"%(testnum, bestcount))

for i in range(int(input())): solve(i+1)
