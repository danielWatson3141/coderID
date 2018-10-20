# Round 1A
# Problem A


fname = "A-small-attempt0.in"


def flip(mask,outlets):
  newoutlets = []
  for out in outlets:
    newoutlets.append(out^mask)
  return newoutlets

def count1s(n):
  b = bin(n)[2:]
  return b.count('1')
  
f = open(fname,"r")
T = int(f.readline())
for case in range(1,T+1):
  [N,L] = f.readline().split()
  N = int(N)
  L = int(L)
  outlets = map(lambda x: int(x,2), f.readline().split())
  devices = map(lambda x: int(x,2), f.readline().split())
  devices.sort()
  goodmasks = []
  for mask in range(2**L):
    newoutlets = flip(mask,outlets)
    newoutlets.sort()
    if newoutlets==devices:
      goodmasks.append(mask)
  if len(goodmasks)==0:
    print "Case #%i: NOT POSSIBLE" % (case)
  else:
    goodmasks = map(count1s,goodmasks)
    print "Case #%i: %i" % (case,min(goodmasks))
    
  
    
  
