import copy
import itertools
T = int(raw_input())

def make_arr(s):
    ls = []
    for i in s:
        ls.append(int(i))
    return ls

for kei in xrange(T):
    N, L = [int(x) for x in raw_input().split()]
    dev = []
    for s in raw_input().split():
        dev.append(make_arr(s))
    dev = sorted(dev)
    out = []
    for s in raw_input().split():
        out.append(make_arr(s))
    # print(dev)
    # print(out)
    min_flips = L+1
    for row in out:
        flips = 0
        cout = copy.deepcopy(out)
        # print 'match', row, dev[0]
        # print 'orig', cout
        for i in xrange(L):
            if row[i] != dev[0][i]:
                flips += 1
                for j in xrange(N):
                    cout[j][i] = 1-cout[j][i]
        cout.sort()
        # print 'now', cout
        # print 'dev', dev

        ok =  True
        for l1, l2 in itertools.izip(dev, cout):
            # print l1, l2
            if l1 != l2:
                ok = False
                break
        # print '*'*30
        if ok:
            min_flips = min(min_flips, flips)
    if min_flips == L+1:
        print 'Case #%d: NOT POSSIBLE' % (kei+1,)
    else:
        print 'Case #%d: %d' % (kei+1, min_flips)



