#!/usr/bin/python

import sys
numcases=int(sys.stdin.readline())
for j in range(numcases):
  lin=sys.stdin.readline().split()
  n=int(lin[0])
  l=int(lin[1])
  flows=sys.stdin.readline().split()
  reqs=sys.stdin.readline().split()
  reqs.sort()
  best=9999
  for match0 in range(n):
    #match device 0 with outlet n
    flips=[]
    for bit in range(l):
      if reqs[0][bit]==flows[match0][bit]:
        flips.append(0)
      else:
        flips.append(1)
    numflips=sum(flips)
    if numflips<best:
      #generate all flipped flows
      ff=[]
      for flow in flows:
        s=""
        for bit in range(l):
          if flips[bit]==0:
            s+=flow[bit]
          elif flow[bit]=="0":
            s+="1"
          else:
            s+="0"
        ff.append(s)
      ff.sort()
      if ff==reqs:
        #solution
        best=numflips
  #print result
  sys.stdout.write("Case #"+repr(j+1)+": ")
  if best==9999:
    sys.stdout.write("NOT POSSIBLE\n")
  else:
    sys.stdout.write(repr(best)+"\n")
