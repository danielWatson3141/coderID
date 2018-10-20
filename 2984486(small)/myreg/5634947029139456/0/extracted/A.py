
def switch(p):
  global A
  for x in A:
    x[p] = 1 - x[p]
  A.sort()

def test(p):
  global A,B,n,l;
  if p == l: return 0
  ok = True
  #
  for x in range(n):
    if A[x][p] != B[x][p]:
      ok = False
      break
  m1 = l + 1
  if ok: m1 = test(p+1);
  #
  ok = True
  switch(p)
  for x in range(n):
    if A[x][p] != B[x][p]:
      ok = False
      break
  m2 = l + 1
  if ok: m2 = 1 + test(p+1);
  switch(p)
  return min(m1, m2)

T = int(raw_input())

for i in range(T):
  n, l = [int(x) for x in raw_input().split()]
  A = [list(int(x) for x in y) for y in raw_input().split()]
  B = [list(int(x) for x in y) for y in raw_input().split()]
  A.sort()
  B.sort()
  num = test(0)
  if num > l:
    print "Case #%i: NOT POSSIBLE"%(i+1)
  else:
    print "Case #%i: %i"%(i+1, num)


