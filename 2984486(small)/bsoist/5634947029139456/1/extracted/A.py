import os, sys
from itertools import repeat, starmap
lines = [line.strip() for line in open("%s" % sys.argv[1])][::-1]

def flip(s,n):
    s,n = map(int,s),map(int,n)
    return ''.join([['0','1','0'][i+j] for i,j in zip(s,n)])

def getBin(length):
    i = 0
    while True:
        n = bin(i)[2:]
        yield "0" * (length - len(n)) + n
        i += 1

for case in range(int(lines.pop())):
    N, L = map(int, lines.pop().split(' '))
    outlets = lines.pop().split(' ')
    devices = lines.pop().split(' ')
    bins = getBin(L)
    limit = int("1" * L, 2)
    while True:
        flipset = bins.next()
        flips = flipset.count('1')
        if not set(devices) - set(outlets):
            break
        if int(flipset,2) > limit:
            flips = "NOT POSSIBLE"
            break
        new_outlets = list(starmap(flip,zip(outlets,repeat(flipset,N))))
        if not set(devices) - set(new_outlets):
            break
    print "Case #%s: %s" % ((case+1), flips)


