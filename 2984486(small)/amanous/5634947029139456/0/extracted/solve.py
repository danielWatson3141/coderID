#!/usr/bin/env python

import itertools

T = int(raw_input())

def read_problem():
  N, L = [ int(e) for e in raw_input().split() ]
  O = [ int(e, 2) for e in raw_input().split() ]
  D = [ int(e, 2) for e in raw_input().split() ]
  return N, L, O, D

def switch(O, indexes):
  m = 0
  for i in indexes:
    m |= (1<<i)
  return [ v ^ m for v in O ]

def solve(problem):
  N, L, O, D = problem
  sD = set(D)
  sO = set(O)
  if sD == sO:
    return 0
  push = 1
  while push <= L:
    for indexes in itertools.combinations(range(L), push):
      sO = set(switch(O, indexes))
      if sD == sO:
        return push
    push += 1
  else:
    return "NOT POSSIBLE"

for n in range(T):
  problem = read_problem()
  solution = solve(problem)
  print 'Case #%d: %s' %(n+1, solution)

