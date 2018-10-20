#!/usr/bin/env python3

import sys, math

cases = int(sys.stdin.readline())
for case_no in range(1, cases + 1):
  N = int(sys.stdin.readline())
  edges = set()
  adj_mat = [[False for i in range(N)] for j in range(N)]
  edge_mat = [set() for i in range(N)]
  for i in range(N - 1):
    a, b = [int(val) for val in sys.stdin.readline().strip().split()]
    a -= 1
    b -= 1
    edges.add((a, b))
    edges.add((b, a))
    adj_mat[a][b] = True
    adj_mat[b][a] = True
    edge_mat[a].add((a, b))
    edge_mat[b].add((b, a))

  # Work out costs for deletion
  needed = [sum(adj_mat[i]) for i in range(N)]
  scores = {edge: (-1, -1) for edge in edges}
  todo = set()
  for i in range(len(needed)):
    if needed[i] == 1:
      for edge in edge_mat[i]:
        todo.add(edge)

  while len(todo) > 0:
    cedge = todo.pop()
    cur = None
    messages = []
    total_dcost = 0
    for edge in edge_mat[cedge[0]]:
      if edge == cedge:
        continue
      edge = (edge[1], edge[0])
      kcost, dcost = scores[edge]
      total_dcost += dcost
      messages.append((kcost, dcost))

    best = -1
    for i in range(len(messages)):
      for j in range(i):
        m1 = messages[i]
        m2 = messages[j]
        cost = m1[0] + m2[0] + total_dcost - m1[1] - m2[1]
        if cost < best or best < 0:
          best = cost
    if best < 0:
      best = 0
      if len(messages) == 1:
        best = total_dcost
    total_dcost += 1
    total_kcost = best
    scores[cedge] = (total_kcost, total_dcost)
    needed[cedge[1]] -= 1
    if needed[cedge[1]] == 1:
      for edge in edge_mat[cedge[1]]:
        if scores[(edge[1], edge[0])][0] == -1:
          todo.add(edge)
    elif needed[cedge[1]] == 0:
      for edge in edge_mat[cedge[1]]:
        if scores[edge][0] == -1:
          todo.add(edge)

  # Choose root
  best_node = None
  for node in range(N):
    # find best 2
    messages = []
    total_dcost = 0
    for edge in edge_mat[node]:
      edge = (edge[1], edge[0])
      kcost, dcost = scores[edge]
      total_dcost += dcost
      messages.append((kcost, dcost))

    best = -1
    for i in range(len(messages)):
      for j in range(i):
        m1 = messages[i]
        m2 = messages[j]
        cost = m1[0] + m2[0] + total_dcost - m1[1] - m2[1]
        if cost < best or best < 0:
          best = cost
    if best < 0:
      best = 0
      if len(messages) == 1:
        best = total_dcost
    if best_node is None or best_node[1] > best:
      best_node = (node, best)

###  for score in scores:
###    print(score[0] + 1, score[1] + 1, scores[score])
###  print(best_node[0] + 1, best_node[1])
  ans = best_node[1]
  print("Case #{}: {}".format(case_no, ans))
