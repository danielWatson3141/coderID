#! /usr/bin/env python
from __future__ import print_function, division
try:
    range = xrange
except NameError:
    pass
import collections
import functools
import itertools as it
import random
import numpy as np # See http://www.numpy.org/
import gmpy2 # See https://code.google.com/p/gmpy/
#import networkx as nx # See http://networkx.github.io/

import os
import sys
# MY MODULES - available at https://github.com/lackofcheese/CodeJamLib/
sys.path.append(os.path.join(
    os.environ['GOOGLE_DRIVE'], 'Coding', 'GCJ', 'CodeJamLib'))
import codejam_io

def toks_line(f_in, fun=lambda x: x):
    return [fun(k) for k in f_in.readline().split()]

def process_first(f_in):
    num_cases = int(f_in.readline())
    other_data = None
    return num_cases, other_data

def process_case(f_in, f_out, case_no, other_data=None):
    N, L = (int(tok) for tok in f_in.readline().split())
    init_flow = [int(s, 2) for s in f_in.readline().split()]
    desired_flow = [int(s, 2) for s in f_in.readline().split()]

    # N, L = 150, 40
    # init_flow = [random.randint(0, 2**L - 1) for i in range(N)]
    # desired_flow = [random.randint(0, 2**L - 1) for i in range(N)]

    ans = solve(N, L, init_flow, desired_flow)
    ans_string = "NOT POSSIBLE" if ans is None else str(ans)
    print("Case #{}: {}".format(case_no, ans_string), file=f_out)

def solve(N, L, init_flow, desired_flow):
    desired_flow.sort()
    min_n_flips = L + 1

    xv = [collections.Counter() for i in range(L+1)]
    for i in range(N):
        for j in range(N):
            v = init_flow[i] ^ desired_flow[j]
            n_flips = bin(v).count("1")
            xv[n_flips][v] += 1
    for n_flips in range(L+1):
        for v, count in xv[n_flips].items():
            if count < N:
                continue
            new_flow = [x ^ v for x in init_flow]
            new_flow.sort()
            if new_flow == desired_flow:
                return n_flips
    return None

if __name__ == '__main__':
    codejam_io.process_input(process_case, process_first, __file__)
