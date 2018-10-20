import sys
sys.setrecursionlimit(10000)

S = []
C = []

def treeSize(tree, root, parent):
	global S
	res = 1
	for i in tree[root]:
		if i != parent:
			if S[i][root] == -1: 
				S[i][root] = treeSize(tree, i, root)
			res += S[i][root]
	return res

def sizeT(tree, N):
	global S
	for i in range(N):
		S[i][i] = N
	for i in range(N):
		if len(tree[i]) == 1:
			S[i][tree[i][0]] = 1
	for i in range(N):
		for j in range(N):
			if S[i][j] == -1 and j in tree[i]:
				S[i][j] = treeSize(tree, i, j)



def cost(tree, root, parent):
	global S
	global C
	if parent == -1:
		l = len(tree[root])
		if l == 1:
			return S[tree[root][0]][root]
		elif l == 2:
			if C[tree[root][0]][root] == -1:
				C[tree[root][0]][root] = cost(tree, tree[root][0], root)
			if C[tree[root][1]][root] == -1:
				C[tree[root][1]][root] = cost(tree, tree[root][1], root)
			return C[tree[root][0]][root] + C[tree[root][1]][root]
		else:
			minCost = 10000
			myCost = []
			mySize = []
			for i in tree[root]:
				myCost.append(C[i][root])
				mySize.append(S[i][root])
			for i in range(len(tree[root])):
				for j in range(len(tree[root])):
					if j>i:
						res = myCost[i] + myCost[j]
						for k in range(len(tree[root])):
							if k != i and k != j:
								res += mySize[k]
						if res < minCost:
							minCost = res
			return minCost
	else:
		l = len(tree[root])
		if l == 1:
			return 0
		elif l == 2:
			for i in tree[root]:
				if i != parent:
					return S[i][root]
			return -1
		elif l == 3:
			res = 0
			for i in tree[root]:
				if i != parent:
					if C[i][root] == -1:
						C[i][root] = cost(tree, i, root)
					res += C[i][root]
			return res
		else:
			minCost = 10000
			myCost = []
			mySize = []
			for i in tree[root]:
				if i != parent:
					if C[i][root] == -1:
						C[i][root] = cost(tree, i, root)
					myCost.append(C[i][root])
					mySize.append(S[i][root])
				else:
					myCost.append(0)
					mySize.append(0)
			for i in range(len(tree[root])):
				for j in range(len(tree[root])):
					if tree[root][i] != parent and tree[root][j] != parent and j>i:
						res = myCost[i] + myCost[j]
						for k in range(len(tree[root])):
							if tree[root][k] != parent and k != i and k != j:
								res += mySize[k]
						if res < minCost:
							minCost = res
			return minCost

def costT(tree, N):
	global S
	global C
	for i in range(N):
		if len(tree[i]) == 1:
			C[i][tree[i][0]] = 0
	for i in range(N):
		for j in range(N):
			if i!= j and C[i][j] == -1 and j in tree[i]:
				C[i][j] = cost(tree, i, j)
	for i in range(N):
		C[i][i] = cost(tree, i, -1)


def solve():
	global S, C
	#f = open("in.txt", 'r')
	f = open("B-small-attempt3.in.txt", 'r')
	T = int(f.readline())
	for t in range(T):
		N = int(f.readline())
		S = [[-1 for j in range(N)] for i in range(N)]
		C = [[-1 for j in range(N)] for i in range(N)]
		tree = [[] for i in range(N)]
		for i in range(N-1):
			[a, b] = [int(k) for k in f.readline().split()]
			tree[a-1].append(b-1)
			tree[b-1].append(a-1)
		sizeT(tree, N)
		costT(tree, N)
		#print S
		#print C
		minCost = N
		for i in range(N):
			c = C[i][i]
			if c < minCost:
				#print i 
				minCost = c
		print "Case #%i:" % (t+1), minCost
		#print treeSize(tree, 1, -1)



solve()