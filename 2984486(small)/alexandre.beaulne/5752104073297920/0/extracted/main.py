#!/usr/bin/python3

import sys

if __name__ == "__main__":

    T = int(sys.stdin.readline())

    for case in range(T):

        N = int(sys.stdin.readline())

        threshold = -30

        array = [int(X) for X in sys.stdin.readline().split()]

        score = 0
        for i, v in enumerate(array):
            if 0 <= v < i:
                score += 1
            else:
                score -= 1

        if score < threshold:
            print("Case #", case+1, ": BAD", sep="")
        else:
            print("Case #", case+1, ": GOOD", sep="")

