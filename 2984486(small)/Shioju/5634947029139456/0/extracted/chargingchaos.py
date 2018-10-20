import sys

def solve(N, L, outlets, devices):
  result = L+1 # can't be larger than L
  for i in xrange(2**L):
    ok = True
    for outlet in outlets:
      if not (outlet ^ i in devices):
        ok = False
        break
    if ok:
      result = min(ones(i), result)
  if result <= L:
    return result
  else:
    return 'NOT POSSIBLE'

def ones(i):
  result = 0
  while (i>0):
    result+= i & 1
    i = i>>1
  return result

def main():
  T = int(sys.stdin.readline())
  for i in xrange(T):
    (N, L) = [int(x) for x in sys.stdin.readline().split()]
    outlets = [int(x,2) for x in sys.stdin.readline().split()]
    devices = [int(x,2) for x in sys.stdin.readline().split()]
    result = solve(N, L, outlets, devices)
    
    print "Case #%d: %s" % (i+1, result)

main()