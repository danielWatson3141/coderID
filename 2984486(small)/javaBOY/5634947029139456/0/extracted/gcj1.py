file=open('in.in')
n=int(file.readline())
for i in range(0,n):
	a=file.readline()
	b=file.readline()[:-1].split()
	b1=[]
	for item in b:
		b1=b1+[int(item,2)]
	c=file.readline()[:-1].split()
	c1=[]
	for item in c:
		c1=c1+[int(item,2)]
	#d=[]
	e=[]
	for item in b1:
		d=[]
		for it in c1:
			d=d+[item^it]
		e=e+[d]
	f=e[0]
	for item in e:
		f=set(f)&set(item)
	cou=0
	if len(f) !=0:
		g=min(f)
		h=bin(g)[2:]
		#cou=0
		for item in h:
			if item == '1':
				cou=cou+1
		print "Case #"+str(i+1)+": "+str(cou)
	else:
		print "Case #"+str(i+1)+": NOT POSSIBLE"
