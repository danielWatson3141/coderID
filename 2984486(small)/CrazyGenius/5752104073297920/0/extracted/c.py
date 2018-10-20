def count_inv(x):
	ret = 0
	for i in range(len(x)):
		for j in range(i+1,len(x)):
			if(x[j] < x[i]):
				ret += 1
	return ret

cc = int(raw_input().strip())

for ccc in range(1,cc+1):
	print 'Case #' + str(ccc) + ':',
	N = int(raw_input().strip())
	inp = raw_input().strip().split()
	for i in range(len(inp)):
		inp[i] = int(inp[i])
	x = range(N)
	ham = count_inv(inp)
	if(ham >= N*N*0.245 and ham <= N*N*0.745):
		print 'GOOD'
	else:
		print 'BAD'
