from itertools import *
import sys

debug = False

def log(*argv):
    if debug:
        print " ".join(imap(str, argv))


def main(f, case):
    N,L = map(int, f.readline().split())
    e = f.readline().split()
    r = f.readline().split()
    log("N :", N, ", L :", L)
    log("e :", e)
    log("r :", r)
    R = map(lambda x: int(x, 2), r)
    log("R :", R)
    t = []
    for i in e:
        s = int(i, 2)
        t += map(lambda x:x^s, R)
    t = sorted(t)
    log("t :", t)
    n = 0
    l = t[0]
    for i in t:
        log ("i : ", i, "l : ", l, "n :", n)
        if i == l:
            n += 1
            if n == N: 
                print "Case #" + str(case) + ":", bin(l).count('1')
                return
        else:
            n = 1
            l = i
    print "Case #" + str(case) + ":", "NOT POSSIBLE"

with open(sys.argv[1]) as f:
    N = int(f.readline())
    for i in xrange(N):
        main(f, i+1)
