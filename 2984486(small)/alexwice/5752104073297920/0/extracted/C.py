import sys
import itertools
import math
import collections
import functools

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
    res = []
    for i in range(R):
        res.append(reader(f, *args, **kwargs))
    return res
def solve(solver,SMALL=True,PRACTICE=False):
    fn = sys.argv[0]
    fn = fn[ 1+fn.rfind('/'): fn.rfind('.') ]
    fn = fn+['-large','-small'][SMALL]+['','-practice'][PRACTICE]
    in_fn = fn + '.in'
    out_fn = fn + '.out'
    with open(in_fn, 'r') as fi:
        with open(out_fn, 'w') as fo:
            T = read_int(fi)
            for i in range(T):
                case = read_case(fi)
                res = solver(case)
                print i+1, res
                write_case(fo, i+1, res)
def write_case(f, i, res):
    f.write('Case #%d: '%i)
    f.write('%s'%res)
    f.write('\n')

#######################################################

def read_case(f):
    N = read_int(f)
    A = read_ints(f)
    return A

#######################################################
sys.setrecursionlimit(1500)
buff = []
buff2 = []
def swap(lt,a,b):
    lt[a],lt[b]=lt[b],lt[a]
    return lt

def howmany(x,a=0):
    global buff
    #how many swaps to return to 0,...999
    for i in xrange(a,1000):
        if x[i]!=i:
            buff.append((i,x.index(i)))
            return 1+howmany(swap(x,i,x.index(i)),i)
    return 0

def solver(case):
    A = case
    global buff
    buff = []
    z = howmany(A)
    if z<993: return "BAD"
    return "GOOD"



    
#False for large
solve(solver,True)
#solve(solver,False)

print 'Done'
