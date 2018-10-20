#!/usr/bin/env python

import random
import numpy

"""
T = 30000
N=1000
x=numpy.zeros((N,N))

for i in xrange(T):
  a = range(N)
  for k in xrange(N):
    p = random.randrange(0,N)
    a[k],a[p] = a[p],a[k]
  for k in xrange(N):
    x[k,a[k]] += 1
  if i % 1000 == 0: print i

x.tofile('cdata')

"""
N=1000
x = numpy.fromfile('cdata').reshape((N,N))

T=1000
print 'bad'
sts_bad = numpy.zeros(T)
for i in xrange(T):
  a = range(N)
  for k in xrange(N):
    p = random.randrange(0,N)
    a[k],a[p] = a[p],a[k]
  st = 0
  for k in xrange(N):
    if x[k,a[k]]>30:
      st+=(x[k,a[k]]-30)**2
  sts_bad[i]=(st)
  if i % 1000 == 0: print i
print sts_bad.mean()
print 'good'
sts_good = numpy.zeros(T)
T=1000
for i in xrange(T):
  a = range(N)
  for k in xrange(N):
    p = random.randrange(k,N)
    a[k],a[p] = a[p],a[k]
  st = 0
  for k in xrange(N):
    if x[k,a[k]]>30:
      st+=(x[k,a[k]]-30)**2
  sts_good[i]=(st)
  if i % 1000 == 0: print i
print sts_good.mean()
from matplotlib import pyplot
pyplot.hist(sts_bad,label='bad')
pyplot.hist(sts_good,label='good')
pyplot.legend()
pyplot.show()

