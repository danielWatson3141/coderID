def DFS(G, Save, P, Visited, curr, p):
    Visited[curr] = True
    if Save[curr]:
        P[curr] = p
        new_p = curr
    else:
        new_p = p
    for u in G[curr]:
        if not Visited[u] and Save[u]:
            DFS(G, Save, P, Visited, u, new_p)

def solve(num):
    N = int(input())
    ANS = N - 1
    G = [[] for i in range(N + 1)]
    for i in range(N - 1):
        x, y = map(int, input().split())
        G[x].append(y)
        G[y].append(x)
    for mask in range(2 ** N):
        Save = [None]
        for i in range(N):
            Save.append(bool(mask % 2))
            mask //= 2
        ans = Save.count(False)
        if ans >= ANS:
            continue
        for root in range(1, N + 1):
            if Save[root]:
                # Перебираем корень дерева
                OK = True
                P = [0] * (N + 1)
                Visited = [False] * (N + 1)
                DFS(G, Save, P, Visited, root, 0)
                for i in range(1, N + 1):
                    if Save[i] and not Visited[i]:
                        OK = False
                        break
                if not OK:
                    continue
                for i in range(1, N + 1):
                    c = P.count(i)
                    if c != 0 and c != 2:
                        OK = False
                        break
                if OK:
                    ANS = min(ANS, ans)
                    break

    print("Case #" + str(num) + ": ", end = "")
    print(ANS)

T = int(input())
for i in range(T):
    solve(i + 1)


