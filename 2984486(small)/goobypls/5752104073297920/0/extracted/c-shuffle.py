import random
from collections import defaultdict
import sys
random.seed(99109)

def bad(n):
  l = list(range(n))
  for i in range(n):
    p = random.randint(0, n-1)
    l[i], l[p] = l[p], l[i]
  return l

tries = 50000
n = 1000
poses = []
with open('record', 'r') as f:
  poses = eval(f.read())

#for i in range(tries):
#  l = bad(n)
#  for i, x in enumerate(l):
#    poses[i][x] += 1

#sys.stderr.write('done\n')
#with open('record', 'w') as f:
#  f.write(repr(poses))

classify = [[1 if n*x >= tries else -1 for x in l] for l in poses]

def score(l):
  return sum(classify[i][x] for i, x in enumerate(l))

ncases = int(raw_input())
for caseno in range(1, ncases+1):
  raw_input()
  x = list(map(int, raw_input().split()))
  word = 'BAD' if score(x) > 0 else 'GOOD'
  print ('Case #%d:' % caseno), word
