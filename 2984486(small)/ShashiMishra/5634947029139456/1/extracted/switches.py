t = input()

for x in range(1,t+1):
	a= raw_input().strip()
	
	N,L = [int(y) for y in a.strip().split()];
	outlets = raw_input().split()
	chargeP = raw_input().split()
	allp = []
	for i in range(0,N):
		differences = []
		for j in range(0,N):
			l=[]
			for k in range(0,L):
				if chargeP[i][k] != outlets[j][k]:
					l.append(k)
			differences.append(l)
		allp.append(differences)
	
	#print allp
	mini= 1000000
	result = False
	for i in range(0,N):
		k=allp[0][i]
		l=[i]
		for j in range(1,N):
			try:
				z=allp[j].index(k)
				l.append(z)
			except:
				continue
		#print l
		if len(l) == N :
			if len(l) == len(set(l)):
				if(len(k)<mini):
					mini = len(k)
				result = True
			
	if result:
		print "Case #"+str(x)+": "+str(mini)
	else:
		print "Case #"+str(x)+": NOT POSSIBLE"
		
