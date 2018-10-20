f = open('c.txt')
T = int(f.readline())
total_bad = 0
for turn in range(1, T+1):
  f.readline()
  permutation = [int(x) for x in f.readline().strip().split()]

  half = len(permutation)/2
  count = 0
  for i in range(half):
    if i < permutation[i] < i + half:
      count += 0.87
      count += (i + half - permutation[i]) / 1.0 / half
    if permutation[i] < i:
      count -= (half - (i - permutation[i])) / 1.0 / half
    if permutation[i] > i + half:
      count -= (permutation[i] - (i - half)) / 1.0 / half
      # if i < permutation[i] < i + 3:
      #   count += 2
      # if i < permutation[i] < i + 10:
      #   count += 1
      # if i < permutation[i] < i + 30:
      #   count += 0.2
  # print count, half
  if count > 8:
    decision = "BAD"
    total_bad += 1
  else:
    decision = "GOOD"
  print "Case #" + str(turn) + ":", decision
# print total_bad, T