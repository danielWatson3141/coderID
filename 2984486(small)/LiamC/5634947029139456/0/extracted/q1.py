from itertools import combinations
from copy import deepcopy
t = int(input())

def flip(outlets, switches):
    for o in outlets:
        for s in switches:
            if o[s] == '1':
                o[s] = '0'
            else:
                o[s] = '1'
    return outlets

def solve(outlets, required, l):
    for i in range(l+1):
        for switches in combinations([j for j in range(l)],i):
            result = list(flip(deepcopy(outlets),switches))
            if sorted(result) == sorted(required):
                answer = len(switches)
                return answer
    return "NOT POSSIBLE"

for case in range(1,t+1):
    n,l = map(int,input().split())
    outlets = input().split()
    outlets = list(map(list, outlets))
    required = input().split()
    required = list(map(list, required))
    answer = solve(outlets,required,l)
    print("Case #{}: {}".format(case,answer))

    

