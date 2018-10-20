import sys

#sys.stdin = open('a.in', 'r')
#sys.stdout = open('a.out', 'w')

#sys.stdin = open('A-small-attempt1.in', 'r')
#sys.stdout = open('a-small.out', 'w')

sys.stdin = open('A-large.in', 'r')
sys.stdout = open('a-large.out', 'w')

T = int(input())

global ans, N, L, src, tar


def test(v, k):
    global ans, N, L, src, tar
    '''
    print('***** ', k)
    for i in range(N):
        print(('0'*L+bin(v[i])[2:])[-L:])
    print('------')
    for i in range(N):
        print(('0'*L+bin(tar[i])[2:])[-L:])
    print('')
    #'''
    for (x, y) in zip(v, tar):
        if (x ^ y) >= (1 << L-k-1):
            return False
    return True


def dfs(k, step):

    global ans, N, L, src, tar
    '''
    print('dfs: %d %d' % (k, step))
    print(ans, N, L, src, tar)
    #'''
    if step >= ans:
        return
    if k == L:
        ans = step
        return
    #print(bin(((1 << L-k-1)-1)))
    head = sorted([(x >> (L-1-k) << (L-1-k)) for x in src])
    if test(head, k):
        dfs(k+1, step)
    for i in range(N):
        head[i] ^= (1 << L-k-1)
        src[i] ^= (1 << L-k-1)
    head.sort()
    if test(head, k):
        dfs(k+1, step+1)
    for i in range(N):
        src[i] ^= (1 << L-k-1)


for t in range(1, T+1):

    (N, L) = map(int, input().split())

    src = list(map((lambda x: int(x, 2)), input().split()))
    tar = sorted(map((lambda x: int(x, 2)), input().split()))

    ans = 9999
    dfs(0, 0)

    print('Case #%d: %s' % (t, ('NOT POSSIBLE' if ans == 9999 else ans)))



sys.stdin.close()
sys.stdout.close()