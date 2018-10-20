import sys

def strxor(a, b):
  return ''.join('0' if c==d else '1' for c, d in zip(a, b))

def doprob():
  n, l = map(int, input().split())
  outlets = list(sorted(input().split()))
  devices = list(sorted(input().split()))

  possibles = set(strxor(a, b) for a in outlets for b in devices)
  possibles = list(sorted(possibles, key=lambda x:sum(1 for c in x if c=='1')))

  for p in possibles:
    newout = list(sorted(strxor(a, p) for a in outlets))
    if newout == devices:
      return str(sum(1 for c in p if c == '1'))

  return 'NOT POSSIBLE'



ncases = int(input())
for caseno in range(1, ncases+1):
  ans = doprob()
  print('Case #%d: %s' % (caseno, ans))
  sys.stderr.write('%d\n' % caseno)
