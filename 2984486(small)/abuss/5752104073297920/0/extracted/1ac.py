from sys import stdin

lines = stdin.read().replace('\r', '').split('\n')

T = int(lines.pop(0))


def ana(r):
    t = 0
    for i in range(n):
        if i < r[i] < i + 300:
            t += 1
    return t


for CN in range(1, T + 1):
    n = int(lines.pop(0))
    p = map(int, lines.pop(0).split(" "))
    print "Case #%d:" % CN, 
    if ana(p) > 275:
        print "BAD"
    else:
        print "GOOD"
