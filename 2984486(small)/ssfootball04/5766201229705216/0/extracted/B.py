import fileinput

f=fileinput.input()
T=int(f.readline())
g=open('output2','w')

def traverse(R,E):
	Con=[]
	En=list(E)
	for i in E:	
		if(i[0]==R):
			Con.append(i[1])
			En.remove(i)
		elif(i[1]==R):
			Con.append(i[0])
			En.remove(i)
	if(len(Con)==0):
		return (R,0,[])
	else:
		l=[]
		for i in Con:
			l.append(traverse(i,En))
		return (R,len(l),l)							

def count(trvs):
	s=trvs[1]
	for i in trvs[2]:
		s=s+count(i)
	return s

def upd(trvs):
	R=trvs[0]
	ln=trvs[1]
	if(ln==0 or ln==2):
		l=[]
		for i in trvs[2]:
			l.append(upd(i))		
		return (trvs[0],trvs[1],l)
	else:
		ans=(trvs[0],0,[])
		max=0
		for i in range(len(trvs[2])):
			for j in range(i+1,len(trvs[2])):
				l=[]
				l.append(upd(trvs[2][i]))
				l.append(upd(trvs[2][j]))
				a=(trvs[0],2,l)
				n=count(a)
				if (n>max):
					ans=a
		return ans

def solve(N,E):
	ans=[]
	for i in range(1,N+1):
		A=traverse(i,E)
		B=upd(A)
		C=count(B)+1
		ans.append(N-C)
	ans.sort()
	return ans[0]		
	
for l in range(T):
	N=int(f.readline())
	E=[]
	k=1
	while(k<=N-1):
		line=f.readline()
		j=0
		while(line[j]!=' '):
			j=j+1
		E1=int(line[:j])
		E2=int(line[j+1:])
		E.append((E1,E2))
		k=k+1
	ans=str(solve(N,E))
	g.write( 'Case #'+str(l+1)+': '+ans+"\n")
