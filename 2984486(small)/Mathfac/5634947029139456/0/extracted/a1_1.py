import sys

sys.stdin = open("input.in")
sys.stdout = open("output.txt", "w")
tn = int(sys.stdin.readline())
setb = set()
sv = [0, 0]
a = 0
n = 0
m = 0
res = 0

def un(a,i):
    c = a[i]
    if c == '1':
        c = '0'
    else:
        c = '1'

    rs = ""
    for id, cc in enumerate(a):
        if id == i:
            rs += c
        else:
            rs += cc

    return  rs

def check():
    for w in a:
        if not w in setb:
            return 0
    return 1


def search(st):
    if st == n:
        return check()
    else:
        if search(st + 1):
            return 1
        else:
            if sv[st] == 1:
                for j in xrange(m):
                    #a[j][st] = (a[j][st] + 1) % 2
                    #a[j][st] = un(a[j][st])
                    a[j] = un(a[j],st)
                if search(st + 1):
                    global res
                    res += 1
                    return 1
                else:
                    for j in xrange(m):
                        a[j] = un(a[j],st)
                    return 0
            else:
                return 0







for ti in range(tn):
    [m, n] = [int(x) for x in sys.stdin.readline().split()]
    a = [w for w in sys.stdin.readline().split()]
    b = [w for w in sys.stdin.readline().split()]

    sv = [0]*n
    imps = 0
    res = 0

    for i in xrange(n):
        suma = 0
        sumb = 0
        for j in xrange(m):
            suma += int(a[j][i])
            sumb += int(b[j][i])

        #print suma, sumb
        if not (suma == sumb) and not (suma == m - sumb):
            print "Case #%s: NOT POSSIBLE" % (ti + 1)
            imps = 1
            break
        elif suma == m - suma:
            sv[i] = 1
        elif (suma == m - sumb):
            res += 1
            for j in xrange(m):
                #a[j][i] = (a[j][i] + 1) % 2
                a[j] = un(a[j],i)

    if not imps:
        setb = {b[j] for j in xrange(m)}
        if search(0):
            print "Case #%s:" % (ti + 1), res
        else:
            print "Case #%s: NOT POSSIBLE" % (ti + 1)

        #print a
        #print b
        #print sv



sys.stdout.close()
