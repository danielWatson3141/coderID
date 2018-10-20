import sys

def flip(i, plugs):
    for j in range(0, len(plugs)):
        if plugs[j][i] == '0':
            plugs[j][i] = '1'
        else:
            plugs[j][i] = '0'

    return plugs

def test(plugs, goal):
    stuff = [[int(n)  for n in bin(b)[2:].zfill(len(plugs[0]))] for b in range(0, 2**len(plugs[0]))]
    stuff = sorted(stuff, key=sum)

    for t in stuff:
        foo = [list(p) for p in plugs]
        for i in range(0, len(t)):
            if t[i] == 1:
                foo = flip(i, foo)

        foo.sort()

        if foo == goal:
            return sum(t)

    return -1

tests = int(sys.stdin.readline())

for i in range(0, tests):
  line = sys.stdin.readline().split()
  N = int(line[0])
  L = int(line[1])

  bits = [list(n) for n in sys.stdin.readline().split()]
  ends = [list(n) for n in sys.stdin.readline().split()]
  ends.sort()

  ans = test(list(bits), ends)

  if ans == -1:
      print "Case #%d: %s" % ((i + 1), "NOT POSSIBLE")
  else:
      print "Case #%d: %d" % ((i + 1), ans)

