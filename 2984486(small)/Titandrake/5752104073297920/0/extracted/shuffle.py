import random
t = input()

def prob(perm):
    c = 0
    for i in range(n):
        if perm[i] == i:
            c += 1
    if c == 0:
        return "BAD"
    return "GOOD"
    

for case in range(1, t+1):
    n = input()
    permutation = map(int, raw_input().split())
    print "Case #%d: %s" % (case, prob(permutation))