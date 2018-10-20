def solve(num):
    N, L = map(int, input().split())
    ANS = 1000
    Outlets = input().split()
    Devices = input().split()
    for i in range(N):
        Outlets[i] = int(Outlets[i], 2)
    B = set()
    for elem in Devices:
        B.add(int(elem, 2))
    for mask in range(2 ** L):
        A = set()
        for elem in Outlets:
            A.add(elem ^ mask)
        if A == B:
            ANS = min(ANS, bin(mask).count("1"))
    print("Case #" + str(num) + ": ", end = "")
    if ANS == 1000:
        print("NOT POSSIBLE")
    else:
        print(ANS)

T = int(input())
for i in range(T):
    solve(i + 1)


