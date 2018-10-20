#!/usr/bin/python

import sys
import scipy as sp

IMPOSSIBLE = 999999
L  = 0 
def test(flows,required):
   for req in required:
      matched = False
      for flow in flows:
         #print "{0:b},{1:b}".format(flow,req)
         if req ^ flow == 0:
            matched = True
            break
      if not matched:
         return False
   return True

def testSwitch(flows,required,startidx,minval):
   for idx in range(startidx,L):
      #toggle switch idx
      #print "throw switch " +str(idx)
      tmpflows = list(flows)
      for fidx,flow in enumerate(tmpflows):
         tmpflows[fidx] = flow ^ (1 << idx)
      if test(tmpflows,required):
         return 1
      tmpval = testSwitch(tmpflows,required,idx+1,minval-1)
      if tmpval < minval:
         minval = tmpval+1
   return minval

#branch and bound
def solve(flows,required):
   numswitch = -1
   
   if test(flows,required):
      return 0
   
   return testSwitch(flows,required,0,IMPOSSIBLE)

def processCase(case):
   global L
   N,L = [int(x) for x in sys.stdin.readline().split()]
   flows = [ int(x,2) for x in sys.stdin.readline().split()]
   required = [int(x,2) for x in sys.stdin.readline().split()]
   
   numswitch = solve(flows,required)
   
   if numswitch < IMPOSSIBLE:
      print "Case #%d: %d" % (case+1,numswitch)
   else:
      print "Case #%d: NOT POSSIBLE" % (case+1,)

num = int(sys.stdin.readline())

for case in range(0,num):
    processCase(case)
