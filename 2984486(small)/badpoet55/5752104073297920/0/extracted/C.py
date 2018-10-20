#C.py

from __future__ import division
import random

def score(per):
    rst = 0
    for i in range(len(per)):
        if per[i] == i:
            rst += 1
    return rst / len(per)

def main():
    tc = input()
    for tid in range(1, tc + 1):
        n = input()
        per = map(int, raw_input().split())
        k = score(per)
        if k > 0.0005:
            ctrl = "BAD"
        else:
            ctrl = "GOOD"
        print "Case #" + str(tid) + ": " + ctrl

if __name__ == "__main__":
    main()