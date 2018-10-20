import sys




def foo2(a, b, n, pre):
    if n == len(a[0]):
        return 0
    a1n = [x[:n+1] for x in a]
    an = [x[n] for x in a]
    bn = [x[n] for x in b]
    res = [10000]
    if an == bn:
        res.append(foo2(a, b, n+1, pre+(0,)))
    a2 = [x[:] for x in a]
    for x in a2:
        x[n] = 1 - x[n]
    a2.sort()
    a2n = [x[n] for x in a2]
    if a2n == bn:
        res.append(foo2(a2, b, n+1, pre+(1,))+1)
    return min(res)


def foo(ifile):
    ifile.readline()
    a = ifile.readline().split()
    b = ifile.readline().split()
    a.sort()
    b.sort()
    b = [[ord(y)-ord('0') for y in list(x)] for x in b]
    a = [[ord(y)-ord('0') for y in list(x)] for x in a]
    res = foo2(a, b, 0, ())
    if res == 10000:
        return 'NOT POSSIBLE'
    return res

def main(ifile):
    n = int(ifile.readline().strip())
    for i in range(n):
        print 'Case #%s: %s' % (i+1, foo(ifile))

main(sys.stdin)

