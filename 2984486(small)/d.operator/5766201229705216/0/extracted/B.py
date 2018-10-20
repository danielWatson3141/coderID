def subtree_kr_cost(L, deg, i, parent):
	if(deg[i]==1): #leaf node
		return (0,1)
	else:
		child_kr = []
		for nbr in L[i]:
			if(nbr!=parent):
				child_kr.append(subtree_kr_cost(L, deg, nbr, i))
		child_kr.sort(key = lambda x: x[1]-x[0])
		if(len(child_kr)>=2):
			keepfactor = (child_kr[-1][1]-child_kr[-1][0]) + (child_kr[-2][1]-child_kr[-2][0])
		else:
			keepfactor = 0
		remtot = 0
		for val in child_kr:
			remtot += val[1]
		if(keepfactor > 0):	
			return (remtot-keepfactor, remtot+1)
		else:
			return (remtot, remtot+1)			

def solve_case(L):
	N = len(L)
	deg = map(len, L)
	smallest_remove = -1
	for root in xrange(N):
		if(deg[root]>=2):
			rem_tuple = subtree_kr_cost(L, deg, root, -1)
			rem = rem_tuple[0]
			if(smallest_remove==-1 or rem<smallest_remove):
				smallest_remove = rem
	return smallest_remove

def solve(in_name, out_name):
	fin = open(in_name, 'r');
	L = [map(int, x.strip().split()) for x in fin.readlines()]
	fin.close()
	T = L[0][0]

	k = 1
	res = []
	for casenr in xrange(T):
		N = L[k][0]
		k+=1
		adjlst = [[] for i in xrange(N)]
		for j in xrange(N-1):
			[X,Y] = L[k]
			k+=1
			adjlst[X-1].append(Y-1)
			adjlst[Y-1].append(X-1)
		for j in xrange(N-1):
			adjlst[j].sort()
		res.append('Case #' + str(casenr+1) + ': ' + str(solve_case(adjlst)) + '\n');
		
	
	fout = open(out_name, 'w')
	fout.writelines(res)
	fout.close()
	
	return
	
solve('B-small-attempt0.in', 'B-small-attempt0.out')
#solve('B-large.in', 'B-large.out')

#solve('B-test.in', 'B-test.out')
