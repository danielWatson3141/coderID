#!/usr/bin/env python
#coding=utf-8
import copy

##inPath = 'test.in'
##outPath = 'test.out'
inPath = 'C-small-attempt1.in'
outPath = "C-small-attempt1.out"


FLAG = True
nNum = 0

def judge(nums):
    global FLAG
    FLAG = True
    nTag = [0] * nNum
    count = 0
    for i in range(nNum):
        nTag[nums[i]] = 1
        count += i - nTag[:nums[i]].count(1)
    return count
##        if nums[i] == i:
##            FLAG = False
##            return
##        else:
##            nums[nums.index(i)] = nums[i]
##            nums[i] = i
####            print nums

with open(outPath,'w') as outf:
    with open(inPath) as inf:
        n = int(inf.readline().strip())
        for case in xrange(1, n+1):
            print case
            nNum = int(inf.readline().strip())
            nums = [int(i) for i in inf.readline().strip().split()]
            c = judge(nums)
##            print c, (
            if c >=  (1 + nNum - 1) * (nNum - 1) / 4:
                outf.write("Case #" + str(case) + ": GOOD\n") 
            else:
                outf.write("Case #" + str(case) + ": BAD\n")
    inf.close()
outf.close()
