#!/usr/bin/env python

import random
import numpy
x = numpy.fromfile('cdata').reshape((1000,1000))
thres=24000

T = int(raw_input())
for i in xrange(T):
  N = int(raw_input())
  a = map(int,raw_input().split())
  st=0
  for k in xrange(N):
    if x[k,a[k]]>30:
      st+=(x[k,a[k]]-30)**2
  print 'Case #%d: %s' %(i+1,'GOOD' if st<thres else 'BAD')

