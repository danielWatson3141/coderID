def rooted_bin_cost(alist, root):
  def rbc(root, parent):
    cost, total = 0, 1
    tlist = []
    for child in alist[root]:
      if child == parent:
        continue
      c, t = rbc(child, root)
      total += t
      tlist.append(t - c)
      cost += c
    tlist.sort()
    cost += sum(tlist) if len(tlist) <= 1 else sum(tlist[:-2])
    return cost, total
  return rbc(root, None)[0]

T = int(input())
for t in range(1, T + 1):
  N = int(input())
  alist = [[] for _ in range(N)]
  for n in range(N - 1):
    x, y = map(int, input().split())
    x, y = x - 1, y - 1
    alist[x].append(y)
    alist[y].append(x)
  ans = N + 1
  for r in range(N):
    tans = rooted_bin_cost(alist, r)
    if tans < ans:
      ans = tans
  print("Case #{}: {}".format(t, ans))
