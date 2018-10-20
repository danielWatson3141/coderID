f = open("B-small-attempt0.in", "r")
d = f.read()
f.close()

def buildTree(n, es):
	t = [set([]) for k in xrange(n)]
	for e in es:
		t[e[0]].add(e[1])
		t[e[1]].add(e[0])
	return t

def valid(t, n):
	deleted = 0
	vin = [True] * n
	for i in xrange(n):
		if len(t[i]) == 0:
			deleted += 1
			vin[i] = False # deleted
	used = [False] * n
	q = [0]
	i = 0
	used[0] = True
	while i < len(q):
		v = q[i]
		for ad in t[v]:
			if used[ad]: continue
			used[ad] = True
			q.append(ad)
		i += 1
	if used != vin: return False, 0
	#print used, vin
	
	for r in xrange(n):
		if len(t[r]) == 0: continue
		used = [False] * n
		this = True
		q = [r]
		i = 0
		used[r] = True
		while i < len(q):
			v = q[i]
			#print "PROBANDO", v, len(t[v])
			childnot = 0
			for cc in t[v]:
				if not used[cc]: childnot += 1
			if not childnot in [0, 2]:
				this = False
				break
			for ad in t[v]:
				if used[ad]: continue
				used[ad] = True
				q.append(ad)
			i += 1
		if this:
			#print "root", r
			return True, deleted
	return False, 0

def solveEasy(n, es):
	#print "ORIG ", buildTree(n, es)
	minbits = n - 1
	tmin = []
	for i in xrange(2**n - 1):
		t = buildTree(n, es)
		num = i
		#nbits = 0
		#print "SAQUE",
		for ibit in xrange(n):
			bit = num % 2
			#bits.append(bit)
			if bit == 1:
				#print ibit,
				#nbits += 1
				node = ibit
				for v in t[ibit]:
					t[v].remove(ibit)
				t[ibit] = set([])
			num /= 2
		#print ""
		#if i == 0: print "ARBOL", "--", t, ".", valid(t, n), "OOO"
		v = valid(t, n)
		if v[0]:
			#print "SI", t
			nbits = v[1]
			if nbits < minbits:
				minbits = nbits
				tmin = t
	#print "MIN ", tmin
	return minbits
	
	
	return str(t)

d = d.split("\n")[:-1]
T = int(d[0])
d = d[1:]

f = open("b.out", "w")
j = 0
for i in xrange(T):
	n = int(d[j])
	t = [[] for k in xrange(n)]
	es = []
	for k in xrange(j+1, j+n):
		e = d[k].split(" ")
		e = int(e[0])-1, int(e[1])-1
		es.append(e)
	s = "Case #%d: %s" % (i+1, solveEasy(n, es))
	print s
	f.write(s+"\n")
	j += n
f.close()

