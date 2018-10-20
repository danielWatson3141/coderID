'''
CodeJam Practice 
Created on 2012-12-20

@author: festony
'''

from cj_lib import *
from properties import *

import math
import fractions


#curr_file_name = 'C-large'
curr_file_name = 'C-small-attempt1'
#curr_file_name = 'test'

# map(int, input_lines.pop(0).split(' '))

def input_dividing_func(input_lines):
    total_case = int(input_lines.pop(0))
    case_inputs = []
    for i in range(total_case):
        N = int(input_lines.pop(0))
        p = map(int, input_lines.pop(0).split(' '))
        case_inputs.append([N, p])
    return case_inputs

def stay_same_p(N):
    P = fractions.Fraction(0)
    for i in range(N):
        p = fractions.Fraction(1)
        p *= math.factorial(N-1)
        p /= math.factorial(N-1-i)
        p *= int(math.pow(N-i-1, N-i-1))
        p /= int(math.pow(N, N))
        P += p
    return P

def process_func(func_input):
    N, p = func_input
    c = 0
    for i in range(N):
        if i == p[i]:
            c += 1
    if c >= N/2-1: 
        return 'BAD'
    return 'GOOD'

run_proc(process_func, input_dividing_func, curr_working_folder, curr_file_name)

#print (stay_same_p(4))
#print float(stay_same_p(4))
##print math.pow(1000,1000)
#def gen_good_perm(N):
#    if N == 1:
#        return [[1]]
#    ps = []
#    sps = gen_good_perm(N-1)
#    for i in range(N):
#        p = []
#        for sp in sps:
#            p = sp[:]
#            p.insert(i, N)
#            ps.append(p)
#    return ps
#
#print gen_good_perm(4)
#
#def gen_bad_perm(N):
#    bp = range(1, N+1)
#    ps = []
#    for i in range(N):
#        p = bp[:]
#        if i > 0:
#            p[0], p[i] = p[i], p[0]
#        ps.append(p)
#    tps = []
#    for i in range(1, N):
#        for b in ps:
#            for i in range(N):
#                p = b[:]
#                if i > 0:
#                    p[0], p[i] = p[i], p[0]
#                tps.append(p)
#        ps = tps
#        tps = []
#    return ps
#            
#x = gen_bad_perm(4)
#y = []
#for xx in x:
#    y.append(tuple(xx))
#print y
#
#d = dict()
#for yy in y:
#    if d.has_key(yy):
#        d[yy] += 1
#    else:
#        d[yy] = 1
#z = []
#for k in d.keys():
#    #print k, d[k]
#    z.append([list(k), d[k]])
#z.sort(cmp=None, key=lambda x:x[1], reverse=False)
#print z
#for zz in z:
#    print zz
#print sum(map(lambda x:x[1], z))
