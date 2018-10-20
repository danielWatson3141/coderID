from itertools import chain, combinations

def powerset_generator(i):
    for subset in chain.from_iterable(combinations(i, r) for r in range(len(i)+1)):
        yield set(subset)

def swp (c):
    if c == '0':
        return '1'
    else:
        return '0'

def flip (S, x):
    ans = []
    for i in range (0, len(S)):
        if i in x:
            ans.append(swp(S[i]))
        else:
            ans.append(S[i])
    return ''.join(ans)

if __name__ == "__main__":
    T = int(raw_input())
    for i in range (1, T+1):
        N, L = [int(x) for x in raw_input().split()]
        init = raw_input().split()
        reqd = raw_input().split()
        init.sort()
        reqd.sort()
        flp = init
        ans = 10**9
        rg = set(list(range(0, L)))
        if init != reqd:
            for x in powerset_generator(rg):
                flp = [flip(y, x) for y in init]
                flp.sort()
                #print x, flp
                if flp == reqd:
                    size = len(x)
                    if size < ans:
                        ans = size
        else:
            ans = 0

        print "Case #%d:" % (i),
        if ans == 10**9:
            print "NOT POSSIBLE"
        else:
            print ans
