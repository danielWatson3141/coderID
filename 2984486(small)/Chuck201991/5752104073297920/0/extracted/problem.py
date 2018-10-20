import os
import sys
from itertools import combinations

lines = sys.stdin.readlines()
num_cases = int(lines[0])
lines = lines[1:]

for zz in range(1, num_cases+1):
    t = int(lines[0])
    items = map(int, lines[1].strip().split(" "))
    lines = lines[2:]

    prob_bad = t**(-1*(t-2))
    prob_good = 0.0
    prob_not_good = 1.0
    prob_of_num_being_swapped = 1.0/t
    for i, item in enumerate(items):
        if i == item:
            # Probability of this being the good algorithm
            #  is the chances of this item begin in this place
            #  If good, it could have gotten here onl in this swap
            prob_not_good *= 1.0/(t-i)
            # Else, if could have gotten here as a result of t swaps
            #prob_bad += t**(-1*(t-1))
        else:
            # The probability of NOT getting the original one
            #  is equal to 1-the chances of it having been picked
            prob_good += 1.0-(prob_of_num_being_swapped)
        prob_of_num_being_swapped += 1.0/(t-i)
    #print "prob_bad ", prob_bad
    #print "prob_good ", prob_good
    #print "prob_not_good ", prob_not_good
    #if prob_bad > prob_good:
    if prob_not_good < prob_bad:
        print "Case #%s: BAD" % zz
    else:
        print "case #%s: GOOD" % zz
