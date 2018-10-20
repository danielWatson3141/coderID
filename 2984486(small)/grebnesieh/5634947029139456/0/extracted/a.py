input = open("a.in" , "r")
output = open("a.out" , "w")

T = int(input.readline())

def solve(N, L, G, R):
    f = []
    for i in range(2**L - 1):
        G2 = G[:]
        z = map(int, list(bin(i)[2:].zfill(L)))
        for j in range(L):
            if z[j] == 1:
                for k in range(N):
                    G2[k][j] = str(1 - int(G2[k][j]))
        if sorted(G2) == sorted(R):
            f.append(sum(z))
    if len(f) == 0:
        return -1
    else:
        return min(f)

for i in range(1, T + 1):
    N, L = map(int, input.readline().split(" "))
    G = map(list, input.readline()[:-1].split(" "))
    R = map(list, input.readline()[:-1].split(" "))
    s = solve(N, L, G, R)
    if s != -1:
        ans = str(s)
    else:
        ans = "NOT POSSIBLE"
    output.write("Case #" + str(i) + ": " + ans + "\n")

input.close()
output.close()
