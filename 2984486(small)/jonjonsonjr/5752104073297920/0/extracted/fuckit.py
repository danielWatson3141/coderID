import sys

tests = int(sys.stdin.readline())

for i in range(0, tests):
  length = int(sys.stdin.readline())
  line = [int(n) for n in sys.stdin.readline().split()]

  num = 0
  for j in range(0, length):
      if j == line[j]:
          num = num + 1

  perc = 1.0/length
  obs = float(num)/length

  if obs > perc:
      print "Case #%d: GOOD" % ((i + 1))
  else:
      print "Case #%d: BAD" % ((i + 1))
