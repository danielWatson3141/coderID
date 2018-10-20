#!/usr/bin/env python
# coding:utf-8
from __future__ import division

import itertools

def process_file(file):
    fsock = open(file)
    text = fsock.read()
    fsock.close()
    lines = text.split('\n')
    return lines

def process_lines(lines):
    cases = []
    n = int(lines[0].split(' ')[0])
    for i in range(1, n+1):
        i = 3*(i-1) + 1
        n,l = lines[i].split(' ')
        o = [x for x in lines[i+1].split(' ')]
        d = [x for x in lines[i+2].split(' ')]
        cases.append((n,l,o,d))
    return cases

def process_case(case):
    n,l,o,d = case
    n = int(n)
    l = int(l)
    d = sorted(d)
    #print n,l,o,d
    if sorted(o) == d:
        return "0"
    
    '''
    for i in range(l):
        oo = [list(z) for z in o]
        for j in range(n):
            oo[j][i] = '1' if oo[j][i] == '0' else '0'
        oo = [''.join(z) for z in oo]
        #print oo, d
        if sorted(oo) == d:
            return i
    '''
    
    for num in range(1, l+1):
        flips = list(itertools.combinations(range(l),num))
        for flip in flips:
            oo = [list(z) for z in o]
            for i in flip:
                for j in range(n):
                    oo[j][i] = '1' if oo[j][i] == '0' else '0'
            oo = [''.join(z) for z in oo]
            #print num, flip
            #print oo, d
            if sorted(oo) == d:
                return num
    return 'NOT POSSIBLE'
    

def main():
    import sys
    if len(sys.argv) == 1:
        filename = 'x.in'
    else:
        filename = sys.argv[1]
    lines = process_file(filename)
    cases = process_lines(lines)
    for k, v in enumerate(cases):
        case = process_case(v)
        if type(case) == set or type(case) == list:
            case = ' '.join([str(x) for x in case])
        print "Case #%d: %s" % (k + 1, case)

if __name__ == "__main__":
    main()