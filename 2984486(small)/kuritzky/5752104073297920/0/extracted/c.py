# -*- coding: utf-8 -*-
"""
Problem C. Proper Shuffle
uses python 3.3

@author: Eric Kuritzky
"""
from collections import *
import itertools as itool
import operator as op
import functools as ft
from sys import argv, stderr
    
def errprt(*args, **kw):
    print(*args, file=stderr, **kw) 
    

def readcase():
    n = int(input())
    return readints()

def solvecase(perm):
    if score(perm)<0:
        return 'BAD'
    else:
        return 'GOOD'

def score(perm):
    score = 0
    for i, j in enumerate(perm):
        if i == j+1:
            score += 1
        elif i == j-1:
            score -= 1
    return score
    
def readints():
    return list(map(int, input().split(' ')))

def main():
        cases = int(input())
        for case in range(1, cases+1):
            print('Case #%d: %s' % (case, solvecase(readcase())))

main()
