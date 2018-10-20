NNN = int(raw_input())
for nnn in xrange(1, NNN+1):
  print "Case #%d:" % (nnn),
  N, L = [int(x) for x in raw_input().split()]
  outlets = sorted(raw_input().split())
  devices = sorted(raw_input().split())
  l_o, l_d = [], []
  for i in xrange(N):
    l_o.append([x for x in outlets[i]])
    l_d.append([x for x in devices[i]])

  def f(o, d, s):
    if len(o[0]) == 0:
      return 0

    s_a = [0]
    for i in xrange(len(s)-1):
      o[s[i]:s[i+1]] = sorted(o[s[i]:s[i+1]])
      d[s[i]:s[i+1]] = sorted(d[s[i]:s[i+1]])
      for j in xrange(s[i], s[i+1]):
        if d[j][0] == '1':
          if j != s[i]: s_a.append(j)
          break
      if s_a[-1] != s[i+1]:
        s_a.append(s[i+1])
    d_a = [x[1:] for x in d]
    matched = 1
    for i in xrange(len(o)):
      if o[i][0] != d[i][0]:
        matched = 0
        break
    if matched:
      o_a = [x[1:] for x in o]
    f1 = f(o_a, d_a, s_a) if matched else None

    for i in xrange(len(o)):
      o[i][0] = '1' if o[i][0]=='0' else '0'
    for i in xrange(len(s)-1):
      o[s[i]:s[i+1]] = sorted(o[s[i]:s[i+1]])
    matched = 1
    for i in xrange(len(o)):
      if o[i][0] != d[i][0]:
        matched = 0
        break
    if matched:
      o_a = [x[1:] for x in o]
    f2 = f(o_a, d_a, s_a) if matched else None

    if f1 == None and f2 == None:
      return None
    elif f1 != None and f2 != None:
      return min(f1, f2+1)
    elif f1 != None:
      return f1
    else:
      return f2+1

  s = [0, N]
  ans = f(l_o, l_d, s)
  if ans == None:
    print "NOT POSSIBLE"
  else:
    print ans

