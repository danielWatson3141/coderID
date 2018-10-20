def xor(a, b) :
	r = ""
	for i in range(len(a)) :
		if a[i] == b[i] :
			r += "0"
		else :
			r += "1"
	return r


T = eval(raw_input())

for i in range(1, T+1) :
	r = raw_input().split()
	N = int(r[0])
	L = int(r[1])
	a = raw_input().split()
	a.sort()
	b = raw_input().split()
	m = 99999
	for j in range(N) :
		x = xor(a[0], b[j])
		
		bb = []
		for k in range(N) :
			bb.append(xor(x, b[k]))
		bb.sort()
		
		check = True
		for k in range(N) :
			if a[k] != bb[k] :
				check = False
				break
		if not check :
		 	continue
		count = 0
		for k in x :
		 	if k == '1' :
		 		count += 1
		if count < m :
		 	m = count
	if m == 99999 :
		print "Case #%d: NOT POSSIBLE" % i
	else :
	  	print "Case #%d: %d" % (i, m)
		




	





