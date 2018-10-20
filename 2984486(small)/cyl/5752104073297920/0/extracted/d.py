#!/usr/bin/env python

import sys
import random


def main():
    T = int(sys.stdin.readline())
    for case_id in range(1, T+1):
        N = int(sys.stdin.readline().strip())
        perm = map(int, sys.stdin.readline().strip().split())
        score = 0
        for i in range(N-1):
            if perm[i] < perm[i+1]:
                score += 1
            else:
                score -= 1
        if score > 0:
            print "Case #" + str(case_id) + ": BAD"
        elif score < 0:
            print "Case #" + str(case_id) + ": GOOD"
        else:
            if random.randint(0, 1) == 0:
                print "Case #" + str(case_id) + ": GOOD"
            else:
                print "Case #" + str(case_id) + ": BAD"

if __name__ == '__main__':
    main()
