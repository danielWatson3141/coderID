#!/usr/bin/env python3

import sys

sys.setrecursionlimit(3000)

def size(H, r):
  return 1 + sum(size(H, c) for c in H[r])

def solve_root(H, r):
  if len(H[r]) == 0:
    return 0
  elif len(H[r]) == 1:
#    assert size(H, r) - 1 > 0
    return size(H, r) - 1
  else:
    solve_children = [(solve_root(H, c), size(H, c)) for c in H[r]]
    solve_children.sort(key=lambda s: s[0] - s[1])
    return sum(s[0] for s in solve_children[:2]) + sum(s[1] for s in solve_children[2:])

def rooted(N, G, r):
  H = {i : set() for i in range(1, N + 1)}
  queue = {r}
  visited = {r}
  while queue:
    x = queue.pop()
    for y in G[x]:
      if y not in visited:
        visited.add(y)
        H[x].add(y)
        queue.add(y)
  return H

def solve(problem):
#  print(*problem, file=sys.stderr)
  N, G = problem
  best = min(solve_root(rooted(N, G, r), r) for r in range(1, N + 1))
  return best

def read():
  N = int(input())
  G = {X : set() for X in range(1, N + 1)}
  for i in range(N - 1):
    X, Y = map(int, input().split())
    G[X].add(Y)
    G[Y].add(X)
  return N, G

def write(i, solution):
  print("Case #%d: %d" % (i + 1, solution))

def main():
  cases = int(input())
  for i in range(cases):
    problem = read()
    solution = solve(problem)
    write(i, solution)

if __name__ == "__main__":
  main()

