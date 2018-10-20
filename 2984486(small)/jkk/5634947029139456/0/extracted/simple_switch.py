#!/usr/bin/env python3

import sys, math

def compare(flips, power, outlets):
  noutlets = []
  power = set(power)
  for outlet in outlets:
    ans = ''
    for i in range(len(flips)):
      val = outlet[i]
      if flips[i] == '1':
        val = '1' if val == '0' else '0'
      ans += val
    if ans not in power:
      return False
  return True

cases = int(sys.stdin.readline())
for case_no in range(1, cases + 1):
  N, L = [int(val) for val in sys.stdin.readline().strip().split()]
  outlets = sys.stdin.readline().strip().split()
  power = sys.stdin.readline().strip().split()

  bflips = -1
  for i in range(2 ** L):
    flips = bin(i)[2:]
    flips = '0' * (L - len(flips)) + flips
    if compare(flips, power, outlets):
      count = sum([int(i) for i in flips])
      if count < bflips or bflips < 0:
        bflips = count
  ans = bflips
  if bflips < 0:
    ans = "NOT POSSIBLE"

  print("Case #{}: {}".format(case_no, ans))
