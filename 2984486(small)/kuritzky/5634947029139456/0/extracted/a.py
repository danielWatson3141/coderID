# -*- coding: utf-8 -*-
"""
Problem A. Charging Chaos
uses python 3.3

@author: Eric Kuritzky
"""
from collections import *
import itertools as itool
import operator as op
import functools as ft
from sys import argv, stdin, stdout, stderr
    
def errprt(*args, **kw):
    print(*args, file=stderr, **kw) 
    
Case = namedtuple('Case', 'devices,outlets,nswitches')

def readcase():
    n, l = readints()
    devices = readbin(n, l)
    outlets = readbin(n, l)
    return Case(devices, outlets, l)

def readbin(cnt, lgth):
    fields = input().split(' ')
    assert len(fields)==cnt 
    assert all(len(fld)==lgth for fld in fields)
    return [int(fld, 2) for fld in fields]
    
def solvecase(devices, outlets, nswitches):
    dev0 = devices[0]
    best = worst = nswitches + 1
    for outlet in outlets:
        change = dev0 ^ outlet
        if works(change, devices, outlets):
            best = min(best, score(change))
    if best != worst:
        return str(best)
    else:
        return "NOT POSSIBLE" 
	
def works(change, devices, outlets):
    outlets = set(outlets)
    return all(dev ^ change in outlets for dev in devices)
    
def score(n):
    ans = 0
    while n>0:
        n &= n-1
        ans += 1
    return ans
    
def readints():
    return list(map(int, input().split(' ')))

def main():
        cases = int(input())
        for case in range(1, cases+1):
            print('Case #%d: %s' % (case, solvecase(**vars(readcase()))))

main()
