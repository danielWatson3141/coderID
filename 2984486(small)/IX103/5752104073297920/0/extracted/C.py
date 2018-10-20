#!/usr/bin/python

import math
import sys
def processCase(case):
   N = int(sys.stdin.readline())
   As = [int(x) for x in sys.stdin.readline().split()]
   
   prob = 0.0

   for idx,a in enumerate(As):
      prob += -N/2.0+math.fabs(idx-a)
   
   #print prob
   
   if prob > math.log(0.5):
      print "Case #%d: GOOD" % (case+1,)
   else:
      print "Case #%d: BAD" % (case+1,)

num = int(sys.stdin.readline())

for case in range(0,num):
    processCase(case)
