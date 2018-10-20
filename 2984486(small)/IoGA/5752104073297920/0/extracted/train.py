#!/usr/bin/env python

from random import randint
import pickle

N = 20

def good(l):
    l = list(l)

    for k in range(N):
        p = randint(k, N-1)
        l[k], l[p] = l[p], l[k]

    return l

def bad(l):
    l = list(l)

    n = len(l)

    for k in range(n):
        p = randint(0, n-1)
        l[k], l[p] = l[p], l[k]

    return l

COUNT = 10000

def main2():
    l = range(N)

#    goods = []
#    for c in range(COUNT):
#        goods.append(good(l))

    pos = {}
    for n in range(5, 50):
        pos[n] = 0
        l = range(n)
        for _ in range(1000):
            if (bad(l)[0] == 1): pos[n] += 1
        pos[n] /= (1000. /n)
    return pos

#    bads = []
#    for c in range(COUNT):
#        bads.append(bad(l))
#
#    return goods, bads

RUNS = 100000
N = 1000

def train():
    l = range(N)

    pos_to_count = [[0 for i in range(len(l))] for j in range(len(l))]

    for _ in range(RUNS):
        for i, v in enumerate(bad(l)):
            pos_to_count[i][v] += 1

    for counts in pos_to_count:
        for index, el in enumerate(counts):
            counts[index] = el / (RUNS * 1. / N)

    print pos_to_count

    with open('data', 'w') as f:
        pickle.dump(pos_to_count, f)

if __name__ == "__main__":
    train()
