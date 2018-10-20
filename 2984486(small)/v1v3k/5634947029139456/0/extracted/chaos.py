
def popcnt(x):
    setbits = 0
    while x > 0:
        setbits += x & 1
        x = (x >> 1)
    return setbits

def solve(i):
    n, l = map(int, raw_input().split())
    outlets = raw_input().strip().split()
    devices = sorted([int(num, 2) for num in raw_input().strip().split()])

    ans = l+1

    for x in xrange((1<<l)):
        nums = [int(num, 2) for num in outlets]
        new_nums = [num ^ x for num in nums]
        new_nums.sort()
        if (new_nums == devices):
            ans = min(ans, popcnt(x))

    if ans <= l:
        print "Case #%d: %d" % (i, ans)
    else:
        print "Case #%d: NOT POSSIBLE" % i

T = input()

for i in xrange(1, T+1):
    solve(i)
