from __future__ import print_function
from itertools import product

def match(sw, de, mod):
    nsw = []
    for s in sw:
        ns = []
        for i in xrange(len(s)):
            ns.append(int(s[i]))
            if mod[i] == 1:
                ns[i] += 1
                ns[i] %= 2
        nsw.append(ns)

    for s in nsw:
        if s in de:
            de.remove(s)
    return len(de)

if __name__ == '__main__':
    T = int(raw_input())
    for pb_i in xrange(T):
        N, L =  [int(_) for _ in raw_input().split()]
        switchs = [_ for _ in raw_input().split()]
        devices = [_ for _ in raw_input().split()]
        S = []
        D = []
        for sw in switchs:
            sw = list(sw)
            tmp = []
            for s in sw:
                tmp.append(int(s))
            S.append(tmp)

        for de in devices:
            de = list(de)
            tmp = []
            for d in de:
                tmp.append(int(d))
            D.append(tmp)


        result = L + 1
        for per in product([0,1], repeat=L):
            r = match(S, list(D), per)
            if(r == 0):
                a = per.count(1)
                if a < result:
                    result = a

        if result == L+1:
            result = "NOT POSSIBLE"
        print("Case #{}: {}".format(pb_i+1, result))