#p1
import sys

def test(outlets, devices, idx, L):
    if idx == L:
        return [0]
    p1 = filter(lambda x: x[idx] == '1', devices)
    p0 = filter(lambda x: x[idx] == '0', devices)
    o1 = filter(lambda x: x[idx] == '1', outlets)
    o0 = filter(lambda x: x[idx] == '0', outlets)
    result = []
    if len(o1) == len(p1):
        t1 = test(o1, p1, idx + 1, L)
        t2 = test(o0, p0, idx + 1, L)
        result += filter(lambda x: x in t2 and x >= 0, t1)
    if len(o1) == len(p0):
        t1 = test(o0, p1, idx + 1, L)
        t2 = test(o1, p0, idx + 1, L)
        result += map(lambda y: y+1, filter(lambda x: x in t2 and x >= 0, t1))
    return result

lines = sys.stdin.readlines()
t = int(lines[0])
for i in range(t):
    args = map(int, lines[3*i+1].split())
    n = args[0]
    l = args[1]
    nswitch = 0
    outlets = lines[3*i+2].split()
    devices = lines[3*i+3].split()
    result = test(outlets, devices, 0, l)
    print "Case #%d:"%(i+1),"NOT POSSIBLE" if not result else min(result)
