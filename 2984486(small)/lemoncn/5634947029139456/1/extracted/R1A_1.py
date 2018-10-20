import math

def conv(x):
    x = x.strip()
    r = 0L
    for i in range(len(x)):
        if x[i] is '1':
            r ^= 1 << (len(x) - 1 - i)
    return r


def num_of_one(x):
    cnt = 0
#    b = []
    ox = x
    while x:
#        try:
#            b.append(int(math.log(x - (x & (x - 1))) / math.log(2)))
#        except ValueError:
#            b.append(int(math.log(x) / math.log(2)))

        x &= x-1
        cnt += 1
    return ox, cnt

def search(mat, i, to_search, current_situation):
    if i == len(mat):
        return True
    for j in range(len(mat[i])):
        if mat[i][j] == to_search and ((1 << j) & current_situation) == 0:
            if search(mat, i + 1, to_search, current_situation ^ (1 << j)):
                return True
    return False

fn = raw_input()
rfp = open(fn + '.in', 'r')
wfp = open(fn + '.out', 'w')
T = int(rfp.readline())
for k in range(T):
    N, L = map(lambda(x): int(x), rfp.readline().split(' '))
    a = map(conv, rfp.readline().split(' '))
    b = map(conv, rfp.readline().split(' '))
    mat = []
    for i in a:
        tmp = []
        for j in b:
            tmp.append(num_of_one(i ^ j))
        mat.append(tmp)
    mincnt = L + 1
    for i in range(N):
        r = 1 << i
        cnt = mat[0][i][1]
        if mincnt > cnt:
            if search(mat, 1, mat[0][i], r):
                mincnt = cnt
    result_string = 'Case #{0}: '.format(k+1)
    if mincnt == L + 1:
        result_string += 'NOT POSSIBLE'
    else:
        result_string += str(mincnt)
    wfp.write(result_string + '\n')
    print result_string