
def test(u, N, f): # kolik zustane, kolik celkem vcetne
  P = []
  for v in N[u]:
    if v != f:
      P.append(test(v, N, u))

  if len(P) == 0: return (1, 1)
  if len(P) == 1: return (1, 1 + P[0][1])
  P.sort()
  return (1+P[-1][0]+P[-2][0], 1+sum(x[1] for x in P))

T = int(raw_input())
for i in range(T):
  n = int(raw_input())
  N = [[] for j in range(n)]
  for j in range(n-1):
    x, y = [int(x) for x in raw_input().split()]
    N[x-1].append(y-1)
    N[y-1].append(x-1)

  mind = n
  for j in range(n):
    cand = test(j, N, None)
    #print cand
    mind = min(cand[1]-cand[0], mind)

  print "Case #%i: %i"%(i+1, mind)