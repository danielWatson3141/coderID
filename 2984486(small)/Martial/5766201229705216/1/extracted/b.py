import sys
sys.setrecursionlimit(10000)

memo = {}
memo_size = {}
a = []
n = 0

def cost(root, parent):
  if (root, parent) in memo:
    return memo[(root, parent)]
  res = size(root, parent) - 1
  costs = []
  for v in a[root]:
    if v != parent:
      costs.append(cost(v, root) - size(v, root))
  costs.sort()
  if len(costs) >= 2:
    res = size(root, parent) - 1 + costs[0] + costs[1]
  memo[(root, parent)] = res
  return res

def size(root, parent):
  # number of nodes
  if (root, parent) in memo_size:
    return memo_size[(root, parent)]
  res = 1
  for v in a[root]:
    if v != parent:
      res += size(v, root)
  memo_size[(root, parent)] = res 
  return res
  
for case_index in range(1, 1+input()):
  n = input()
  a = [[] for k in range(n)]
  for i in range(n - 1):
    x, y = map(int, raw_input().split())
    x -= 1
    y -= 1
    a[x].append(y)
    a[y].append(x)
  memo = {}
  memo_size = {}
    
  res = n
  for i in range(n):
    c = cost(i, -1)
    if c < res:
      res = c
    
  sys.stderr.write(str(case_index)+' ')
  print 'Case #%s: %d'%(case_index,res)

sys.stderr.write('\n')

