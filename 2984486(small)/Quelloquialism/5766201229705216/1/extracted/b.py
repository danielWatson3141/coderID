from collections import defaultdict
import sys

sys.setrecursionlimit(10000)

x = defaultdict(list)

def sizeof(r, p):
  global x
  ans = 1
  for i in x[r]:
    if i != p:
      ans += sizeof(i, r)
  return ans

def score(r, p):
  global x
  child = []
  for i in x[r]:
    if i != p:
      child.append(i)
  if len(child) == 0:
    return 0, 1
  elif len(child) == 1:
    size = sizeof(child[0], r)
    return size, size + 1
  elif len(child) == 2:
    sc0, sz0 = score(child[0], r)
    sc1, sz1 = score(child[1], r)
    return sc0 + sc1, sz0 + sz1 + 1
  else: # too many children
    ans = 0
    scs = []
    for i in child:
      sc, sr = score(i, r)
      ans += sr
      scs.append(sr - sc)
    scs.sort()
    return ans - scs[-1] - scs[-2], ans + 1

T = input()
for i in range(1, T + 1):
  N = input()
  x = defaultdict(list)
  for j in range(N - 1):
    a, b = [int(y) for y in raw_input().split()]
    a -= 1
    b -= 1
    x[a].append(b)
    x[b].append(a)
  ans = N
  for j in range(N):
    ans = min(ans, score(j, -1)[0])
  print "Case #" + str(i) + ":", ans
