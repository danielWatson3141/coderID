import random 

def countFixedPoints(arr):
    c = 0
    for i in range(len(arr)):
        if arr[i] in [i+1, i+2, i+3]:
            c += 1
    return c

t = input()
for i in range(t):
    n = input()
    nums = map(int, raw_input().strip().split(' '))
    if countFixedPoints(nums) > 2:
        print "Case #%d: BAD" % (i + 1)
    else:
        print "Case #%d: GOOD" % (i + 1)
    
