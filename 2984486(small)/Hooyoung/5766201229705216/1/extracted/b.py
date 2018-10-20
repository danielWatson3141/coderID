#!/usr/bin/env python

def s(g,i,p):
  if (i==p and len(g[i])==1) or (i!=p and len(g[i])==2): return 1
  return 1+sum(sorted([s(g,x,i) for x in g[i] if x != p],reverse=True)[:2])

from collections import defaultdict
T = int(raw_input())
for t in xrange(T):
  N = int(raw_input())
  nei = defaultdict(list)
  for i in xrange(N-1):
    x,y = map(int,raw_input().split())
    x-=1
    y-=1
    nei[x].append(y)
    nei[y].append(x)
  m = 0
  for i in xrange(N): 
    m = max(m,s(nei,i,i))
  print 'Case #%d: %d' % (t+1,N-m)
  
