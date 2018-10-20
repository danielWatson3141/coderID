import random

T = int(raw_input())

for t in xrange(T):
    N = int(raw_input())
    nums = map(int, raw_input().split())

    points = 0

    for i in xrange(N-1):
        if nums[i] != 0 and abs(nums[i]-i)<50:
            points += 1

    print 'Case #%d: %s' % (t+1, 'GOOD' if points<100 else 'BAD')
        
