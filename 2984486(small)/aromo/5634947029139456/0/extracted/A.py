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

def break_word(x):
    return np.array(map(int, x))

def fix_outlet(o, m):
    result = np.array(o)
    result[m] = 1 - result[m]
    return result

def solve_one():
    """ XXX the real code comes here """
    N, L = input_ints()

    outlets = map(break_word, input_words())
    devices = map(break_word, input_words())

    # print outlets
    # print devices

    costs = []
    for outlet_for_first in range(N):
        mask = outlets[outlet_for_first] != devices[0]
        fixed_outlets = [fix_outlet(o, mask) for o in outlets]
        # print 'XXX', outlet_for_first, mask.sum(), mask
        # print fixed_outlets
        # print ''.join(sorted([''.join(map(str, f)) for f in fixed_outlets]))
        # print ''.join(sorted([''.join(map(str, f)) for f in devices]))
        if ''.join(sorted([''.join(map(str, f)) for f in fixed_outlets])) == ''.join(sorted([''.join(map(str, f)) for f in devices])):
            # is feasible
            costs.append(mask.sum())

    if len(costs) == 0:
        return 'NOT POSSIBLE'
    else:
        return min(costs)


if __name__ == "__main__":
    assert(len(sys.argv) == 2)
    IN = open(sys.argv[1])

    T = input_ints()[0]
    
    for i in range(T):
        print "Case #%d:" % (i+1,), solve_one()
        sys.stderr.write("CASE #%d DONE\n" % (i+1,))
        sys.stderr.flush()


