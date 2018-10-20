#!/usr/bin/env python

"""
  Problem : 
  Code by : AdamJB
  Info    : 
"""

import math

INF = 2**10

def solveCase(case, N, L, init, req):
  minFlips = INF

  maskValue = 2**L - 1 

  initAsNum = []
  reqAsNum = []
  for i in init:
    initAsNum.append(int(i, 2))
  for r in req:
    reqAsNum.append(int(r, 2))

  sInit = sorted(initAsNum)
  sReq = sorted(reqAsNum)

  if sInit == sReq:
    minFlips = 0
  else:
    for x in range(1, 1024):
      modInit = []
      for i in sInit:
        newVal = (i ^ x) & maskValue
        modInit.append(newVal)
      if (sorted(modInit) == sReq):
        curFlips = bin(x).count("1")
        if curFlips <= minFlips:          
          minFlips = curFlips          

      #print sReq
      #print modInit

  if minFlips == INF:
    print("Case #%d: %s" % (case, "NOT POSSIBLE"))
  else:
    print("Case #%d: %s" % (case, str(minFlips)))


def main():
  T = int(raw_input())
 
  for case in range(1, T+1):
    (N, L) = (int(i) for i in raw_input().strip().split())
    init = [str(i) for i in raw_input().strip().split()]    
    req = [str(i) for i in raw_input().strip().split()]      
    solveCase(case, N, L, init, req)
  
main()

