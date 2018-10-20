from copy import deepcopy as copy

infile=file('B-small-attempt0.in','rb+'); outfile=file('B-small-attempt0.out','wb+')

def solve(N,G):
 connectedto=dict([(n,[]) for n in range(1,N+1)])
 for edge in G: connectedto[edge[0]].append(edge[1]); connectedto[edge[1]].append(edge[0])
 #print connectedto
 solution=N
 for root in range(1,N+1):
  children=dict([(n,[]) for n in range(1,N+1)])
  level=dict([(n,N+1) for n in range(1,N+1)]); level[root]=0
  behind=[root]; level[root]=0
  for node in behind:
   children[node]=list(set(connectedto[node])-set(behind)); behind+=children[node]
   for child in children[node]: level[child]=level[node]+1
  k=sorted(range(1,N+1),key=lambda node: level[node],reverse=True)
  worth=dict([(n,1) for n in range(1,N+1)])
  for node in k:
   if len(children[node]) in [0,2]: worth[node]=len(children[node])+1; continue
   if len(children[node])==1: children[node]=[]; worth[node]=1
   if len(children[node])>2:
    while len(children[node])>2:
     nodetoremove=min(children[node],key=lambda node: worth[node])
     children[node].remove(nodetoremove)
    worth[node]=3
  connectedfromroot=[root]
  for node in connectedfromroot: connectedfromroot+=children[node]
  if N-len(connectedfromroot)<solution: solution=N-len(connectedfromroot)
 return solution

for casen in range(1,int(infile.readline())+1):
 nodes=int(infile.readline().strip())
 edges=[infile.readline().strip().split() for x in range(nodes-1)]
 edges=[(int(a),int(b)) for a,b in edges]
 outfile.write('Case #%i: %i\r\n'%(casen,solve(nodes,edges)))