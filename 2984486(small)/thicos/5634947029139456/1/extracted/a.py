T = int(raw_input())

def text_xnor(a, b):
	c = ""
	num = 0
	for i in range(len(a)):
		if a[i] == b[i]:
			c += "0"
		else:
			c += "1"
			num+=1
	return (num,c)

def text_xor(a, b):
	c = ""
	for i in range(len(a)):
		if a[i] == b[i]:
			c += "0"
		else:
			c += "1"
	return c

	
for t in range(T):
	inp = raw_input().split()
	N = int(inp[0])
	L = int(inp[1])
	flow = raw_input().split()
	need = raw_input().split()
	flips = set()
	
	res = -1
	for i in flow:
		for j in need:
			flips.add(text_xnor(i, j))
	flips = list(flips)
	flips.sort()
	mat = [[0 for i in range(2*N+2)] for i in range(2*N+2)]
	for f in flips:
		needf = set()
		num = N+1
		for i in need:
			r = text_xor(i,f[1])
			needf.add(r)
		flag = True
		for i in flow:
			if i not in needf:
				flag = False
				break
		if flag:
			res = f[0]
			break
	if (res < 0): print "Case #%d: NOT POSSIBLE"%(t+1)
	else: print "Case #%d: %d"%(t+1,res)
			
	
