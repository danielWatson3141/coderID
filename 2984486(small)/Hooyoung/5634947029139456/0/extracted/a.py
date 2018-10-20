#!/usr/bin/env python

from collections import defaultdict

INF = 1000

def solve(pairs,L):
  if L == 0:
    return 0
  best = INF
  for flip in (0,1):
    newpairs = list()
    fail = False
    for (devs,outs) in pairs:
      xdevs = defaultdict(list)
      xouts = defaultdict(list)
      for dev in devs:
        xdevs[int(dev[0])].append(dev[1:])
      for out in outs:
        xouts[int(out[0])].append(out[1:])
      if len(xdevs[0]) != len(xouts[flip]) or len(xdevs[1]) != len(xouts[1-flip]):
        fail = True
        break
      newpairs.append((xdevs[0],xouts[flip]))
      newpairs.append((xdevs[1],xouts[1-flip]))
    if not fail:
      best = min(best,solve(newpairs,L-1)+flip)
  return best

T = int(raw_input())
for t in xrange(T):
  N,L = map(int,raw_input().split())
  devs = raw_input().split()
  outs = raw_input().split()
  ans = solve(((devs, outs),),L)
  if ans >= INF:
    print 'Case #%d: NOT POSSIBLE' % (t+1)
  else:
    print 'Case #%d: %d' % (t+1,ans)

