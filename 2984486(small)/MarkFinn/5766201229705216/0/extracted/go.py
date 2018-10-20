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
    n = int(lines[0])
    lines=lines[1:]
    nodes=[tuple()]*n
    for i in xrange(n-1):
      d=lines[0].split()
      x,y=int(d[0])-1,int(d[1])-1
      nodes[x]+=(y,)
      nodes[y]+=(x,)
      lines=lines[1:]
 
    r=solve(nodes)
    print 'Case #%d: %d'%(case,r)
    case+=1


def rec(n,seen,level,dl):
#  print 'rec', seen, level
  level-=seen
  if len(level) == 0:
    return True
  elif len(level) == 1:
    level=list(level)
    dl.add(level[0])
    return True
  seen|=level
  level=list(level)
  best=None
  for i in xrange(1,len(level)):
    for j in xrange(i):
      
      ss=seen.copy()
      dll=dl.copy()
      dlling=set(level)-set([level[i], level[j]])
      if dlling&seen:
        continue
      dll|= dlling
      if not rec(n,ss,set(n[level[i  ]  ]  )  ,dll):
        continue
      if not rec(n,ss,set(n[level[j]]),dll):
        continue
      v=len(n)-len(seen)
      if best==None or v<best[0]:
        best=v,ss
  if best==None:
    return None
  seen|=best[1]
  return True
    
def solve(n):
  if len(n)==1:
    return 0
  b=None
  for r in xrange(len(n)):
    seen=set([r])
    nl=set(n[r])
    dl=set()
    v=rec(n,seen,nl,dl)
    v=len(n)-len(seen)
#    print 'asdf', r, v,seen
    if b==None or v<b:
      b=v
  return b

if __name__ == '__main__': 
  if len(sys.argv) != 2:
    print >> sys.stderr, "bad args"
    sys.exit(1)
  tc, l = readin(sys.argv[1])
  doall(tc, l)
  print >> sys.stderr, "done"

