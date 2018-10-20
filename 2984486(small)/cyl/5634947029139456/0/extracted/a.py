#!/usr/bin/env python

import sys
from itertools import combinations
from copy import deepcopy


def main():
    T = int(sys.stdin.readline().strip())
    for case_id in range(1, T+1):
        N, L = map(int, sys.stdin.readline().strip().split())
        ori = sorted(map(lambda s: map(int, list(s)),
                     sys.stdin.readline().strip().split()))
        req = sorted(map(lambda s: map(int, list(s)),
                     sys.stdin.readline().strip().split()))
        if ori == req:
            print "Case #" + str(case_id) + ": 0"
            continue
        else:
            done = False
            ori_1, req_1 = 0, 0
            ori_flip, req_flip = [], []
            for i in range(L):
                ori_flip_cnt = 0
                req_flip_cnt = 0
                for x in ori:
                    if x[i] == 1:
                        ori_1 += 1
                        ori_flip_cnt -= 1
                    else:
                        ori_flip_cnt += 1
                for y in req:
                    if y[i] == 1:
                        req_1 += 1
                        req_flip_cnt -= 1
                    else:
                        req_flip_cnt += 1
                ori_flip.append(ori_flip_cnt)
                req_flip.append(req_flip_cnt)

            for k in range(1, L):
                if done:
                    break
                for choice in combinations(range(L), k):
                    if done:
                        break
                    if sum([ori_flip[c] for c in choice]) + ori_1 != req_1:
                        continue
                    tmp = deepcopy(ori)
                    #print choice, tmp
                    for c in choice:
                        for x in tmp:
                            if x[c] == 0:
                                x[c] = 1
                            else:
                                x[c] = 0
                    tmp = sorted(tmp)
                    #print choice, tmp
                    if tmp == req:
                        #print choice
                        print "Case #" + str(case_id) + ": " + str(k)
                        done = True
            if not done:
                print "Case #" + str(case_id) + ": NOT POSSIBLE"


if __name__ == '__main__':
    main()
