def countone(x):
	tmp = "{0:b}".format(x)
	ret = 0
	for i in tmp:
		ret += int(i)
	return ret

cc = int(raw_input().strip())

for ccc in range(1,cc+1):
	print 'Case #' + str(ccc) + ':',
	N,L = raw_input().strip().split()
	N = int(N)
	L = int(L)
	outlet = []
	device = []
	tmp_ol = raw_input().strip().split()
	tmp_dv = raw_input().strip().split()
	for i in tmp_ol:
		outlet.append(int(i,2))
	for i in tmp_dv:
		device.append(int(i,2))

	x = device[0]
	ans = L+1
	for ol in outlet:
		hamming = x ^ ol
		tmp_outlet = []
		for i in outlet:
			tmp_outlet.append(i^hamming)
		can = True
		for dv in device:
			if(dv not in tmp_outlet):
				can = False
				break
			tmp_outlet.remove(dv)
		if(can):
			ans = min(ans,countone(hamming))
	if(ans == L+1):
		print 'NOT POSSIBLE'
	else:
		print ans		
