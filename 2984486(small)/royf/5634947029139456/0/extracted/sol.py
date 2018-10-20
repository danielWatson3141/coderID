
import math
import itertools
import numpy as NP

################################################################################

def read_case(f):
    N, L = read_ints(f)
    O = read_ints(f, 2)
    D = read_ints(f, 2)
    return N, L, O, D

def solve_small(case):
    N, L, O, D = case
    s = None
    for d in D:
        x = set(d^o for o in O)
        if s is None:
            s = x
        else:
            s &= x
    if not s:
        return 'NOT POSSIBLE'
    return str(sorted((sum(y == '1' for y in bin(x)[2:]), x) for x in s)[0][0])

def solve_large(case):
    return solve_small(case)

def write_case(f, i, res):
    f.write('Case #%d: '%i)
    f.write('%s'%res)
    f.write('\n')

################################################################################

def read_word(f):
    return next(f).strip()

def read_int(f, b=10):
    return int(read_word(f), b)

def read_letters(f):
    return list(read_word(f))

def read_digits(f, b=10):
    return [int(x, b) for x in read_letters(f)]

def read_words(f, d=' '):
    return read_word(f).split(d)

def read_ints(f, b=10, d=' '):
    return [int(x, b) for x in read_words(f, d)]

def read_floats(f, d=' '):
    return [float(x) for x in read_words(f, d)]

def read_arr(f, R, reader=read_ints, *args, **kwargs):
    return [reader(f, *args, **kwargs) for i in range(R)]

def solve(solver, fn, out_fn=None):
    in_fn = fn + '.in'
    if out_fn is None:
        out_fn = fn + '.out'
    with open(in_fn, 'r') as fi:
        with open(out_fn, 'w') as fo:
            T = read_int(fi)
            for i in range(T):
                case = read_case(fi)
                res = solver(case)
                write_case(fo, i, res)

DEBUG = 'i'

from run import *
