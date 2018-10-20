min_cnt = {"cnt": 0}

def hoge(A, B, mask, cnt):
    if mask == 0:
        A.sort()
        B.sort()
        if tuple(A) == tuple(B) and cnt < min_cnt["cnt"]:
            min_cnt["cnt"] = cnt
        return

    A0 = [a for a in A if a&mask == 0]
    A1 = [a for a in A if a&mask != 0]
    B0 = [b for b in B if b&mask == 0]
    B1 = [b for b in B if b&mask != 0]

    # don't flip
    if len(A0) == len(B0):
        hoge(A, B, mask >> 1, cnt)

    # flip
    if len(A0) == len(B1):
        hoge([a^mask for a in A], B, mask >> 1, cnt + 1)

def main():
    T = int(raw_input())
    for i in range(T):
        (N, L) = [int(x) for x in raw_input().split()]
        A = [long(x, 2) for x in raw_input().split()]
        B = [long(x, 2) for x in raw_input().split()]
        min_cnt["cnt"] = L + 1
        hoge(A, B, 1 << (L-1), 0)
        ans = min_cnt["cnt"]
        if ans <= L:
            print "Case #{0}: {1}".format(i + 1, ans)
        else:
            print "Case #{0}: {1}".format(i + 1, "NOT POSSIBLE")

if __name__ == '__main__':
    main()
