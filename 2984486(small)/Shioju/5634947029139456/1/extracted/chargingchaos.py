import sys

def solve(N, L, outlets, devices):
  for (flips, i) in gen(L):
    ok = True
    for outlet in outlets:
      if not (outlet ^ i in devices):
        ok = False
        break
    if ok:
      return flips
  return 'NOT POSSIBLE'

def gen(L):
  yield (0,0)
  over = 2**L
  newset = [0]
  for i in range(1, L+1):
    tempset = []
    # append a 1
    for item in newset:
      newitem = (item<<1) | 1
      if newitem < over:
        tempset += [newitem]
    newset = []
    # shift left
    for temp in tempset:
      while (temp<over):
        print temp
        yield (i, temp)
        newset += [temp]
        temp <<= 1

def main():
  T = int(sys.stdin.readline())
  for i in xrange(T):
    (N, L) = [int(x) for x in sys.stdin.readline().split()]
    outlets = [int(x,2) for x in sys.stdin.readline().split()]
    devices = [int(x,2) for x in sys.stdin.readline().split()]
    result = solve(N, L, outlets, devices)
    
    print "Case #%d: %s" % (i+1, result)

main()