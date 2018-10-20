def readint(): return int(raw_input())
def readarray(f): return map(f, raw_input().split())

def dist(l):
  s = 0
  for i in range(len(l)-1):
    s += abs(l[i] - l[i+1])
  return s

value = 333018.3435
if value == -1:
  from random import randint
  def good(N):
    a = range(N)
    for k in range(N):
      p = randint(k, N-1)
      a[k], a[p] = a[p], a[k]
    return a
  def bad(N):
    a = range(N)
    for k in range(N):
      p = randint(0, N-1)
      a[k], a[p] = a[p], a[k]
    return a
  Dbad = 0
  DSbad = 0
  Dgood = 0
  DSgood = 0
  N = 1000
  for i in range(N):
    l = bad(1000)
    d = dist(l)
    Dbad += d
    DSbad += d*d
    l = good(1000)
    d = dist(l)
    Dgood += d
    DSgood += d*d
  mBad = Dbad/(N+0.0)
  mGood = Dgood/(N+0.0)
  vBad = DSbad/(N+0.0) - mBad*mBad
  vGood = DSgood/(N+0.0) - mGood*mGood
  print mBad, vBad
  print mGood, vGood
  print (mBad+mGood)/2
  exit()

_T = readint()
for _t in range(_T):
  print 'Case #%i:'%(_t+1),
  N = readint()
  P = readarray(int)
  d = dist(P)
  if d < value:
    print 'BAD'
  else:
    print 'GOOD'
