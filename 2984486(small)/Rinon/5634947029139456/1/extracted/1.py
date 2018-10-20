import sys
words = []

sys.stdin.readline()

# from https://wiki.python.org/moin/BitManipulation
def bitCount(int_type):
  count = 0
  while(int_type):
    int_type &= int_type - 1
    count += 1
  return(count)

# from https://wiki.python.org/moin/BitManipulation
def lowestSet(int_type):
  low = (int_type & -int_type)
  lowBit = -1
  while (low):
    low >>= 1
    lowBit += 1
  return(lowBit)

def tocols(o):
  ocols = []
  for i in range(len(o[0])):
    ocols.append('')
  for i in range(len(o[0])):
    for j in range(len(o)):
      ocols[i] += o[j][i]
  return ocols
  

def solve(n, l, o, d):
  ocols = [int(x,2) for x in tocols(o)]
  dcols = [int(x,2) for x in tocols(d)]

  o = [int(x,2) for x in o]
  d = [int(x,2) for x in d]

  o.sort()
  d.sort()

  ocount = map(bitCount, ocols)
  dcount = map(bitCount, dcols)

  for (oc, dc) in zip(ocount, dcount):
    if oc != dc and n-oc != dc:
      return -1

  min = l
  for x in o:
    mask = x^d[0]
    newo = [x^mask for x in o]
    newo.sort()
    if newo == d and bitCount(mask) < min:
      min = bitCount(mask)

  return min


case = 0

while True:
  case += 1
  line = sys.stdin.readline()
  if line == '':
    break
  (n,l) = map(int, line.split())
  o = sys.stdin.readline().split()
  d = sys.stdin.readline().split()

  num = solve(n, l, o, d)
  if num == -1:
    print('Case #%d: NOT POSSIBLE' % case)
  else:
    print('Case #%d: %d' % (case, num))
