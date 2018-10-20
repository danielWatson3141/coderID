import copy

T = int(input())
result = ''
best = 'NOT POSSIBLE'

def solve(Mi, Mf, i, t):
    global best
    if (sum([1 for x in Mi if x not in Mf]) == 0):
        best = t
        return

    for k in range(i, L):
        Mt = copy.deepcopy(Mi)
        for l in Mt:
            if (l[k] == '1'):
                l[k] = '0'
            else:
                l[k] = '1'
        solve(Mt, Mf, k+1, t+1)


for Y in range(1, T+1):
    M0 = []
    M1 = []
    
    best = 'NOT POSSIBLE'
    
    N, L = list(map(int, input().split())) #n fichas, n chars ficha
    
    M0 = list(map(list, input().split()))
    M1 = list(map(list, input().split()))

    solve(M0, M1, 0, 0)

    print ('Case #' + str(Y) + ': ' + str(best))

