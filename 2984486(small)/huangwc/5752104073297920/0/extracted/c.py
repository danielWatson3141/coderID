import sys

#sys.stdin = open('c.in', 'r')
#sys.stdout = open('c.out', 'w')

sys.stdin = open('C-small-attempt3.in', 'r')
sys.stdout = open('c-small.out', 'w')

# sys.stdin = open('C-large.in', 'r')
# sys.stdout = open('c-large.out', 'w')

T = int(input())

ratio = []

for t in range(1, T+1):

    N = int(input())

    p = list(map(int, input().split()))
    #print('\t'.join(map(str, p)))

    ans = sum([1 if k+1==p[k] else 0 for k in range(N)])
    # print(ans)


    print('Case #%d: %s' % (t, 'BAD' if ans != 1 else 'GOOD'))


sys.stdin.close()
sys.stdout.close()