def maxtree(i,alst,parent):
	#print i, parent
	l = len(alst[i])
	if parent != None:
		l -= 1
	if l < 2:
		return 1
	mtc1 = 0
	mtc2 = 0
	for v in alst[i]:
		if v != parent:
			mt = maxtree(v,alst,i)
			if mt > mtc1:
				mtc2 = mtc1
				mtc1 = mt
			else:
				if mt > mtc2:
					mtc2 = mt
	return 1 + mtc1 + mtc2

def solve():
	T = int(raw_input())
	Tid = 1
	while Tid <= T:
		N = int(raw_input())
		alst = [[] for i in range(N+1)]
		for i in range(N-1):
			v = raw_input().split()
			v = map(int, v)
			alst[v[0]].append(v[1])
			alst[v[1]].append(v[0])
		#print alst
		mval = 1
		idx = None
		for i,lst in enumerate(alst):
			if i == 0:
				continue
			if len(lst) >= 2:
				mt = maxtree(i,alst, None)
				#print i,mt
				if mt > mval:
					mval = mt
					idx = i
		print "Case #%d: %d" % (Tid, N-mval)
		Tid += 1

if __name__ == "__main__":
	solve()
