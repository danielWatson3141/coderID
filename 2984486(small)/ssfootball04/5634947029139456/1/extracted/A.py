import fileinput

f=fileinput.input()
T=int(f.readline())
g=open('output','w')

def solve(Nm,Kn):
	ans=[]
	Nam=[]	
	for i in Nm:
		Nam.append(int(i))	
	Nam.sort()
	
	for i in Kn:
		S=[]
		Ap=Nm[0]
		Ou=i
		j=0
		while(j<len(Ap)):
			if(Ap[j]!=Ou[j]):
				S.append(j)
			j=j+1
		Ken=[]
		for j in Kn:
			st=""
			for k in range(len(j)):
				if (S.count(k)==0):
					st=st+j[k]
				else:
					st=st+str(1-abs(int(j[k])))
			Ken.append(st)
		Kan=[]
		for x in Ken:
			Kan.append(int(x))		
		Kan.sort()
		if(Nam==Kan):
			ans.append(len(S))
	ans.sort() 
	if(len(ans)==0):
		return "NOT POSSIBLE"
	else:
		return str(ans[0])

for l in range(T):
	line=f.readline()
	j=0
	while(line[j]!=' '):
		j=j+1
	N=int(line[:j])
	L=line[j+1:]
	j,k,p=0,0,0
	Nm=[]
	line=f.readline()+" "
	while(k!=N):
		if(line[j]==' '):
			Nm.append(line[p:j])
			k,p=k+1,j+1	
		j=j+1
	j,k,p=0,0,0
	Kn=[]
	line=f.readline()+" "
	while(k!=N):
		if(line[j]==' '):
			Kn.append(line[p:j])
			k,p=k+1,j+1	
		j=j+1
	
	ans=str(solve(Nm,Kn))
	g.write( 'Case #'+str(l+1)+': '+ans+"\n")
