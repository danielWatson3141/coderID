#!/usr/bin/env python
import itertools
def switch(a, n):
    temp = 2**(n-1)
    return a ^ temp

with open("A-small-attempt0.in", "r") as fin:
    N = int(fin.readline())
    fout = open("A-small-attempt0.out", "w")

# read the input
    for i in xrange(N):
        para = map(int, fin.readline().split())
        d = para[0]
        l = para[1]
        device = fin.readline().split()
        length = fin.readline().split()
        for p in xrange(len(device)):
            device[p] = int(device[p], 2)
            length[p] = int(length[p], 2)
        device.sort()
        length.sort()
        rd = list(device)
        rl = list(length)
        result = -1
        if rd == rl:
            result = 0
        else:
            for p in xrange(1, l+1):
                c = itertools.combinations(range(1,l+1), p)
                for n in c:
                    for q in n:
                        for nn in xrange(d):
                            length[nn] = switch(length[nn], q)
                    length.sort()
                    if length == device:
                        result = p
                        break
                    else:
                        length = list(rl)
                try:
                    if (result > 0):
                        break
                except:
                    pass
        fout.write("Case #" + str(i+1) + ": ")
        if result == -1:
            fout.write("NOT POSSIBLE\n")
        else:
            fout.write(str(result) + "\n")
        

fin.close()
fout.close()
