def solve(curflows, reqflows):
    curflows = [[int(b) for b in f] for f in curflows]
    reqflows = set(tuple(int(b) for b in f) for f in reqflows)

    F = curflows[0]
    best = None
    for R in reqflows:
        newflows = [f[:] for f in curflows]
        flips = 0
        for i in xrange(len(F)):
            if F[i] != R[i]:
                flips += 1
                for f in newflows:
                    f[i] ^= 1
        newflows = set(tuple(f) for f in newflows)
        if newflows == reqflows:
            if best is None or flips < best:
                best = flips
    if best is None:
        return 'NOT POSSIBLE'
    else:
        return str(best)


def run():
    T = int(raw_input())
    for i in xrange(T):
        N, L = [int(x) for x in raw_input().split()]
        curflow = raw_input().split()
        reqflow = raw_input().split()
        r = solve(curflow, reqflow)
        print 'Case #%d:' % (i + 1), r


if __name__ == '__main__':
    run()
