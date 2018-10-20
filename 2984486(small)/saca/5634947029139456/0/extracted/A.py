#!/usr/bin/env python3
import math, collections, itertools
from sys import stdin


def readValue(valueType):
    return valueType(stdin.readline())


def readValues(valueType):
    return list(map(valueType, stdin.readline().split()))


class Mouth():
    count = 1

    @classmethod
    def answer(cls, answer):
        if answer is None:
            answer = 'NOT POSSIBLE'
        print("Case #{}: {}".format(cls.count, answer))
        cls.count += 1


def readInput():
    global N, L, devs, outs
    N, L = readValues(int)
    outs = list(map(list, readValues(str)))
    devs = readValues(str)


def doSwitch(outs, swNo):
    for out in outs:
        out[swNo] = '0' if out[swNo] == '1' else '1'


def solve():
    global N, L, devs, outs

    fmt = '{:0' + str(L) + "b}"
    devs.sort()
    for cfg in range(2 ** L):
        newOuts = [[c for c in out] for out in outs]
        cfgLen = 0

        for swNo, ch in enumerate(fmt.format(cfg)):
            if ch == '1':
                cfgLen += 1
                doSwitch(newOuts, swNo)
        newOuts = [''.join(out) for out in newOuts]
        newOuts.sort()
        if newOuts == devs:
            #print('{} {}'.format(fmt.format(cfg), newOuts))
            #print('{}!{}'.format(fmt.format(cfg), devs))
            return cfgLen
    return None

if __name__ == '__main__':
    for _ in range(readValue(int)):
        readInput()
        Mouth.answer(solve())
