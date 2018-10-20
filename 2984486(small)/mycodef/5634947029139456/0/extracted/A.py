#!/usr/bin/python

f = open("A.in", "r")
f2 = open("A.out", "w")

def main2():
    N, L = map(int, f.readline().split())
    has = map(list, f.readline().split())
    req = map(list, f.readline().split())

    def flip(i):
        for h in has:
            h[i] = '0' if h[i] == '1' else '1'

    def test():
        h2 = sorted(has)
        r2 = sorted(req)
        for i in xrange(N):
            for j in xrange(L):
                if h2[i][j] != r2[i][j]: return False
        return True

    ans = 100

    for i in xrange(1 << L):
        cur = 0
        for j in xrange(L):
            if (i >> j) % 2 == 1: 
                flip(j)
                cur += 1

        if test(): 
            ans = min(ans, cur)
            break
        for j in xrange(L):
            if (i >> j) % 2 == 1: flip(j)
    
    if ans == 100:
        f2.write("NOT POSSIBLE")
    else:
        f2.write(str(ans))


tk = int(f.readline())

for i in xrange(tk):
	f2.write("Case #%d: " % (i + 1))
	main2()
	f2.write('\n')


f.close()
f2.close()
