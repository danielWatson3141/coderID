import sys
Stat = []
def solve(num):
    N = int(input())
    P = list(map(int, input().split()))
    c = 0
    for i in range(N):
        if P[i] == i:
            c += 1
    Stat.append((c, num))

T = int(input())
for i in range(T):
    solve(i + 1)
Stat.sort()

Ans = dict()
for i in range(60):
    x, y = Stat[i]
    Ans[y] = "YES"
for i in range(60, 120):
    x, y = Stat[i]
    Ans[y] = "NO"

for i in range(1, T + 1):
    print("Case #" + str(i) + ": " + Ans[i])

