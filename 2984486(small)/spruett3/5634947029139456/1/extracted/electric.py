np="NOT POSSIBLE"

T=int(raw_input())
def flip(i, cur):
    return map(lambda x: x ^ (1 << i), cur)

def bits_set(x):
    return bin(x).count('1')

def mask_works(m, starts, goal):
    return set(map(lambda x: x ^ m, starts)) == goal
def minf(starts, ends):
    masks = []
    s = starts[0]
    for e in ends:
        masks.append(s ^ e)

    goal = set(ends)
    
    masks.sort(key=bits_set)
    for m in masks:
        if mask_works(m, starts, goal):
            return bits_set(m)
    return -1
for i in range(T):
    N,L = map(int, raw_input().split())
    starts = map(lambda s: int(s, 2), raw_input().split())
    ends = map(lambda s: int(s, 2), raw_input().split())
    x = minf(starts, ends)
    if x >= 0:
        print 'Case #%d: %d' % (i + 1, x)
    else:
        print 'Case #%d: %s' % (i + 1, np)
