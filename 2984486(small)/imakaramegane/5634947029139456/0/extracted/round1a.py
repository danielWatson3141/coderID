# coding: utf-8
import sys
import os.path
import itertools
from itertools import groupby
import math

def debug(v):
    pass#print(v)

def read(f):
    t = tuple(int(v) for v in f.readline().split())
    debug(t)
    return t

def readf(f):
    t = tuple(float(v) for v in f.readline().split())
    debug(t)
    return t

def readstr(f):
    t = tuple(v for v in f.readline().split())
    debug(t)
    return t

def answer(f, X, Y):
    out = "Case #{}: {}".format(X, Y)
    f.write(out)
    f.write("\n")
    print(out)

def is_ok(cons, dev, ptn):
    cons =[switch(elec, ptn) for elec in cons]
    for c, d in zip(sorted(cons), sorted(dev)):
        if c != d:
            return False
    return True

def switch(elec, ptn):
    elec = list(elec)
    for i in range(len(elec)):
        if ptn[i] == "1":
            elec[i] = "1" if elec[i] == "0" else "0"
    return "".join(elec)

def main(inf, outf):
    T, = read(inf)
    for casenmbr in range(1, T + 1):
        N, L = read(inf)
        cons = readstr(inf)
        dev  = readstr(inf)

        for ptn in (bin(v)[2:].zfill(L) for v in range(pow(2,L))):
            if is_ok(cons, dev, ptn):
                ans = ptn.count("1")
                break
        else:
            ans = "NOT POSSIBLE"

        answer(outf, casenmbr, ans)


if __name__=="__main__":
    infname = sys.argv[1]
    outfname = os.path.splitext(infname)[0] + ".out"
    with open(infname, "r") as inf:
        with open(outfname, "w") as outf:
            main(inf, outf)
