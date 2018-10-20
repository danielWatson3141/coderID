#!/usr/bin/env python
#coding=utf-8
import copy

##inPath = 'test.in'
##outPath = 'test.out'
inPath = 'A-small-attempt1.in'
outPath = "A-small-attempt1.out"
##inPath = 'A-large.in'
##outPath = "A-large.out"

SWITCH = 0
LEN = 0

def flip(flow, device, s):
##    ss = step + 1
    global SWITCH
##    print 'k', ss
    if len(s) == LEN:
        return
    s1 = s + '0'
    s2 = s + '1'
    sn1 = int(s1, 2)
    sn2 = int(s2, 2)
    cur_f1 = copy.deepcopy(flow)
    cur_f2 = copy.deepcopy(flow)
    cur_f1 = [i ^ sn1 for i in cur_f1]
    cur_f2 = [i ^ sn2 for i in cur_f2]
    cur_f1.sort()
    cur_f2.sort()
    ss1 = s1.count('1')
    ss2 = s2.count('1')
    if cur_f1 == device and ss1 < SWITCH:
        SWITCH = ss1
    if cur_f2 == device and ss2 < SWITCH:
        SWITCH = ss2     
    flip(flow, device, s1)
    flip(flow, device, s2)    

def tryf(flow, device):
    global SWITCH
    flow.sort()
    device.sort()
    if flow == device:
        SWITCH = 0
        return
    flip(flow, device, '')

with open(outPath,'w') as outf:
    with open(inPath) as inf:
        n = int(inf.readline().strip())
        for case in xrange(1, n+1):
##            print case
            a, b = inf.readline().strip().split()
            LEN = int(b)
            flow = [int(i, 2) for i in inf.readline().strip().split()]
            device = [int(i, 2) for i in inf.readline().strip().split()]
            SWITCH = LEN + 1
            tryf(flow, device)

            if SWITCH == LEN + 1:
                outf.write("Case #" + str(case) + ": NOT POSSIBLE\n") 
            else:
                outf.write("Case #" + str(case) + ": " + str(SWITCH) + '\n')
    inf.close()
outf.close()
