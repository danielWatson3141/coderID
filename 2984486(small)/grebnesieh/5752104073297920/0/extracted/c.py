input = open("c.in" , "r")
output = open("c.out" , "w")

T = int(input.readline())

for i in range(1, T + 1):
    N = int(input.readline())
    L = map(int, input.readline().split(" "))
    c2 = 0
    for j in range(N):
        if L[j] <= j :
            c2 += 1
    if c2 >= 485:
        ans = "GOOD"
    else:
        ans = "BAD"
    print ans
    output.write("Case #" + str(i) + ": " + ans + "\n")

input.close()
output.close()
