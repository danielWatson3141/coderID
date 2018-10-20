#!/usr/bin/env python3

T = int(input())
for t in range(1,T+1):
    N, L = list(map(int, input().split()))
    initial = list(map(lambda x:int(x, 2), input().split()))
    expected = set(map(lambda x:int(x, 2), input().split()))

    best = L + 1
    for i in range(0, 2**L):
        new = set(map(lambda x:x^i, initial))
        if new == expected:
            bit_length = bin(i).count('1') #int.bit_length(i)
            if bit_length < best:
                best = bit_length
    print("Case #%d: %s" % (t, str(best) if best <= L else "NOT POSSIBLE"))
