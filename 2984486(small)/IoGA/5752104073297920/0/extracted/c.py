#!/usr/bin/python

import sys
from math import log
import pickle

DEF_N = 1000

def read_case(f):
    N = int(f.readline())
    assert(N == DEF_N)
    perm = map(int, f.readline().strip().split())
    return perm

probs = pickle.load(open('data'))

def solve(perm):
    N = len(perm)
    log_good_prob = log(1.) * N

    log_bad_prob = 0

    for i, v in enumerate(perm):
        log_bad_prob += log(probs[i][v])

    if log_good_prob > log_bad_prob:
        return 'GOOD'
    else:
        return 'BAD'


def main(filename):
    with open(filename) as f:
        for case_num in range(int(f.readline())):
            result = solve(read_case(f))
            print 'Case #{}: {}'.format(case_num + 1, result)

if __name__ == "__main__":
    main(sys.argv[1])
