#!/usr/bin/env python3

import sys, math

def simple_compare(flips, power, outlets):
  noutlets = []
  power = set(power)
  for outlet in outlets:
    ans = ''
    for i in range(len(flips)):
      val = outlet[i]
      if flips[i] == '1':
        val = '1' if val == '0' else '0'
      ans += val
    if ans not in power:
      return False
  return True

def compare(flips, power, outlets):
  for outlet in outlets:
    ans = ''
    for i in range(len(flips)):
      val = outlet[i]
      if flips[i] == '1':
        val = '1' if val == '0' else '0'
      ans += val
    if ans not in power:
      return False
  return True

cases = int(sys.stdin.readline())
for case_no in range(1, cases + 1):
  N, L = [int(val) for val in sys.stdin.readline().strip().split()]
  outlets = sys.stdin.readline().strip().split()
  power = sys.stdin.readline().strip().split()

  options = set()
  # Check the base case
  tpower = set([p[0] for p in power])
  toutlets = set([p[0] for p in outlets])
  if len(tpower) != len(toutlets):
    ans = "NOT POSSIBLE"
    print("Case #{}: {}".format(case_no, ans))
    continue
  else:
    if len(tpower) == 2:
      options.add('0')
      options.add('1')
    elif tpower.pop() == toutlets.pop():
      options.add('0')
    else:
      options.add('1')
  
  for i in range(2, L + 1):
    tpower = set([p[:i] for p in power])
    toutlets = set([o[:i] for o in outlets])
    noptions = set()
    for option in options:
      for opt in ['0', '1']:
        noption = option + opt
        if compare(noption, tpower, toutlets):
          noptions.add(noption)
    options = noptions
    if len(options) == 0:
      break
  ans = "NOT POSSIBLE"
  for option in options:
    count = sum([int(i) for i in option])
    if ans == "NOT POSSIBLE" or count < ans:
      flips = option
###      if not compare(flips, power, outlets):
###        print("Uhoh")
      ans = count
  print("Case #{}: {}".format(case_no, ans))
