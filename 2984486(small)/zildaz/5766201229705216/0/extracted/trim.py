inputfile = open('B-small-attempt2.in')
outputfile = open('result2.txt','w')

no_of_tests = int(inputfile.readline())


def deleteFrom(delr,nodes,root):
	if(delr in nodes):
		for dnn in nodes[delr]:
			if dnn != root and dnn in nodes:
				del nodes[dnn]
				return deleteFrom(dnn,nodes,root)+1
	return 0
			

			
for t in range(no_of_tests):
	print t
	N = int(inputfile.readline())
	nodes = {}
	for i in range(N-1):
		a1 = map(long,inputfile.readline().split())
		c1=int(a1[0])
		c2=int(a1[1])

		l = []
		if c1 not in nodes:
			nodes[c1]=l
		else:
			l = nodes[c1]
		l.append(c2)
		
		l = []
		if c2 not in nodes:
			nodes[c2]=l
		else:
			l = nodes[c2]
		l.append(c1)
		
	dls = 0
	for j in range(1,N):
		for n in range(1,N):
			if n in nodes and len(nodes[n])==2:
				if(nodes[n][0] in nodes and len(nodes[nodes[n][0]])==2):
					delr = nodes[nodes[n][0]][0]
					if delr == n:
						delr = nodes[nodes[n][0]][1]
					dls += deleteFrom(delr,nodes,delr)
				if(nodes[n][1] in nodes and len(nodes[nodes[n][1]])==2):
					delr = nodes[nodes[n][1]][0]
					if delr == n:
						delr = nodes[nodes[n][1]][1]
					dls += deleteFrom(delr,nodes,delr)
				

			
			
	
		
		
	print  >>outputfile,"Case #%d: %d"  % (t+1,dls)


outputfile.close()