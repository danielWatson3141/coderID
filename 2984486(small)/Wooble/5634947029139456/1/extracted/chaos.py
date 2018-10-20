#!/usr/bin/env python3

def reqmask(init, req):
    mask = []
    for x, y in zip(list(init), list(req)):
        if x == y:
            mask.append('0')
        else:
            mask.append('1')
    return ''.join(mask)

def maskall(initlist, mask):
    retlist = []
    for init in initlist:
        sinit = list(init)
        for pos, char in enumerate(mask):
            if char == "1":
                sinit[pos] = '1' if sinit[pos] == '0' else '0'
        retlist.append(''.join(sinit))
    return retlist

num_cases = int(input())
for case in range(1, num_cases+1):
    N, L = (int(x) for x in input().split())
    initial_flows = input().split()
    required_flows = input().split()
    reqset = set(required_flows)
    result = "NOT POSSIBLE"

    if reqset == set(initial_flows):
        result = 0
    else:
        best = L+1
        for req in required_flows:
            mask = reqmask(initial_flows[0], req)
            if mask.count("1") < best:
                newflows = maskall(initial_flows, mask)
                if set(newflows) == reqset:
                    best = mask.count("1")
        if best <= L:
            result = best


    print("Case #{}: {}".format(case, result))
    
