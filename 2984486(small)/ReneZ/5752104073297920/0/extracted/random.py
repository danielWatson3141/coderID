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
        N = int(r.next())
        lst = map(int, r.next().split(" "))

        badness = []
        for i in xrange(len(lst)):
            if lst[i] < 300:
                if lst[i] > i and lst[i] < i + 700:
                    badness.append(700 - lst[i] + i)
                elif lst[i] >= i + 700:
                    badness.append(300 - lst[i])
                else:
                    badness.append(-300 + (i - lst[i]))
            elif lst[i] < 700:
                if lst[i] > i:
                    badness.append(500 - lst[i] + i)
                else:
                    badness.append(-500 + (i - lst[i]))
            else:
                if lst[i] > i:
                    badness.append(300 - lst[i] + i)
                else:
                    badness.append(-300 + (i - lst[i]))
        
        # sum(badness)
        # ans.append(sum(badness))
        if sum(badness) > 30000:
            ans.append(" BAD")
        else:
            ans.append(" GOOD")
    write("output", ans)

if __name__ == '__main__':
    main()
