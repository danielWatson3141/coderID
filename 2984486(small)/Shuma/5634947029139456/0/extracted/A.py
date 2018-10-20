Tc = input()
for tc in xrange(1, Tc + 1):
    N, L = map(int, raw_input().split())
    P = map(lambda x: int(x, 2), raw_input().split())
    D = map(lambda x: int(x, 2), raw_input().split())
    def solve():
        ans = 1 << 30
        for b in xrange(1 << L):
            A = [0] * (1 << L)
            for p in P:
                A[p] += 1
            for d in D:
                A[d ^ b] -= 1
                if(A[d ^ b] < 0):
                    break
            else:
                ans = min(ans, sum(1 if c == "1" else 0 for c in format(b, "b")))
        if ans == 1 << 30:
            ans = "NOT POSSIBLE"
        return "Case #{}: {}".format(tc, ans)
    print solve()
