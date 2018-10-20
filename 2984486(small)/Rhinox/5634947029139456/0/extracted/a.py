# python 2.7

import os, sys

class Input:
    def __init__(self, fp): self.fp = fp
    def m(self, n, t=str):  return [map(t, list(self.line())) for i in range(n)]
    def ms(self, n, t=str, sep=' '):  return [map(t, self.line().split(sep)) for i in range(n)]
    def line(self):  return self.fp.readline().strip()
    def words(self): return self.line().split()
    def int(self):   return int(self.line())
    def ints(self):  return map(int, self.words())
    def float(self): return float(self.line())
    def floats(self):return map(float, self.words())
    def str(self):   return self.line()
    def types(self, *types): return [t(w) for t,w in zip(types, self.words())]

from itertools import chain, combinations
def enumerate_bits(length):
    s = range(length)
    return chain.from_iterable(combinations(s, r) for r in range(len(s)+1))

if __name__ == "__main__":
    fn = "test.txt" if len(sys.argv) <= 1 else sys.argv[1]
    f = Input(open(fn))
    fout = open(os.path.splitext(fn)[0] + ".out", "w")

    def answer(t, ans):
        o = "Case #%d: %s\n"%(t, ans)
        sys.stdout.write(o)
        fout.write(o)

    for case in range(f.int()):
        n, l = f.ints()

        o = [map(int, list(x)) for x in f.words()]
        d = [map(int, list(x)) for x in f.words()]

        #o = map(int, "".join(f.words()))
        #d = map(int, "".join(f.words()))
        sd = sorted(d)

        def flip(lst, i):
            for x in lst: x[i] = 1 - x[i]
            #for j in range(i, len(lst), l): lst[j] = 1 - lst[j]

        b = None
        for indexes in enumerate_bits(l):
            oo = [x[:] for x in o]
            for i in indexes: flip(oo, i)

            if sorted(oo) == sd:
                b = len(indexes)
                break

        flip(o, 0)
        answer(case + 1, "NOT POSSIBLE" if b is None else b)
