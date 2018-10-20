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
  for f in F:
    s = f^R[0]
    nF = map(lambda x: x^s, F)
    nF.sort()
    if R == nF:
      best = min(best, bin(s).count('1'))
  if best == L+1:
    print 'NOT POSSIBLE'
  else:
    print best
