import sys

def search(curr, bi, N, L, end, switches, mins):
    if curr == end:
        if switches < mins:
            mins = switches
        return mins

    if bi >= L:
        return mins

    new = list(curr)

    for se in (0, 1):
        if se == 1:
            for i in range(N):
                t = list(new[i])
                if t[bi] == '0':
                    t[bi] = '1'
                else:
                    t[bi] = '0'
                new[i] = ''.join(t)

            new = sorted(new)
            switches += 1

        mins = search(new, bi + 1, N, L, end, switches, mins)
        if se == 1:
            switches -= 1

    return mins

T = int(sys.stdin.readline().strip())
for casei in range(T):
    N, L = sys.stdin.readline().split()

    N = int(N)
    L = int(L)

    st = sys.stdin.readline().split()
    st = sorted([s for s in st])

    ed = sys.stdin.readline().split()
    ed = sorted([s for s in ed])

    ret = search(st, 0, N, L, ed, 0, 100)

    out = "Case #{0}: ".format(casei + 1)

    if ret == 100:
        out += "NOT POSSIBLE"
    else:
        out += str(ret)

    print out
