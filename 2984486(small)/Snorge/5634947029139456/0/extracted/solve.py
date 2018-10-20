import sys
sys.setrecursionlimit(100000)

# functions
def t(s, p):
    r = s[:p]
    if s[p] == '0':
        r += 1
    else:
        r += 0
    r += s[p+1:]

def g(o, m):
    res = []
    for p in o:
        r = ""
        for c in range(len(m)):
            if m[c] == '1':
                if p[c] == '1':
                    r += '0'
                else:
                    r += '1'
            else:
                r += p[c]
        res.append(r)
    return set(res)

    


# get the file
f = open(sys.argv[1])

count = int(f.readline().strip())

# to list
for i in range(count):
    done = False
    a = f.readline().strip().split()
    N = int(a[0])
    L = int(a[1])
    o = f.readline().strip().split()
    d = set(f.readline().strip().split())

    q = []
    for j in range(2**L):
        q.append("{num:0{width}b}".format(width=L,num=j))

    sq = sorted(q, key=lambda k: k.count('1'))

    for s in sq:
        r = g(o,s)
        if r == d:
            print("Case #" + str(i+1) + ": " + str(s.count('1')))
            done = True
            break


    if not done:
        print("Case #" + str(i+1) + ": NOT POSSIBLE")
