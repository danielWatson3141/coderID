def readint(): return int(raw_input())
def readarray(f): return map(f, raw_input().split())

_T = readint()
for _t in range(_T):
  print 'Case #%i:'%(_t+1),
  N, L = readarray(int)
  F = readarray(lambda x: int(x, base=2))
  R = readarray(lambda x: int(x, base=2))
  R.sort()

  best = L+1
  for S in range(1<<L):
    nF = map(lambda x: x^S, F)
    nF.sort()
    if nF == R:
      best = min(bin(S).count('1'), best)
  if best == L+1:
    print 'NOT POSSIBLE'
  else:
    print best
