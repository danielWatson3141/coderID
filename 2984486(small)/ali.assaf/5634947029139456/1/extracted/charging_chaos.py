#!/usr/bin/env python3

import sys

def is_solution(outlets, devices, switches):
  return set(outlet ^ switches for outlet in outlets) == set(devices)

def solve(problem):
#  print(*problem, file=sys.stderr)
  N, L, outlets, devices = problem
  best = None
  outlet = outlets[0]
  for device in devices:
    switches = outlet ^ device
    if is_solution(outlets, devices, switches):
      size = bin(switches).count("1")
      if best is None or best > size:
        best = size
  if best is not None:
    return best
  return "NOT POSSIBLE"

def read():
  N, L = map(int, input().split())
  outlets = [int(s, 2) for s in input().split()]
  devices = [int(s, 2) for s in input().split()]
  assert len(outlets) == N
  assert len(devices) == N
  return N, L, outlets, devices

def write(i, solution):
  print("Case #%d: %s" % (i + 1, solution))

def main():
  cases = int(input())
  for i in range(cases):
    problem = read()
    solution = solve(problem)
    write(i, solution)

if __name__ == "__main__":
  main()

