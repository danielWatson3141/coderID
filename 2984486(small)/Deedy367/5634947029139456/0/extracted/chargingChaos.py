import sys
from IPython.core.debugger import Tracer
from random import randrange
from operator import mul
import sys
from IPython.core.debugger import Tracer
import math
import random
from Queue import PriorityQueue

def flipper(curr, ind):

  N = len(random.sample(curr,1))
  L = len(curr)
  newcurr = []
  # Tracer()()
  for x in curr:
    if x[ind] == '0':
      x=x[:ind] + '1' + x[ind+1:]
    else:
      x=x[:ind] + '0' + x[ind+1:]
    newcurr.append(x)
  return sorted(newcurr)

def getPriority(curr, required):
  return 1

def chargingChaos(f):
  soln = ''
  cases = int(f.readline())
  for case in xrange(cases):
    row = f.readline().split(' ')
    N = int(row[0])
    L = int(row[1])
      # Tracer()()
    current = sorted(f.readline().strip().split(' '))
    required = sorted(f.readline().strip().split(' '))
    # Tracer()()
    states = PriorityQueue()
    states.put((0, current, 0))
    visited = set({})
    visited.add(' '.join(current))
    found = False
    sol = 0
    while not states.qsize() == 0:
      topstr = states.get()
      top = topstr[1]
      steps = topstr[2]
      # Tracer()()
      if len([1 for x,y in zip(required, top) if not x==y]) == 0:
        found = True
        sol = steps
        break;
      for i in xrange(L):
        if i >= L:
          Tracer()()
        nextstate = flipper(top, i)
        # Tracer()()
        if not ' '.join(nextstate) in visited:
          visited.add(' '.join(nextstate))
          states.put((steps+1, nextstate, steps+1))
      # print states.qsize()
      # Tracer()()
    if not found:
      steps = "NOT POSSIBLE"
    soln += 'Case #{0}: {1}\n'.format(case+1, steps)
    # print soln
  return soln

def writeOutput(file, soln):
  file.write(soln)
  file.close()

if __name__ == '__main__':
  f = open(sys.argv[1])
  soln = chargingChaos(f)
  f.close()
  g = open("output.txt", "w")
  writeOutput(g, soln)

