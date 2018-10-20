# from __future__ import division
# import math
# import numpy as np
# import bisect
import itertools
import collections

fname = "A-large.in.txt"
# fname = "test.in"

def solve(N,L,A,B):
  # print N, L
  # print A
  # print B
  
  if N == 1:
    return diff(A[0],B[0])

  # combA = []
  # lA = []

  matA = [[None for _ in range(N)] for _ in range(N)]

  for i, j in itertools.combinations(range(N), 2):
    # combA.append((c1, c2))
    l = []
    for k in xrange(L):
      if A[i][k] == A[j][k]:
        l.append("0")
      else:
        l.append("1")
    matA[i][j] = "".join(l)
    matA[j][i] = "".join(l)

  matB = [[None for _ in xrange(N)] for _ in xrange(N)]

  for i, j in itertools.combinations(range(N), 2):
    # combA.append((c1, c2))
    l = []
    for k in xrange(L):
      if B[i][k] == B[j][k]:
        l.append("0")
      else:
        l.append("1")
    matB[i][j] = "".join(l)
    matB[j][i] = "".join(l)

  mA = [set(filter(None, lst)) for lst in matA]
  mB = [set(filter(None, lst)) for lst in matB]
  # print mA
  # print mB

  fi = []
  f0 = []
  for i in xrange(N):
    for j in xrange(N):
      if mA[i] == mB[j]:
        fi.append((i,j))
        if i == 0:
          f0.append((i,j))

  # print fi
  if len(fi) == 0:
    return "NOT POSSIBLE"
  if len(fi) == N:
    x, y = fi[0]
    return diff(A[x], B[y])
  else:
    mn = 10000
    for x,y in f0:
      mn = min(mn, diff(A[x], B[y]))
    return mn

  # print matA
  # print matB

  # print lA, set(lA)
  # print lB
  # assert len(set(lA)) == len(lA)
  # if set(lA) != set(lB):
  # if collections.Counter(lA) != collections.Counter(lB):
  #   return "NOT POSSIBLE"
  # else:
  #   el = collections.Counter(lA).most_common()[-1][0]
  #   print el
  #   P = [combA[i] for i, x in enumerate(lA) if x == el]
  #   Q = [combB[i] for i, x in enumerate(lB) if x == el]
  #   # uniA = set([x for x in lA if lA.count(x) == 1])
  #   # assert len(uniA) > 0
  #   # uniB = set([x for x in lB if lB.count(x) == 1])
  #   # uni = uniA & uniB
  #   # assert len(uni) > 0
  #   # print lA
  #   # print lB
  #   # el = uni.pop()
  #   # y = lA.index(el)
  #   # x = lB.index(el)
  #   # P = combA[y]
  #   # Q = combB[x]
  #   print P
  #   print Q
  #   P = P[0]
  #   mi = 100
  #   for q in Q:
  #     mi = min(mi, diff(P[0], q[0]), diff(P[0], q[1]))
  #   return mi
    # calculate differences
    # return min(diff(P[0], Q[0]), diff(P[0], Q[1]))

def diff(X,Y):
  ct = 0
  for i in xrange(len(X)):
    if X[i] != Y[i]:
      ct += 1

  return ct

def main():
  with open(fname) as f:
    for i in xrange(int(f.readline())):
      N, L = map(int,f.readline().split())
      A = f.readline().split()
      B = f.readline().split()
      print 'Case #%s: %s' % (i + 1, solve(N,L,A,B))
  
main()