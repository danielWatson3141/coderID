#!/usr/bin/env python

from sys import stdin

tt = stdin.readline()

tt = eval(tt)

def switch(stri):
    ret = 0
    for i in range(0, len(stri)):
        add = 0
        if stri[i] == '1':
            add = 1
        ret = ret * 2 + add
    return ret

for cc in range(1, tt + 1):
    tmp = stdin.readline()
    tmp = tmp.split()
    n = eval(tmp[0])
    l = eval(tmp[1])
    tmp = stdin.readline()
    tmp = tmp.split()
    outlet = []
    dev = []
    for i in tmp:
        outlet.append(switch(i))
    tmp = stdin.readline()
    tmp = tmp.split()
    for i in tmp:
        dev.append(switch(i))
    dev = sorted(dev)
    tj = dev[0]
    res = "NOT POSSIBLE"
    for ti in outlet:
        tmpres = 0
        mask = tj ^ ti
        tmpm = mask
        while tmpm > 0:
            if tmpm & 1 == 1:
                tmpres += 1
            tmpm >>= 1
        if tmpres > res:
            continue
        tmplet = list(outlet)
        for i in range(0, n):
            tmplet[i] ^= mask
        tmplet = sorted(tmplet)
        flag = 1
        for i in range(0, n):
            if tmplet[i] != dev[i]:
                flag = 0
                break
        if flag == 0:
            continue
        res = tmpres
    if type(res) == str:
        print "Case #%d: %s" % (cc, res)
    else:
        print "Case #%d: %d" % (cc, res)
