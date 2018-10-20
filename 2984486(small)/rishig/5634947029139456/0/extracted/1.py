import sys
sys.path.insert(0, '/home/rishig/codejam/')
from library import *
from collections import defaultdict

def flip(bit, mask):
    if mask < 1: # 0 or -1
        return bit
    else:
        return str(1-int(bit))

def match(dev, nout, nmask):
    for i in range(len(dev())):
        if not (nmask[i] or (dev[i] == nout[i])):
            return False
    return True

def badd(a,b):
    return [(i+j) %2 for (i,j) in zip(a,b)]

def beq(a,b):
    for i,j in zip(a,b):
        if i != j: return False
    return True

def solvecase(case):
    N,L = readints(f)
    if N == 1:
        xxouts = [readstr(f)]
        xxdevs = [readstr(f)]
    else:
        xxouts = readstrs(f)
        xxdevs = readstrs(f)
    outs = [[int(x) for x in out] for out in xxouts]
    devs = [[int(x) for x in dev] for dev in xxdevs]

    def fits(dev, msk):
        d = badd(dev,msk)
        for out in outs:
            if beq(d, out):
                return True
        return False

    mins = L+1
    for i in range(N):
        mask = badd(devs[0],outs[i])
        ver = True
        for dev in devs:
            if not fits(dev, mask):
                ver = False
                break
        if ver: # every device fits
            mins = min(mins, sum(mask))
    if mins <= L:
        return mins
    else: return 'NOT POSSIBLE'

if __name__ == '__main__':
    f = file(sys.argv[1])
    T = readint(f)
    # sys.stderr.write(strftime("%H:%M:%S\n"))
    for case in range(1,T+1):
        ans = solvecase(case)
        print 'Case #%d: %s' % (case, ans)
#         if T <= 15 or case == 1 or case % max((T//10),5) == 0:
#             sys.stderr.write('completed case %d, ' % case)
#             sys.stderr.write(strftime("%H:%M:%S\n"))
