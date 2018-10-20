from collections import defaultdict

def solve(tcase):
  n, l = (int(e) for e in raw_input('').split())
  s = [int(e, 2) for e in raw_input('').split()]
  t = [int(e, 2) for e in raw_input('').split()]
  m1 = defaultdict(list)
  m2 = defaultdict(list)
  for i in xrange(n):
    chk = set()
    for j in xrange(n):
      x = s[i] ^ t[j]
      m1[x].append(i)
      m2[x].append(j)
      chk.add(x)
    assert len(chk) == n, "row %d error" % i
  
  r1, r2 = set(), set()
  exp = range(n)
  for x, lst in m1.iteritems():
    lst = sorted(lst)
    if lst == exp:
      r1.add(x)
  for x, lst in m2.iteritems():
    lst = sorted(lst)
    if lst == exp:
      r2.add(x)
  
  res = n * 100
  for e in (r1 & r2):
    tmp = sum(int(b) for b in bin(e)[2:])
    res = min(tmp, res)
  if res == n * 100:
    res = 'NOT POSSIBLE'
  
  print 'Case #%d: %s' % (tcase, str(res))

T = int(raw_input(''))
for tcase in xrange(1, T + 1):
  solve(tcase)