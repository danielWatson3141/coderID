#!/usr/bin/python
""" template.py input-file > output-file"""

import sys
import numpy as np

sys.setrecursionlimit(10000)

def input_words():
    line = IN.readline()
    return line.strip().split()

def input_ints():
    return map(int, input_words())

def input_floats():
    return map(float, input_words())

def format_sequence(s, formatter='%s'):
    return " ".join(map(lambda x: formatter % (x,), s))

def update_expected(v, k):
    N = len(v)
    res = (1. - 1./N) * v + (1./N) * v[k]
    res[k] = v.mean()
    return res

def bad_loglikes(N):
    result = []
    
    for i in range(N):
        v = np.zeros(N)
        v[i] = 1.
#        print v
        for k in range(N):
            v = update_expected(v, k)
#            print v
#        print np.log(v)
        result.append(np.log(v))
#        print i
    return result


def solve_one(ll):
    """ XXX the real code comes here """
    N = input_ints()[0]
    # for testing
    if N != 1000:
        ll = bad_loglikes(N)
    perm = np.array(input_ints())

    # print ll
    # print perm
    this_loglike = 0.
    for i in range(N):
        k = perm[i]
        tmp = ll[k][i]
#        print i, k, tmp
        this_loglike += tmp
    
#    print this_loglike, N * np.log(1. / N)
    if this_loglike > N * np.log(1. / N):
        return 'BAD'
    else:
        return 'GOOD'


if __name__ == "__main__":
    assert(len(sys.argv) == 2)
    IN = open(sys.argv[1])

    T = input_ints()[0]
    
    ll = bad_loglikes(1000)
#    ll = None

    for i in range(T):
        print "Case #%d:" % (i+1,), solve_one(ll)
        sys.stderr.write("CASE #%d DONE\n" % (i+1,))
        sys.stderr.flush()



