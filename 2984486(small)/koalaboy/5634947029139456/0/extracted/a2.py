import sys

def find_p(a, f):
    r = []
    for s in a:
        l = [c for c in s]
        for i, b in enumerate(f):
            if b == '1':
                l[i] = '1' if l[i] == '0' else '0'
        r.append(''.join(l))
    return r

f = open(sys.argv[1])

case = int(f.readline().strip())

for n in xrange(1, case + 1):
    d, ef = [ int(i) for i in f.readline().strip().split() ]
    c = 2 ** ef
    efs = f.readline().strip().split()
    dl = f.readline().strip().split()

    ans = 'NOT POSSIBLE'
    for i in xrange(0, c - 1):
        sf = bin(i)[2:].zfill(ef)
        s = find_p(efs, sf)
        ok = True
        for dd in dl:
            if dd not in s:
                ok = False
                break
        if ok:
            ans = sf.count('1')
            break

    print "Case #%d: %s"%(n, ans)
