import random,sys
sys.setrecursionlimit(100000)

def fixes(perm):
    count = 0
    for i,j in enumerate(perm):
        if i==j:
            count+= 1
    return count


T = int(input())
for case in range(1,T+1):
    N = int(input())
    perm = [int(x) for x in input().split()]
    if fixes(perm)==1:
        ans = "GOOD"
    else:
        ans = "BAD"
    print("Case #",case,": ",ans,sep = '')
