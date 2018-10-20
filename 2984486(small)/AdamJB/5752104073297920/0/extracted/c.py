#!/usr/bin/env python

"""
  Problem : 
  Code by : AdamJB
  Info    : 
"""

import random

def solveCase(case, N, G):
  # print N
  # print G
  s = random.seed(case)
  x = random.randint(0, N)
  if x % 2 == 0:
    print("Case #%d: %s" % (case, "GOOD"))
  else:
    print("Case #%d: %s" % (case, "BAD"))


def main():
  T = int(raw_input())
 
  for case in range(1, T+1):
    N = int(raw_input())
    G = [int(i) for i in raw_input().strip().split()]
      
    solveCase(case, N, G)
    
main()

