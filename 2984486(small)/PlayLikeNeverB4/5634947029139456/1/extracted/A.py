import math

input = open('date.in', 'r')
output = open('date.out', 'w')

def pairup(node, N, G, v, st, dr):
    if v[node]:
        return False
    v[node] = True

    for i in range(N):
        if G[node][i] and st[i] == -1:
            st[i] = node
            dr[node] = i
            return True

    for i in range(N):
        if G[node][i] and pairup(st[i], N, G, v, st, dr):
            st[i] = node
            dr[node] = i
            return True

    return False

def can(need, O, D, N):
    G = [ [ False for i in range(N) ] for j in range(N) ]
    for i in range(N):
        for j in range(N):
            if (D[i] ^ O[j]) == need:
                G[i][j] = True

    ok = True
    st = [ -1 for i in range(N) ]
    dr = [ -1 for i in range(N) ]
    match = 0
    while ok:
        ok = False
        v = [ False for i in range(N) ]
        for i in range(N):
            if dr[i] == -1 and pairup(i, N, G, v, st, dr):
                ok = True
                match += 1

    return match == N

T = int(input.readline())
for t in range(T):
    line = input.readline().split(' ')
    N = int(line[0])
    L = int(line[1])

    outlets = input.readline().split(' ')
    devices = input.readline().split(' ')

    O = [ long(outlets[i], 2) for i in range(N) ]
    D = [ long(devices[i], 2) for i in range(N) ]

    ans = 2 * L
    for i in range(N):
        need = D[0] ^ O[i]
        if can(need, O, D, N):
            ans = min(ans, bin(need).count('1'))

    if ans == 2 * L:
        ans = "NOT POSSIBLE"
    output.write('Case #{}: {}\n'.format(t + 1, ans))

    print t

input.close()
output.close()