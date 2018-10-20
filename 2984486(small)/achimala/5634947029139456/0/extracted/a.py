from copy import deepcopy

def flip(a):
    return 1 - a

def possible(start, target):
    N = len(start)
    W = len(start[0])

    possible = {}
    for i in range(W):
        possible[i] = set(range(W))

    for i in range(N):
        s = start[i]
        t = target[i]

        s0 = s.count(0)
        t0 = t.count(0)
        if s0 != t0:
            return False

        sOnes = set()
        sZeros = set()
        for i, x in enumerate(s):
            if x == 1:
                sOnes.add(i)
            else:
                sZeros.add(i)

        tOnes = set()
        tZeros = set()
        for i, x in enumerate(t):
            if x == 1:
                tOnes.add(i)
            else:
                tZeros.add(i)

        for i in sOnes:
            possible[i] &= tOnes
            if not possible[i]:
                return False

        for i in sZeros:
            possible[i] &= tZeros
            if not possible[i]:
                return False

    return True

def memoize(f):
    mem = {}
    def _(*args):
        k = str(args)
        if k in mem:
            return mem[k]
        mem[k] = f(*args)
        return mem[k]
    return _

@memoize
def solve_(S, T, i):
    if i >= len(S):
        return float("inf")

    if possible(S, T):
        return 0

    S2 = deepcopy(S)
    T2 = deepcopy(T)

    S2[i] = map(flip, S2[i])

    if possible(S2, T2):
        return 1

    a = 1 + solve_(S2, T2, i + 1)
    b = solve_(S, T, i + 1)
    return min(a, b)

def solve(S, T):
    N = len(S[0])
    W = len(S)
    St = [[S[j][i] for j in range(W)] for i in range(N)]
    Tt = [[T[j][i] for j in range(W)] for i in range(N)]

    ans = solve_(St, Tt, 0)
    if ans == float("inf"):
        return "NOT POSSIBLE"
    return ans

T = int(raw_input())
for case in range(1, T + 1):
    raw_input() # N, L
    S = map(lambda s: map(int, list(s)), raw_input().split())
    T = map(lambda s: map(int, list(s)), raw_input().split())
    print "Case #{}: {}".format(case, solve(S, T))

