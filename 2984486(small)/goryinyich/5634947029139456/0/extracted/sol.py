import sys

def bitcount(n):
    res = 0
    while n > 0:
        res += n&1
        n >>= 1
    return res

def fun(mask):
    c = sorted([a[i]^mask for i in range(n)])
    if cmp(b, c) == 0:
        return bitcount(mask)
    else:
        return 1000000
    

tc = int(sys.stdin.readline())
for ic in range(tc):
    tokens = sys.stdin.readline().strip().split()
    n = int(tokens[0])
    l = int(tokens[1])
    a = sorted([int(t, 2) for t in sys.stdin.readline().strip().split()])
    b = sorted([int(t, 2) for t in sys.stdin.readline().strip().split()])
    res = 1000000

    for i in range(n):
        mask = a[0]^b[i]
        res = min(res, fun(mask))
    print 'Case #%d: %s' % (ic+1, str(res) if res <= l else 'NOT POSSIBLE')
    
