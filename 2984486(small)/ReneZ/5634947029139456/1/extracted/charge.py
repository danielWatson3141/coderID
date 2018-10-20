from util import *

def diff(a, b):
    return [a[i] != b[i] for i in xrange(len(a))]

def swp(x, switches):
    out = ""
    for i in range(len(x)):
        if switches[i]:
            out += '1' if x[i] == '0' else '0'
        else:
            out += x[i]
    return out

def main():
    r = reader("input")
    num = int(r.next())
    ans = []
    for i in xrange(num):
        N,L = map(int, r.next().split(" "))
        outlets = r.next().split(" ")
        devices = r.next().split(" ")
        devices = sorted(devices)

        minimum = None

        for o in outlets:
            d = diff(devices[0], o)
            tot = sum(d)
            
            if devices == sorted(map(lambda x: swp(x,d), outlets)):
                if minimum is not None:
                    minimum = min(tot, minimum)
                else:
                    minimum = tot

        if minimum is not None:
            ans.append(minimum)
        else:
            ans.append("NOT POSSIBLE")
    write("output", ans)

if __name__ == '__main__':
    main()
