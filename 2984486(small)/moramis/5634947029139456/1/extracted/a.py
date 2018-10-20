#! /usr/bin/python

import sys, itertools

def getline():
    return sys.stdin.readline().strip()

DEBUG = False
def out(s):
    if DEBUG:
        sys.stderr.write(str(s) + '\n')

class Case:
    def __init__(self, casenum):
        self.casenum = casenum

    def done(self, answer):
        print 'Case #%d: %s' % (self.casenum, answer)

    def cmp(self, a, b):
        return cmp(a[1], b[1])

    def bits(self, x):
        return len(filter(lambda n: n == '1', bin(x)))

    def solve(self):
        n, l = [int(x) for x in getline().split()]
        a = [int(x, 2) for x in getline().split()]
        b = [int(x, 2) for x in getline().split()]

        xors = [a[0] ^ x for x in b]
        data = [(x, self.bits(x)) for x in xors]
        data.sort(self.cmp)

        good = False
        for xor, count in data:
            good = True
            for x in a:
                if not x ^ xor in b:
                    good = False
                    break
            if good:
                self.done(count)
                break

        if not good:
            self.done('NOT POSSIBLE')

cases = int(getline())
for case in xrange(cases):
    Case(case + 1).solve()
