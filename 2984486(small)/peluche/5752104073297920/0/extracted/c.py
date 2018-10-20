#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
see Fisher-Yates shuffle
"""

good = "GOOD"
bad  = "BAD"

import random
import json

def gen_bad(acc):
    a = [k for k in range(1000)]
    for k in range(1000):
        p = random.randint(0, 999)
        a[k], a[p] = a[p], a[k]
    for ind, el in enumerate(a):
        acc[ind][el] += 1
        
def save_it(acc):
    with open("data.json", "w") as f:
        f.write(json.dumps(acc))

def load_it():
    with open("data.json", "r") as f:
        s = ""
        for t in f:
            s += t
        acc = json.loads(s)
    return acc

def gen(nb):
    acc = load_it()
    # acc = [[0 for x in range(1000)] for x in range(1000)]
    for i in range(nb):
        gen_bad(acc)

    save_it(acc)
    print acc

def solve(l, acc):
    prob = 0
    prob_norm = 0
    for ind, el in enumerate(l):
        prob += acc[ind][el] / (2* 1500000.0)
        prob_norm += 0.001
    if prob > prob_norm:
        return bad
    else:
        return good
    
def percent():
    acc = load_it()
    print [el/1500000.0 for el in sorted(acc[4])]
    print sum(acc[4])

def main():
    acc = load_it()
    T = int(raw_input())
    for i in range(1, T + 1):
        N = raw_input()
        l = map(int, raw_input().split())
        res = solve(l, acc)
        print "Case #{}: {}".format(i, res)

if __name__ == '__main__':
#    print load_it()
#    gen(1500000)
#    percent()
    main()
