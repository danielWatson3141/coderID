import copy

def getNodesInSubtree(adj,node,parent):
  nodes=[]
  curnode = node
  children = copy.copy(adj[node])
  children.remove(parent)
  nodes.extend(children)

  for child in children:
    nodes.extend(getNodesInSubtree(adj,child,curnode))
  return list(set(nodes))


def getDeleteNum(adj,root,cur,parent):
  children = copy.copy(adj[cur])
  if parent in children:
    children.remove(parent)
  if children==[]:
    return 0
  elif len(children)==1:
    return len(getNodesInSubtree(adj,cur,parent))
  else:
    s=0
    for child in children:
      s+=getDeleteNum(adj,root,child,cur)
    return s

def getMinDeleteNum(adj,deg2Nodes):
  l=[]
  for node in deg2Nodes:
    l.append(getDeleteNum(adj,node,node,None))
  if l:
    return min(l)
  else:
    return 0

f=open("B-small-attempt3.in",'r')
lines=f.readlines()
lines=lines[1:]
f.close()
i=0
casen=1
while i<len(lines):
  n=int(lines[i].strip("\n"))
  adj={}
  deg2={}
  #print n
  for j in range((n-1)):
    #print j
    #print (lines[i+1+j].strip("\n")).split()

    num1,num2 = (lines[i+1+j].strip("\n")).split()
    if num1 not in adj:
      adj[num1]=[num2]
    else:
      adj[num1].append(num2)
    if num2 not in adj:  
      adj[num2]=[num1]
    else:
      adj[num2].append(num1)

    if num1 not in deg2:
      deg2[num1]=1
    else:
      deg2[num1]+=1
    if num2 not in deg2:
      deg2[num2]=1
    else:
      deg2[num2]+=1
  deg2list=[]
  for x in deg2.keys():  
    if deg2[x]==2:
      deg2list.append(x)
  #print adj
  #print deg2list
  ans=getMinDeleteNum(adj,deg2list)
  if n==2:
    print "Case #"+str(casen)+": "+str(1)
  else:
    print "Case #"+str(casen)+": "+str(ans)
  casen+=1
  i+=n




