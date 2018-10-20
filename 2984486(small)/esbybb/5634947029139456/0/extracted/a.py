inp1=open('A-small-attempt0.in')
T = int(inp1.readline().strip())

def tobin(n,l):
	nn=n
	br=[0]*l
	inx=0
	while nn>0:
		br[inx]=(nn%2)
		inx+=1
		nn/=2
	return br
	
	
for tc in range(T):
	N,L = map(int,inp1.readline().strip().split())
	S1=inp1.readline().strip().split()
	S2=inp1.readline().strip().split()
	
	S2s=sorted(S2)
	
	min=L+1
	import math
	for j in range(int(math.pow(2,L))):
		
		tb=tobin(j,L)
		
		S1t=S1[:]
		cnt=0
		for l in range(L):
			
			if tb[l]==1:
				for v in range(N):
					w=list(S1t[v])
					if w[l]=='0':
						w[l]='1'
					else:
						w[l]='0'
					S1t[v]=	''.join(map(str,w))
				cnt+=1
		S1s=sorted(S1t)
		
		if S1s==S2s:
			if cnt<min: min=cnt
	
	res='NOT POSSIBLE'
	if min<=L: res=min
	print 'Case #{}: {}'.format(tc+1,res)
	