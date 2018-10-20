#!/bin/python
import sys




def readin(infile):
  print >> sys.stderr, "reading from " + infile
  lines=open(infile, 'r').readlines()
  testcount = int(lines[0])
  print >> sys.stderr, "read %d test cases from %d lines"%(testcount, len(lines))
  lines=lines[1:]
  return testcount, lines

def doall(testcases, lines):
  case = 1

  while lines:
    nl = lines[0]
    nl=nl.split()
    n,l=int(nl[0]), int(nl[1])
    data = [int(na,2) for na in lines[1].split()]
    data2 = [int(na,2) for na in lines[2].split()]
    lines=lines[3:]

    solve(case,n,l,data,data2)
    case+=1

def solve(case,n,l,flows,devs):
#  print n,l,flows,devs
  print 'Case #%d:'%case,
  ans={}
  for f in flows:
    for d in devs:
      sw=f^d
      if sw in ans:
        ans[sw]+=1
      else:
        ans[sw]=1

  b=None
  for a,v in ans.iteritems(): 
    if v < n:
      continue
    d=bin(a).count('1')
    if b==None or d<b[1]:
      b=a,d
  

  if b==None:
    print 'NOT POSSIBLE'
  else:
    print b[1]


if __name__ == '__main__': 
  if len(sys.argv) != 2:
    print >> sys.stderr, "bad args"
    sys.exit(1)
  tc, l = readin(sys.argv[1])
  doall(tc, l)
  print >> sys.stderr, "done"

