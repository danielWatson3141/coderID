import sys
from IPython.core.debugger import Tracer
from random import randrange
from operator import mul
import sys
from IPython.core.debugger import Tracer
import math
import random
from Queue import PriorityQueue

def getallpairs(l,k):
  l.remove(k)
  pairs = set({})
  for x in l:
    for y in l:
      if not x == y:
        pairs.add(tuple(sorted((x,y))))
  return pairs


def checknodes(graph,lastcall, root):
  summ = 1
  if len(graph[root]) > 3:
    pairs = getallpairs(list(graph[root]), lastcall)
    res = []
    # Tracer()()
    for pair in pairs:
      ressum = 1
      # Tracer()()
      for ele in pair:
        if lastcall == None or not ele == lastcall:
          if len(graph[ele]) == 1:
            ressum += 1
          elif len(graph[ele]) == 2:
            ressum += 1
          else:
            ressum += checknodes(graph, root, ele)
      res.append(ressum)
    summ = max(res)
  else:
    for ele in graph[root]:
      if lastcall == None or not ele == lastcall:
        if len(graph[ele]) == 1:
          summ += 1
        elif len(graph[ele]) == 2:
          summ += 1
        else:
          summ += checknodes(graph, root, ele)
  # Tracer()()
  return summ


def fullBinaryTree(f):
  soln = ''
  cases = int(f.readline())
  for case in xrange(cases):
    nodes = int(f.readline())
    graph = {}
    for i in xrange(nodes):
      graph[i+1] = set({})
    for i in xrange(nodes-1):

      edge = f.readline().strip().split(' ')
      node1 = int(edge[0])
      node2 = int(edge[1])
      graph[node1].add(node2)
      graph[node2].add(node1)
      # Tracer()()

    roots = [x for x in graph if len(graph[x]) == 2]

    res = []
    # roots = [11]
    for root in roots:
      # Tracer()()
      res.append(checknodes(graph, None, root))
    if len(res) > 0:
      sol = nodes - max(res)
    else:
      sol = nodes
    # print sol
    # Tracer()()


    soln += 'Case #{0}: {1}\n'.format(case+1, sol)
    # print soln
  return soln

def writeOutput(file, soln):
  file.write(soln)
  file.close()

if __name__ == '__main__':
  f = open(sys.argv[1])
  soln = fullBinaryTree(f)
  f.close()
  g = open("output.txt", "w")
  writeOutput(g, soln)

