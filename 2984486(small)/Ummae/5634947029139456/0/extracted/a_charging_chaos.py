import sys
rl = lambda: sys.stdin.readline().strip()


T = int(rl())
for tcase in range(T):
    N, L = map(int, rl().split())
    oo = rl().split()
    oo = [int(o, 2) for o in oo]
    dd = rl().split()
    dd = [int(d, 2) for d in dd]
    ans = -1
    for flip in xrange(0, (1 << L)):
        ooo = oo[::]
        cnt_flip = 0
        for i in range(L):
            if (flip & (1 << i)) != 0:
                ooo = [o ^ (1 << i) for o in ooo]
                cnt_flip += 1

        used = [False for i in range(N)]
        for d in dd:
            for idx in range(N):
                if not used[idx] and d == ooo[idx]:
                    used[idx] = True
                    break

        if used.count(True) == N:
            if ans == -1:
                ans = cnt_flip
            else:
                ans = min(ans, cnt_flip)

    if ans == -1:
        print 'Case #%d: NOT POSSIBLE' % (tcase + 1)
    else:
        print 'Case #%d: %d' % (tcase + 1, ans)
