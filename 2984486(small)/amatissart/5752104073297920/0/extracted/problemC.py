# -*- coding: utf-8 -*-
"""
Created on Sat Apr 26 04:39:17 2014

@author: adrien
"""
from scipy.integrate import trapz
import numpy as np
import sys

filename = sys.argv[1]
with open(filename) as f:
    n_cases = int(f.readline())
    for i in range(n_cases):
        N = int(f.readline())
        temp = []
        for x in f.readline().split():
            temp.append(int(x))
        array = np.array(temp)
        s = np.zeros(N)
        for k in range(N):
            s[k] = np.sum(array[0:k])
        area = trapz(s)
        if (area>247000000):
            print 'Case #%d: GOOD' % (i+1)
        else:
            print 'Case #%d: BAD' % (i+1)
        
