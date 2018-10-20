import sys
f = sys.stdin

def solve():
    n = int(f.readline())
    s = map(int, f.readline().split(' '))
    score = 0
    score2 = 0
    for i in range(n):
        if s[i] == i:
            score += 1
    for i in range(n - 1):
        if s[i] == s[i - 1] + 1:
            score2 += 1
    #print score, score2
    if score > 1 or score2 > 1:
        return "BAD"
    else:
        return "GOOD"
            

T = int(f.readline())
for i in range(T):
    print "Case #%d: %s" % (i + 1, solve())
    
