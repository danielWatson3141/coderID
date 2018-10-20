#!/usr/bin/env python
import os
import sys
import time

tStart = time.time()

#---------------------------------------------------------------------

ifilename = 'input.in'
ofilename = 'results.out'

args = sys.argv
if len(args) > 1:
  ifilename = args[1]
if len(args) > 2:
  ofilename = args[2]

#---------------------------------------------------------------------
 
ifile = open(ifilename,'r')
data  = ifile.read()
ifile.close()
lines = data.splitlines()

ofile = open(ofilename, 'w')

#---------------------------------------------------------------------

def ones_cum(vector):
  cum = [0 for k in xrange(len(vector[0]))]
  for x in vector:
    for k in xrange(len(x)):
      if x[k] == '1':
        cum[k] += 1
  return cum

def flip(vector, flips):
  for n,x in enumerate(flips): 
    if x == 1:
      for k in xrange(len(vector)):
        if vector[k][n] == '1':
          vector[k] = vector[k][:n] + '0' + vector[k][(n+1):]
        else:
          vector[k] = vector[k][:n] + '1' + vector[k][(n+1):]
  return vector

def next_flip(flips, mask):

  ff = [flips[k] for k in xrange(len(flips)) if mask[k]==1]
  w  = sum(ff)
  if w == 0:
    ff[0] = 1
  elif sum(ff[(-w):])==w:
    ff = [int(k<=w) for k in xrange(len(ff))]
  else:
    for k in xrange(len(ff)-1):
      if ff[k] == 1 and ff[k+1] == 0:
        ff[k]   = 0
        ff[k+1] = 1
        wp = sum(ff[:k])
        ff[:k] = [int(n<wp) for n in xrange(len(ff[:k]))]
        break
  n = 0
  for k in xrange(len(flips)):
    if mask[k] == 1:
      flips[k] = ff[n]
      n += 1

  return flips

ncases = int(lines[0])
lines  = lines[1:]
for n in xrange(ncases):

  [N,L] = [int(x) for x in lines[0].split()]
  A     = lines[1].split()
  B     = lines[2].split()
  lines = lines[3:]

  a_cum  = ones_cum(A)
  b_cum  = ones_cum(B)

  la     = len(A)
  flips  = [0 for k in xrange(len(A[0]))]

  possible = 1
  for k in xrange(len(A[0])):
    if b_cum[k] != a_cum[k]:
      if b_cum[k] == (la - a_cum[k]):
        flips[k] = 1
      else:
        possible = 0
        break

  if possible == 0:
    res = 'NOT POSSIBLE'
  else:
    A = flip(A, flips)
    A.sort()
    B.sort()
    if A == B:
      res = '%d'%(sum(flips))
    else:
      if la%2 == 1:
        res = 'NOT POSSIBLE'
      else:
        e_flips = [int(x==la/2) for x in a_cum]
        if sum(e_flips) == 0:
          res = 'NOT POSSIBLE'
        else:
          new_flips = [0 for k in xrange(len(A[0]))]
          new_flips = next_flip(new_flips, e_flips)
          ne        = sum(e_flips)
          while 1:
            #print e_flips, new_flips
            Ap = flip([x for x in A], new_flips)
            Ap.sort()
            if Ap == B:
              flips = [(flips[k]+new_flips[k])%2 for k in xrange(len(flips))]
              res = '%d'%(sum(flips))
              break
            if sum(new_flips) == ne:
              res = 'NOT POSSIBLE'
              break
            new_flips = next_flip(new_flips, e_flips)

  # -------------------------------------------------
  res = 'Case #%d: %s'%(n+1, res)
  ofile.write('%s\n'%(res))
  print res

#---------------------------------------------------------------------

ofile.close()

print '\n Run time = ' + str((time.time() - tStart))     
