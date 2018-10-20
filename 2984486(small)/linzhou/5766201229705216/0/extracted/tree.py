from sets import Set
mtx = []

def subtreesize(s,p):
	global mtx
	size = 1
	ar = [s]
	appear = Set(ar)
	while len(ar) > 0:
		t = ar[0]
		ar.remove(t)
		for cd in mtx[t]:
			if (not cd in appear and cd != p):
				ar.append(cd)
				appear.add(cd)
				size += 1
	return size

def getcost(j,p):
	global mtx
	ll = 0
	for cd in mtx[j]:
		if cd != p:
			ll += 1
	if (ll == 0):
		return 0
	if (ll == 1):
		for cd in mtx[j]:
			if (cd != p):
				return subtreesize(cd,j)
	elif (ll == 2):
		tmpcost = 0
		for cd in mtx[j]:
			if (cd != p):
				tmpcost += getcost(cd,j)
		return tmpcost
	else:
		costa = []
		sizea = []
		for k in range(0,len(mtx[j])):
			if (mtx[j][k] != p):
				costa.append(getcost(mtx[j][k],j))
				sizea.append(subtreesize(mtx[j][k],j))
		sizesum = sum(sizea)
		incost = sizesum
		for a in range(0,len(costa)):
			for b in range(a+1,len(costa)):
				tmpcost = costa[a] + costa[b] + sizesum - sizea[a] - sizea[b]
				if tmpcost < incost:
					incost = tmpcost
		return incost		
linearray = []

fp = open('B-small-attempt0.in','r')
for line in fp:
	linearray.append(line.rstrip('\n'))
fp.close()

T = int(linearray[0])
op = open('output.txt','w')
i = 1
case = 0
while i < len(linearray):	
	N = int(linearray[i])
	i += 1

	case += 1
	cost = N

	mtx = []
	for j in range(0,N+1):
		mtx.append([])

	
	for j in range(0,N-1):
		splits = linearray[i].split()
		a = int(splits[0])
		b = int(splits[1])
		mtx[a].append(b)
		mtx[b].append(a)
		i += 1

	for j in range(1,N+1):
		tmpcost = getcost(j,-1)
		if (tmpcost < cost):
			cost = tmpcost

	op.write("Case #%s: %s\n" % (case,cost))
op.close()