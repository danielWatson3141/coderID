import sys
sys.setrecursionlimit(10000)

# Returns (numdelsofar, size of subtree)
def mindel(tree, node, parent=set()):
  partials = [mindel(tree, n, {node}) for n in tree[node] - parent]
  delsofar = sum(a for a, b, in partials)
  subtrees = [b for a, b in partials]

  if len(subtrees) == 0:
    return (delsofar, 1)
  if len(subtrees) == 1:
    return (delsofar + subtrees[0], 1)
  if len(subtrees) == 2:
    return (delsofar, sum(subtrees) + 1)
  if len(subtrees) > 2:
    subtrees.sort()
    return (delsofar + sum(subtrees[:-2]), 1 + sum(subtrees[-2:]))


def doprob():
  n = int(input())

  tree = {i:set() for i in range(1, n+1)}
  for i in range(n-1):
    a, b = map(int, input().split())
    tree[a] |= {b}
    tree[b] |= {a}

  return min(mindel(tree, node)[0] for node in tree)


ncases = int(input())
for caseno in range(1, ncases+1):
  ans = doprob()
  print('Case #%d: %d' % (caseno, ans))
