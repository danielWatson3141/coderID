import sys

def conv(w):
  L = len(w)
  res = 0
  for i in range(L):
    if w[i] == '1':
      res += 1<<i
  return res
  
for case_index in range(1, 1+input()):
  N, L = map(int, raw_input().split())
  s = map(conv, raw_input().split())
  t = map(conv, raw_input().split())
  s.sort()
  t.sort()
  possible = False
  best = L + 1
  for i in range(N):
    r = 0
    flip = 0
    for k in range(L):
      flip = s[0] ^ t[i]
      r = bin(flip).count('1') 
    u = [s[j] ^ flip for j in range(N)]
    u.sort()
    if u == t:
      possible = True
      if r < best:
        best = r
  if possible:
    res = str(best)
  else:
    res = 'NOT POSSIBLE'
    
      
  sys.stderr.write(str(case_index)+' ')
  print 'Case #%s: %s'%(case_index,res)

sys.stderr.write('\n')

