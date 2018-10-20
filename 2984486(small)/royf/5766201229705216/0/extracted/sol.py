
import math
import itertools
import numpy as NP

################################################################################

def read_case(f):
    N = read_int(f)
    E = read_arr(f, N-1)
    return N, E

def size_aux(n, s, d, i, j):
    res = 1
    for k in n[j]:
        if k == i:
            continue
        res += size(n, s, d, j, k)
    return res

def delete_aux(n, s, d, i, j):
    best = None
    for k in n[j]:
        if k == i:
            continue
        for l in n[j]:
            if l in [i, k]:
                continue
            b = delete(n, s, d, j, k) + delete(n, s, d, j, l) - size(n, s, d, j, k) - size(n, s, d, j, l)
            if best == None or best > b:
                best = b
    if best is None:
        if len(n[j] - {i}) == 1:
            best = size(n, s, d, j, (n[j] - {i}).pop())
        else:
            best = 0
    else:
        best += sum(size(n, s, d, j, k) for k in n[j] if k != i)
    return best

def size(n, s, d, i, j):
    if (i, j) not in s:
        s[i, j] = size_aux(n, s, d, i, j)
    return s[i, j]

def delete(n, s, d, i, j):
    if (i, j) not in d:
        d[i, j] = delete_aux(n, s, d, i, j)
    return d[i, j]

def solve_small(case):
    N, E = case
    n = {}
    for (x, y) in E:
        n.setdefault(x, set()).add(y)
        n.setdefault(y, set()).add(x)
    s = {}
    d = {}
    for i in range(1, N+1):
        for j in n[i]:
            s[i, j] = size(n, s, d, i, j)
            d[i, j] = delete(n, s, d, i, j)
    best = None
    for i in range(1, N+1):
        b = delete_aux(n, s, d, None, i)
        if best == None or best > b:
            best = b
    return best

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
