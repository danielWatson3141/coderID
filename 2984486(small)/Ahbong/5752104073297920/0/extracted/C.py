def permuted(nums):
  return sum(p[0] != p[1] for p in enumerate(nums))

T = int(input())

for t in range(1, T + 1):
  N = int(input())
  nums = list(map(int, input().split()))
  print("Case #{}: {}".format(t,
        "BAD" if permuted(nums) < N - 1 else "GOOD"))

