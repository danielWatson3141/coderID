def flip(ch):
    return '1' if ch == '0' else '0'

INF = 1000000000

def solve(poss, lev):
    global L, N, devices, outlets

    if any(len(p) == 0 for p in poss):
        return INF

    if lev == L:
        return 0

    poss2 = []
    fposs2 = []
    for idx, d in enumerate(devices):
        ps = []
        fps = []
        for o in poss[idx]:
            if o[lev] == d[lev]:
                ps += [o]
            else:
                fps += [o]

        poss2 += [ps]
        fposs2 += [fps]

    return min(solve(poss2, lev + 1), 1 + solve(fposs2, lev + 1))



if __name__ == '__main__':
    for caseno in xrange(int(raw_input())):
        N, L = [int(s) for s in raw_input().split()]
        outlets = [s for s in raw_input().split()]
        devices = [s for s in raw_input().split()]
        devices.sort()

        poss = [outlets for d in devices]

        best = solve(poss, 0)

        sol = str(best) if best < INF else "NOT POSSIBLE"
        print 'Case #%d: %s' % (caseno + 1, sol)
