T = input()
for tc in range(1, T + 1):
  N, L = [int(x) for x in raw_input().split()]
  start = raw_input().split()
  end = raw_input().split()
  bstart = [int(x, 2) for x in start]
  bend = [int(x, 2) for x in end]
  ans = 2 * L
  for n1 in range(N):
    for n2 in range(N):
      flips = bstart[n1] ^ bend[n2]
      habo = {}
      for n3 in range(N):
        habo[flips ^ bstart[n3]] = 1
      good = True
      for n3 in range(N):
        if bend[n3] not in habo:
          good = False
      if good:
        ans = min(ans, bin(flips).count("1"))
  if ans == 2 * L:
    ans = "NOT POSSIBLE"
  print "Case #" + str(tc) + ":", ans
