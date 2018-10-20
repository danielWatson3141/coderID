'''
CodeJam Practice 
Created on 2012-12-20

@author: festony
'''

from cj_lib import *
from properties import *

import math
import fractions


curr_file_name = 'A-large'
#curr_file_name = 'A-small-attempt0'
#curr_file_name = 'test'

# map(int, input_lines.pop(0).split(' '))

def input_dividing_func(input_lines):
    total_case = int(input_lines.pop(0))
    case_inputs = []
    for i in range(total_case):
        N, L = map(int, input_lines.pop(0).split(' '))
        outlet = map(lambda a:int(a, 2), input_lines.pop(0).split(' '))
        req = map(lambda a:int(a, 2), input_lines.pop(0).split(' '))
        case_inputs.append([N, L, outlet, req])
    return case_inputs

def cmp_l(l1, l2):
    if len(l1) != len(l2):
        return False
    tl1 = l1[:]
    tl2 = l2[:]
    for l in l1:
        tl1.remove(l)
        if l not in tl2:
            return False
        tl2.remove(l)
    return True
    
#def process_func(func_input):
#    N, L, outlet, req = func_input
#    maxL = int(math.pow(2, L))
#    #print maxL
#    #os = set(outlet)
#    #rs = set(req)
#    ll = []
#    for i in range(0, maxL):
#        tr = []
#        for o in outlet:
#            tr.append(o^i)
#        if cmp_l(tr, req):
#            ll.append(i)
#    #print ll
#    if ll == []:
#        return 'NOT POSSIBLE'
#    sn = []
#    for l in ll:
#        b = bin(l)
#        bs = b[2:]
#        #print bs
#        bl = map(int, list(bs))
#        sn.append(sum(bl))
#    return min(sn)

#large
def process_func(func_input):
    N, L, outlet, req = func_input
    mtx = []
    for o in outlet:
        tfm = []
        for r in req:
            tfm.append(o^r)
        mtx.append(tfm)
    #print mtx
    mtxsl = []
    for l in mtx:
        mtxsl.append(set(l))
    f = mtxsl[0]
    for s in mtxsl:
        f &= s
    #print f
    f = list(f)
    if f == []:
        return 'NOT POSSIBLE'
    p = []
    for c in f:
        idx = set([])
        for l in mtx:
            idx.add(l.index(c))
        print idx
        if len(idx) == N:
            p.append(c)
    print p
    if p == []:
        return 'NOT POSSIBLE'
    sn = []
    for l in p:
        b = bin(l)
        bs = b[2:]
        #print bs
        bl = map(int, list(bs))
        sn.append(sum(bl))
    return min(sn)

run_proc(process_func, input_dividing_func, curr_working_folder, curr_file_name)


