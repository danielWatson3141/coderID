import math

input = open('date.in', 'r')
output = open('date.out', 'w')

def dfsSize(node, prev):
    global sz
    sz[node] = 1
    for x in G[node]:
        if x != prev:
            sz[node] += dfsSize(x, node)
    return sz[node]

def dfs(node, prev):
    global sz

    children = 0
    for x in G[node]:
        if x != prev:
            children += 1

    if children == 1:
        return sz[node] - 1
    if children > 2:
        val = [ 0 for i in range(children) ]
        idx = 0
        for x in G[node]:
            if x != prev:
                val[idx] = dfs(x, node) - sz[x]
                idx += 1
        val.sort()
        ret = sz[node] - 1
        ret += val[0]
        ret += val[1]
        return ret

    ret = 0
    for x in G[node]:
        if x != prev:
            ret += dfs(x, node)
    return ret

T = int(input.readline())
for t in range(T):
    N = int(input.readline())
    G = [ [] for i in range(N) ]
    for i in range(N - 1):
        line = input.readline().split(' ')
        x = int(line[0]) - 1
        y = int(line[1]) - 1
        G[x].append(y)
        G[y].append(x)

    ans = N
    for root in range(N):
        sz = [ 0 for i in range(N) ]
        dfsSize(root, -1)
        crt = dfs(root, -1)
        ans = min(ans, crt)

    output.write('Case #{}: {}\n'.format(t + 1, ans))

    print t

input.close()
output.close()