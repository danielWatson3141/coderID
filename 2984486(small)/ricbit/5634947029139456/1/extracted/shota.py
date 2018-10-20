def count(a, b):  
  m = a ^ b
  ans = 0
  while m:
    if m & 1 == 1:
      ans += 1
    m >>= 1
  return ans

for tot in xrange(input()):
  n, l = map(int, raw_input().split())
  initial = [int(i, 2) for i in raw_input().split()]
  initial.sort()
  goal = [int(i, 2) for i in raw_input().split()]
  solution = l + 10
  for i in xrange(n):
    mask = initial[0] ^ goal[i]
    neigh = [x ^ mask for x in goal]
    neigh.sort()
    if neigh == initial:
      solution = min(solution, count(initial[0], goal[i]))
  if solution > l:
    print "Case #%d: NOT POSSIBLE" % (tot + 1)
  else:
    print "Case #%d: %d" % (tot + 1, solution)
      
