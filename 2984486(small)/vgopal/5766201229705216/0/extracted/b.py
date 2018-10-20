def num_on_path(i, edges):
  keys = set(edges[i])
  keys.add(i)
  while True:
    length = len(keys)
    adding = []
    for key in keys:
      adding.extend(edges[key])
    keys.update(adding)
    if len(keys) == length:
      return len(keys)

def num_delete(i, N, edges):
  if len(edges[i]) == 2:
    c1, c2 = edges[i]
    edges[c1].remove(i)
    edges[c2].remove(i)
    edges[i] = []
    return num_delete(c1, N, edges) + num_delete(c2, N, edges)
  elif len(edges[i]) == 0:
    return 0
  elif len(edges[i]) > 2:
    my_edges = edges[i]
    for edge in my_edges:
      edges[edge].remove(i)
    edges[i] = []
    values = []

    for edge in my_edges:
      num_path = num_on_path(edge, edges)
      num_d = num_delete(edge, N, edges)
      num = num_path - num_d
      values.append((num, num_d, num_path))
    values = sorted(values)[::-1]
    # print values
    return values[0][1] + values[1][1] + sum(x[2] for x in values[2:])
    # return sum(values[2:])
  else:
    return num_on_path(i, edges) - 1

def copy_dict(edges):
  new_edges = defaultdict(list)
  for i in edges:
    new_edges[i].extend(edges[i])
  return new_edges

from collections import defaultdict

f = open('b_small.txt')
T = int(f.readline())
for turn in range(1, T+1):
  N = int(f.readline())
  edges = defaultdict(list)
  for _ in range(N-1):
    x,y = [int(x) for x in f.readline().strip().split()]
    edges[x].append(y)
    edges[y].append(x)

  # if turn != 2:
  #   continue
  # print N, edges
  minimum = N
  # print num_delete(7, N, edges.copy())
  for i in range(1,N+1):
    # print edges
    num = num_delete(i, N, copy_dict(edges))
    # print i, num
    minimum = min(num, minimum)
  print "Case #" + str(turn) + ":", minimum