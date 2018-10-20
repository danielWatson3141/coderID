INF = 10*10
def makeFullBinary(A,N,root):
	children = getAdjacent(A,N,root)
	if len(children)==0: # this is a leaf, we are fine
		return 0
	elif len(children)==1: # only one child - we have to remove it
		return deleteSubtree(A,N,children[0])
	elif len(children)==2: # make children full binary
		return makeFullBinary(A,N,children[0]) + makeFullBinary(A,N,children[1])
	else: # hard case - more than 2 children
		ch = 0
		size = dict()
		changes = dict()
		for i in children:
			size[i] = getSize(A,N,i)
			changes[i] = makeFullBinary(A,N,i)
		#print(size)
		while len(children)>2:
			#print(children)
			candidate = children[0]
			for i in children:
				if size[i]<changes[candidate]:
					candidate = i
			ch+=size[candidate]
			children.remove(candidate)
		return ch + changes[children[0]]+changes[children[1]]

def getSize(A,N,root):
	adj = getAdjacent(A,N,root)
	size = 1
	for i in adj:
		size+=getSize(A,N,i)
	return size

def deleteSubtree(A,N,root):
	ch = 1
	adj = getAdjacent(A,N,root)
	for i in adj:
		ch+=deleteSubtree(A,N,i)
	return ch

#makes edges one way
def traverse(A,N,root):
	adj =  getAdjacent(A,N,root)
	for i in adj:
		A[i][root] = False
		traverse(A,N,i)

def getAdjacent(A,N,root):
	adj = []
	for i in range(N):
		if (A[root][i]):
			adj.append(i)
	return adj

for T in range(int(input())):
	N = int(input())
	A = [[False]*N for i in range(N)]
	for i in range(N-1):
		X,Y = map(int,input().split())
		A[X-1][Y-1] = True
		A[Y-1][X-1] = True
	minimum = INF
	for i in range(N):
		B = [[False]*N for i in range(N)]
		for a in range(N):
			for b in range(N):
				B[a][b]=A[a][b]
		traverse(B,N,i)
		ch = makeFullBinary(B,N,i)
		if ch<minimum:
			minimum = ch
	print ("Case #"+str(T+1)+": "+str(minimum))
	
