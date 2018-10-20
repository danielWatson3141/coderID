num_cases = int(raw_input())

for case in range(num_cases):
    n = int(raw_input())
    nums = [int(i) for i in raw_input().split(" ")]
    left = 0
    for i in range(len(nums)):
        num = nums[i]
        if num >= i:
            pass
        else:
            left += 1
    if left > n / 2.0 + 1:
        print("Case #{}: BAD".format(case+1))
    else:
        print("Case #{}: GOOD".format(case+1))