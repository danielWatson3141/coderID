#!/bin/python
import sys

import random


def readin(infile):
  print >> sys.stderr, "reading from " + infile
  lines=open(infile, 'r').readlines()
  testcount = int(lines[0])
  print >> sys.stderr, "read %d test cases from %d lines"%(testcount, len(lines))
  lines=lines[1:]
  return testcount, lines

def doall(testcases, lines):
  case = 1

  while lines:
    n = int(lines[0])
    ii = [int(x) for x in lines[1].split()]
    lines=lines[2:]
 
    if solve(ii):
      print 'Case #%d: GOOD'%case
    else:
      print 'Case #%d: BAD'%case
    case+=1


def solve(n):
  own=0
  prev=0
  for i in xrange(len(n)):
    if n[i]>i:
      own+=1
  return own < 505

def r(g):
  a=range(1000)
  for k in xrange(1000):
    if g:
      p = random.randint(k,1000-1)
    else:
      p = random.randint(0,1000-1)
    a1,a2=a[k], a[p]
    a[p]=a1
    a[k]=a2
  return a
"""
v=0
for i in xrange(500):
  v+=solve(r(False))
print v
"""
#print solve(r(False))


if __name__ == '__main__': 
  if len(sys.argv) != 2:
    print >> sys.stderr, "bad args"
    sys.exit(1)
  tc, l = readin(sys.argv[1])
  doall(tc, l)
  print >> sys.stderr, "done"

