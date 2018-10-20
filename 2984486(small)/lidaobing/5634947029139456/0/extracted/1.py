import sys

def foo3(n):
    res = 0
    while n > 0:
        res += n % 2
        n //= 2
    return res

def foo2(a, b, n):
    n2 = n
    i = 0
    while n > 0:
        if n % 2 == 1:
            for i2 in range(len(a)):
                a[i2][i] = chr(97-ord(a[i2][i]))
        n //= 2
        i += 1
    a.sort()
    if a == b:
        return foo3(n2)
    return 1000


def foo(ifile):
    ifile.readline()
    a = ifile.readline().split()
    b = ifile.readline().split()
    b.sort()
    b = [list(x) for x in b]

    n = len(a[0])

    res = 1000

    for i in range(2**n):
        t = foo2([list(x) for x in a], b, i)
        if t < res:
            res = t
    if res == 1000:
        return 'NOT POSSIBLE'
    return res



def main(ifile):
    n = int(ifile.readline().strip())
    for i in range(n):
        print 'Case #%s: %s' % (i+1, foo(ifile))

main(sys.stdin)

