from collections import defaultdict

def check(outd, devd):
    return all(outd[a] == devd[a] for a in outd.keys()) and all(devd[a] == outd[a] for a in devd.keys())

def countBits(x, n):
    counter = 0
    for i in range(n):
        if ((1 << i) & x) != 0:
            counter += 1
    return counter

def solve(outlets, devs, n):
    outd = defaultdict(int)
    for out in outlets:
        outd[out] += 1

    devd = defaultdict(int)
    for d in devs:
        devd[d] += 1

    winner = 10**10

    for i in range(1 << n):
        moutd = defaultdict(int)
        for out in outlets:
            moutd[out ^ i] += outd[out]
        if check(moutd, devd):
            bits = countBits(i, n)
            if bits < winner:
                winner = bits

    return None if winner == 10 ** 10 else winner

for t in range(1, int(input())+1):
    n = int(input().split(" ")[1])
    outs = [int(s,2) for s in input().split(" ")]
    devs = [int(s,2) for s in input().split(" ")]
    ans = solve(outs, devs, n)
    print("Case #" + str(t) + ": " + (str(ans) if ans != None else "NOT POSSIBLE"))

