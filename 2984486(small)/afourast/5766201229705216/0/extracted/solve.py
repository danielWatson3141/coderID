import sys
#~ sys.setrecursionlimit(10)
from itertools import combinations

def getChildren(tree,r,prev):

  childs = set()
  
  for e in tree:
    
    if e[0]==r:
      childs.add(e[1])
    elif e[1] == r:
      childs.add(e[0])
  
  if len(childs)==0:
    return 0
  
  if prev in childs:
    childs.remove(prev)
    
  return childs

def parse(tree,r,prev):
  
  childs = getChildren(tree,r,prev)
  
  s = 1
  for c in childs:
    s+= parse(tree,c,r)
  
  return s

def getChildrenSum(tree,r,prev):
  return parse(tree,r,prev) 

def pruneTree(tree,r,prev):
  
  childs = list(getChildren(tree,r,prev))
  
  nmg = [ getChildrenSum(tree,c,r) for c in childs ]
  
  assert(len(nmg)==len(childs))
  
  #~ sortedIds = sorted(range(len(nmg)), key=lambda k: -nmg[k])
  #~ nmg.sort()
  
  #~ print r , prev 
  #~ print zip(childs,nmg)
  
  if len(nmg) >=2:
    
    mins = float('inf')
    
    for p in combinations(range(len(nmg)),2):
      #~ print p
      allSum = sum(nmg)
      allSum-= nmg[p[0]]
      allSum-= nmg[p[1]]
    
      new = allSum + pruneTree(tree,childs[p[0]],r) + pruneTree(tree,childs[p[1]],r)
      
      if new < mins:
        mins = new
    
    return mins
      
  elif len(nmg) ==1:
    return nmg[0]
  else:
    return 0
    

def solve(N,tree):
  
  
  #~ print tree
  
  mins = float('inf')
  
  for r in range(N):
    new = pruneTree(tree,r,None)
    
    #~ print 'Root = %d , best = %d' %(r,new) 
    #~ print 
    
    if new < mins:
      mins = new
    
  return mins

T = int(raw_input());

for case in range(T):
  
  N = int(raw_input());

  tree = []

  for i in range(N-1):
    
    edge = map( lambda x : x-1 , map(int,raw_input().split()) )
    tree.append(edge)
  
  sol = str(solve(N,tree))
  
  print 'Case #%d: %s' %(case+1,sol)
    

