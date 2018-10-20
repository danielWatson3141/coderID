import sys
import math
import itertools

def main():
    #infile = open('in')
    #infile = open('A-large.in')
    infile = open('A-small-attempt5.in')
    #infile = open('A-small-practice.in')
    #infile = open('A-large-practice.in')
    outfile = open('out', 'w')
    T = long(infile.readline())
    for i in xrange(T):
        outfile.write('Case #'+str(i+1)+': ' + solve(infile) + '\n')

def solve(infile):
    n, l = map(long, infile.readline().split())
    outl = map(list, infile.readline().split())
    dev = map(list, infile.readline().split())
    def flip(ind):
        for j in range(n):
            outl[j][ind] = '0' if outl[j][ind] == '1' else '1'
    res = 0
    ok = True
    spec = []
    for i in range(l):
        need = 0
        have = 0
        for j in range(n):
            if dev[j][i] == '1':
                need += 1
            if outl[j][i] == '1':
                have += 1
        if need != have:
            if need == (n-have):
                res += 1
                flip(i)
            else:
                ok = False
                break
        else:
            spec.append(i)
    if not ok:
        return 'NOT POSSIBLE'
    else:
        outl.sort()
        dev.sort()
        ok = outl == dev
        if ok:
            return str(res)
        else:
            for cnt in range(len(spec)):
                for c in itertools.combinations(spec, cnt):
                    for ind in c:
                        res += 1
                        flip(ind)
                    outl.sort()
                    ok = outl == dev
                    if not ok:
                        for ind in c:
                            res -= 1
                            flip(ind)
                    else:
                        break
                if ok : break
            return str(res) if ok else 'NOT POSSIBLE'
if __name__=='__main__':
    main()
