#!/usr/bin/python3
T = int(input())
for t in range(T):
  print('Case #{}: '.format(t + 1), end='')
  N, L = map(int, input().split())
  a = list(map(int, input().split()))
  b = list(sorted(map(int,input().split())))
  #print(list(b))
  result = 999999999
  for i in range(2 ** L):
    new_a = list(sorted([el ^ i for el in a]))
    #print(list(new_a))
    if new_a == b:
      result = min(result, str(i).count('1'))
  if result != 999999999:
    print(result)
  else:
    print('NOT POSSIBLE')


