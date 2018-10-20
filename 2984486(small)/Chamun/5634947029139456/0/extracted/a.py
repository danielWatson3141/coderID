#!/usr/bin/python3
import sys
 
def line():
  return sys.stdin.readline().strip()

def binrange(a):
  return len(str(bin(a)[2:]))

def count(d, o):
  c = 0
  for i in range(max(binrange(d), binrange(o))):
    if (d & 1) != (o & 1):
      c = c + 1
    d = d >> 1
    o = o >> 1
  return c

def solve(devices, outlets):
  ans = 100
  found = False

  outlets.sort()
  devices.sort()

  if devices == outlets:
    return 0

  d = devices[0]
  for o in outlets:
    mask = d ^ o

    noutlets = [x ^ mask for x in outlets]
    noutlets.sort()

    if devices == noutlets:
      chgbits = count(d, o)
      found = True
      ans = min(chgbits, ans)
    
  if found:
    return ans
  return -1

cases = int(line())
for i in range(cases):
  n, l = [int(x) for x in line().split(" ")]
  outlets = [int(x, 2) for x in line().split(" ")]
  devices = [int(x, 2) for x in line().split(" ")]
  ans = solve(outlets, devices)
  if ans >= 0:
    print ("Case #{}: {}".format(i+1, ans))
  else:
    print ("Case #{}: NOT POSSIBLE".format(i+1))
