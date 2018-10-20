#!/usr/bin/env python3

num_cases = int(input())
N = input()

for case in range(1, num_cases+1):
    vals = [int(n) for n in input().split()]

    count = 0
    for x,y in enumerate(vals):
        if x>y:
            count += 1
    if count > 482:
        result = "GOOD"
    else:
        result = "BAD"


    print("Case #{}: {}".format(case, result))
    
