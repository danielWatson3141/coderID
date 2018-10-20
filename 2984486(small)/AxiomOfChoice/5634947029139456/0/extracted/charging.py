read_ints = lambda: [int(i) for i in input().split()]
read_strs = lambda: sorted(int(s, 2) for s in input().split())

INF = float('inf')

def solve():
    n, l = read_ints()
    outlets = read_strs()
    devices = read_strs()

    ans = INF
    for s in range(1 << l):
        flipped = sorted(o ^ s for o in outlets)
        if flipped == devices:
            ans = min(ans, bin(s).count('1'))

    return 'NOT POSSIBLE' if ans == INF else ans

t = read_ints()[0]
for i in range(t):
    print('Case #{0}: {1}'.format(i + 1, solve()))
