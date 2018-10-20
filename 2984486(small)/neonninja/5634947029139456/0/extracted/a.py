def match(jacks, devs):
  for i in range(len(devs)):
    if devs[i] not in jacks:
      return False
  return True
  
def flip(jacks, mask):
  jacks = list(init)
  for i in range(len(jacks)):
    jacks[i] = jacks[i] ^ mask
  return jacks
  
def print_b(list):
  for i in range(len(list)):
    print '{:02b}'.format(list[i]),
  print
  
def solve(init, devs, L):
  solutions = list()
  for t in range(1<<L):
    jacks = flip(init,t)
    m = match(jacks,devs)
    if m:
      solutions.append(bin(t).count("1"))
  if not solutions:
    return "NOT POSSIBLE"
  else:
    return min(solutions)
  
cases = int(raw_input())+1
for case in range(1,cases):
  line1 = raw_input().split()
  N = int(line1[0])
  L = int(line1[1])
  init = [int(s, 2) for s in raw_input().split()]
  devs = [int(s, 2) for s in raw_input().split()]
  
  y = solve(init, devs, L)
  if y==-1:
    y = "NOT POSSIBLE"
  print "Case #%s: %s" % (case, y)
