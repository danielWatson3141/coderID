inf = open("A-small-attempt1.in")
of = open("output.txt",'w')
t = int(inf.readline())
for k in range(t):
	n, l = inf.readline().split(' ')
	n = int(n)
	l = int(l)
	olef = inf.readline().strip('\n').split(' ')
	rqef = inf.readline().strip('\n').split(' ')
	f = False
	minopt = l
	for i in range(n):
		for j in range(n):
			checkd = olef[i]
			optn = 0
			for d in range(l):
				if olef[i][d] == rqef[j][d]: 
					checkd = checkd[0:d] + '0' + checkd[d+1:]
				else:
					checkd = checkd[0:d] + '1' + checkd[d+1:]
					optn += 1
			efset = set()
			for x in range(n):
				changed = olef[x]
				for d in range(l):
					if checkd[d] == '0':
						changed = changed[0:d] + olef[x][d] + changed[d+1:]
					else:
						if olef[x][d] == '1':
							changed = changed[0:d] + '0'+ changed[d+1:]
						else:
							changed = changed[0:d] + '1' + changed[d+1:]
				efset.add(changed)
			flag = True
			for x in range(n):
				if rqef[x] in efset:
					efset.remove(rqef[x])
				else:
					flag = False
					break
			if flag:
				if optn < minopt:
					minopt = optn
				f = True
	if f == False:
		of.write(str("Case #%d: NOT POSSIBLE\n") % (k+1))
		print str("Case #%d: NOT POSSIBLE") % (k+1)
	else:
		of.write(str("Case #%d: %d\n") % (k+1, minopt))
		print str("Case #%d: %d") % (k+1, minopt)
of.close()



