T = int(input())
for t in range(1, T + 1):
  N, L = map(int, input().split())
  L1 = list(map(lambda x: int(x, 2), input().split()))
  L1.sort()
  L2 = list(map(lambda x: int(x, 2), input().split()))
  ans = L + 1
  for n in range(N):
    mask = L1[0] ^ L2[n]
    bits = bin(mask).count("1")
    tL2 = list(map(lambda x: x ^ mask, L2))
    tL2.sort()
    if L1 == tL2 and bits < ans:
      ans = bits
  print("Case #{}: {}".format(t, ans if ans <= L else "NOT POSSIBLE"))
