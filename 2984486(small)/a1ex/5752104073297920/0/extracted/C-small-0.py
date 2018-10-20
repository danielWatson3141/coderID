import sys, string
from copy import copy, deepcopy

def readlist():
	return [int(x) for x in sys.stdin.readline().strip().split(" ")]

def readint():
	return int(sys.stdin.readline())

T = readint()

def goodalg(N):
    a = range(N)
    for k in range(N):
        p = randint(k, N-1)
        aux = a[k]
        a[k] = a[p]
        a[p] = aux
    return a

def badalg(N):
    a = range(N)
    for k in range(N):
        p = randint(0, N-1)
        aux = a[k]
        a[k] = a[p]
        a[p] = aux
    return a

def testalg(alg, N, M):
    cnt = [0]*N
    for i in range(M):
        r = alg(N)
        cnt = [cnt[i] + r[i] for i in range(N)]
    return cnt

def count_inversion(lst):
    return merge_count_inversion(lst)[1]

def merge_count_inversion(lst):
    if len(lst) <= 1:
        return lst, 0
    middle = int( len(lst) / 2 )
    left, a = merge_count_inversion(lst[:middle])
    right, b = merge_count_inversion(lst[middle:])
    result, c = merge_count_split_inversion(left, right)
    return result, (a + b + c)

def merge_count_split_inversion(left, right):
    result = []
    count = 0
    i, j = 0, 0
    left_len = len(left)
    while i < left_len and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            count += left_len - i
            j += 1
    result += left[i:]
    result += right[j:]
    return result, count        

def testinv(alg, N, M):
    inv = []
    for i in range(M):
        r = alg(N)
        inv.append(count_inversion(r))
    return inv

for t in range(T):
    N = readint()
    P = readlist()
    
    np = count_inversion(P)
    thr = 249765
    print "Case #%d: %s" % (t+1, "BAD" if np < thr else "GOOD")
