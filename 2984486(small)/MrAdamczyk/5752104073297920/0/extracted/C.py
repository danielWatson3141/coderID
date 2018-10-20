import sys

def solve(x):
    N = int(raw_input())
    line = raw_input()
    print "Case #%d: BAD" % x

sys.setrecursionlimit(150000000)
T = int(raw_input())
for i in xrange(T):
    solve(i+1)
