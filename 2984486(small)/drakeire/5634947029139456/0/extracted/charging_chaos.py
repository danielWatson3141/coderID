#!/usr/bin/env python

import sys

MAX_ML = float('inf')

def main():
  fi = sys.stdin
  fo = sys.stdout
  caseCount = int(fi.readline().strip())
  for i in xrange(1, caseCount+1):
    n, l, os, ds = readInput(fi)
    ml = solve(n, l, os, ds)
    displayAndClear(fo, i, ml)

def readInput(f):
  n, l = [int(arg) for arg in f.readline().split()]
  outlets = [int(arg, 2) for arg in f.readline().split()]
  devices = [int(arg, 2) for arg in f.readline().split()]
  return n, l, outlets, devices

def displayAndClear(f, i, ml):
  if ml == MAX_ML:
    f.write('Case #%d: NOT POSSIBLE\n' % i)
  else:
    f.write('Case #%d: %d\n' % (i, ml))
  f.flush()

def solve(n, l, os, ds):
  ds = set(ds)
  minml = MAX_ML
  for i in range(pow(2, l)):
    if isMatch(i, os, ds):   
      ml = matchLength(i)
      if ml < minml:
        minml = ml
    
  return minml

def isMatch(s, os, ds):
  for o in os:
    if o ^ s not in ds:
      return False
  return True

def matchLength(m):
  length = 0
  while m > 0:
    digit = m & 1
    if digit == 1:
      length += 1
    m = m >> 1
  return length

if __name__ == '__main__':
  main()

