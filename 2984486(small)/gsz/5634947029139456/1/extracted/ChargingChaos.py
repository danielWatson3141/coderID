#!/usr/bin/env python

from __future__ import print_function

def readSolveCase():
    N, L = map(int, raw_input().split())
    nums1 = [int(s, 2) for s in raw_input().split()]
    nums2 = [int(s, 2) for s in raw_input().split()]
    xorAll = 0
    for n in nums1:
        xorAll ^= n
    for n in nums2:
        xorAll ^= n
    if N % 2 == 1:
        if {n ^ xorAll for n in nums1} == set(nums2):
            return '{:b}'.format(xorAll).count('1')
        else:
            return "NOT POSSIBLE"
    else:
        s1 = set(nums1)
        s2 = set(nums2)
        minOnes = L+1
        for n1 in nums1:
            for n2 in nums2:
                if {n ^ n1^n2 for n in s1 - {n1}} == s2 - {n2}:
                    ones = '{:b}'.format(xorAll^n1^n2).count('1')
                    if ones < minOnes:
                        minOnes = ones
                        best = xorAll^n1^n2
        if minOnes < L+1:
            return str(minOnes)
        else:
            return "NOT POSSIBLE"

def main():
    T = int(raw_input())
    for t in xrange(1, T+1):
        print('Case #{}: {}'.format(t, readSolveCase()))

if __name__ == "__main__":
    main()
