from random import randint
T = int(input())
for t in range(1,T+1):
    N = int(input())
    nums = [int(x) for x in input().split()]
    out = "BAD"
    if (randint(0,1) == 0):
        out = "GOOD"
    print("Case #{0}: {1}".format(t, out))
