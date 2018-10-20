def penalty(n, p):
    if p > n:
        penalty = 1.0 * (p - n - 1) / (p - n)
    else:
        penalty = 1.0 * (n - p) / (n + 1)
    return penalty

def verdict(nums):
    N = len(nums)
    s = 0.0
    for p in range(N):
        s += penalty(nums[p], p)
    s = s / N
    if s > 0.73:
        return 'GOOD'
    else:
        return 'BAD'

def do_case(case_num, nums):
    print "Case #%d: %s" % (case_num, verdict(nums)) 

def main():
    T = int(raw_input())
    for case_num in range(1, T + 1):
        raw_input()
        nums = map(int, raw_input().split())
        do_case(case_num, nums)

if __name__ == "__main__":
    main()
