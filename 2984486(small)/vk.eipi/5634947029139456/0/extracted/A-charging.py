#!/usr/bin/python
import sys

def countOne(x):
  t = 0
  while x >0:
    t += x&1
    x >>= 1
  return t

def solve():
  N, L = map(int, sys.stdin.readline().split())
  i2 = lambda x: int(x,2)
  outlets = map(i2, sys.stdin.readline().split())
  devices = map(i2, sys.stdin.readline().split())
  devices.sort()
  minS = L+1
  for o1 in outlets:
    mask = devices[0] ^ o1
    newoutlets = sorted(map(lambda x:(x^mask), outlets))
    if (devices == newoutlets):
      minS = min(minS, countOne(mask))
  if minS <= L:
    return minS
  else:
    return "NOT POSSIBLE"

T = int(sys.stdin.readline())
for test_case in xrange(1, T+1):
  answer = solve()
  print "Case #{0}: {1}".format(test_case, answer)
