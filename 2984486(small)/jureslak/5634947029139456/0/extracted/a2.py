def flip(have, x):
    for j in range(len(have)):
        have[j][x] = "10"[int(have[j][x])]

t = int(input())
for asdf in range(t):
    n, l = map(int, input().split())
    have = list(map(list, input().split()))
    want = list(map(list, input().split()))

    want.sort()

    minc = float("inf")
    for j in range(1 << l):
        c = 0
        for k in range(l):
            if j & (1 << k) != 0:
                flip(have, k)
                c += 1
        have.sort()
        if have == want:
            minc = min(minc, c)
        for k in range(l):
            if j & (1 << k) != 0:
                flip(have, k)
                c += 1

    if minc == float("inf"):
        print("Case #{}: NOT POSSIBLE".format(asdf+1))
    else:
        print("Case #{}: {}".format(asdf+1, minc))
