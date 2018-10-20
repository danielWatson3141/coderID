
import sys, collections
def read(): sys.stdout.flush(); return sys.stdin.readline().strip()

def number_in_original_pos(L):
    return sum(1 for (i, x) in enumerate(L) if i == x)

import random

def good_perm(L):
    M = list(L)
    for i in xrange(len(L)-1, 0, -1):
        j = random.randrange(0, i+1)
        M[i], M[j] = M[j], M[i]
    return M

def bad_perm(L):
    M = list(L)
    for i in xrange(len(L)-1, 0, -1):
        j = random.randrange(0, len(L))
        M[i], M[j] = M[j], M[i]
    return M

def iso_val(L):
    return sum(1 for i, x in enumerate(L) if i == x)

def likelihood_of_good_perm(L):
    total = 0.0
    for i in xrange(500):
        total += iso_val(good_perm(L))
    return total / 500
    
def likelihood_of_bad_perm(L):
    total = 0.0
    for i in xrange(500):
        total += iso_val(bad_perm(L))
    return total / 500


tests = int(read())
for test in xrange(tests):
    read()
    L = [int(x) for x in read().split(" ")]
    
    while True:
        M = sum((1 if likelihood_of_good_perm(L) > likelihood_of_bad_perm(L) else -1) for i in xrange(3))
        ans = None
        if M == 3:
            ans = "GOOD"
        elif M == -3:
            ans = "BAD"
        
        if ans:
            print "Case #%d: %s" % (test+1, ans)
            break
