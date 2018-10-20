t = int(raw_input())

def possible(flow, req, n, digit, history):
  flow_ones = [x for x in flow if x[digit] == '1']
  flow_zeroes = [x for x in flow if x[digit] == '0']
  req_ones = [x for x in req if x[digit] == '1']
  req_zeroes = [x for x in req if x[digit] == '0']

  pos = []

  switch = False
  if len(flow_ones) == len(req_ones):
    pos.append([(flow_ones, req_ones), (flow_zeroes, req_zeroes)])
    switch = False

  if len(flow_ones) == len(req_zeroes):
    pos.append([(flow_ones, req_zeroes), (flow_zeroes, req_ones)])  
    switch = True   

  return (switch, pos)

def solve(flow, req, n, l):
  todo = [("", [(flow, req)])]

  for digit in xrange(l):
    new_todo = []

    for (hist, xs) in todo:
      switch_possible = True
      noswitch_possible = True
      todo_switch = []
      todo_noswitch = []

      for (f, r) in xs:

        switch, pos = possible(f, r, n, digit, hist)
        if len(pos) == 0:
          switch_possible = False
          noswitch_possible = False

        elif len(pos) == 1:
          if switch:
            noswitch_possible = False
            todo_switch = todo_switch + pos[0]

          elif not switch:
            switch_possible = False
            todo_noswitch = todo_noswitch + pos[0]

        else:
          if noswitch_possible:
            todo_noswitch = todo_noswitch + pos[0]
          if switch_possible:
            todo_switch = todo_switch + pos[1]

        if not switch_possible and not noswitch_possible:
          break

      if switch_possible:
        new_todo.append((hist + "1", todo_switch))
      if noswitch_possible:
        new_todo.append((hist + "0", todo_noswitch))
    todo = new_todo

  ans = l + 1
  for (h, xs) in todo:
    count = 0
    for c in h:
      if c == "1":
        count += 1
    if count < ans:
      ans = count

  return ans

for i in xrange(t):
  n, l = map(int, raw_input().split(" "))
  flow = raw_input().split(" ")
  req = raw_input().split(" ")
  ans = solve(flow, req, n, l)
  if ans > l:
    ans = "NOT POSSIBLE"
  print "Case #" + str(i + 1) + ":", ans










