def bitsum(n,L):
    count = 0
    for i in range(L):
        if (n& (1<<i)):
            count += 1
    return count

T = int(input())
for case in range(1,T+1):
    N,L = (int(x) for x in input().split())
    initial = [int(x,2) for x in input().split()]
    final = [int(x,2) for x in input().split()]
    best = L+1
    for m in initial:
        change = final[0]^m
        for n in final:
            if (n^change) not in initial:
                break
        else:
            best = min(best,bitsum(change,L))
    if best>L:
        ans = "NOT POSSIBLE"
    else:
        ans = str(best)
    print("Case #",case,": ",ans,sep = '')
