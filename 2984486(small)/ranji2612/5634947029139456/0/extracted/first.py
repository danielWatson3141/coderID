def copylist(s):
	D=[]
	for i in s:
		D.append(i)
	return D
def checkmatch(s,s1):
	for i in range(len(s)):
		if not s[i]==s1[i]:
			return 0
	return 1
def toggle(s):
	if s=='0':
		return '1'
	else:
		return '0'
f = open('A-small-attempt1.in', 'r')
f1 = open('A-small.out', 'w')

import itertools 

#T=int(raw_input())
T=int(f.readline())

i=0
res=[]

i=0
while i < T:
	#s=raw_input().split()
	s=f.readline().split()
	N=int(s[0])
	L=int(s[1])
	
	#s=raw_input().split()
	s=f.readline().split()
	s=sorted(s)
	
	
	#s1=raw_input().split()
	s1=f.readline().split()
	s1=sorted(s1)
	
	count=0
	flag=checkmatch(s,s1)
	if flag:
		count=0
	else:
		k=[x+1 for x in range(L)] 
		
		ii=0
		flag=0
		while ii < L:
			Set=[]
			k1=itertools.combinations(k, ii+1)
			for j in k1:
				s2=copylist(s)
				for jj in j:
					for z in range(len(s)):
						s2[z]=s2[z][:jj-1]+toggle(s2[z][jj-1])+s2[z][jj:]
				
				s2=sorted(s2)
				if i==0:
					print s,s2
				
				flag=checkmatch(s2,s1)
				if flag==1:
					count=ii+1
					ii=L
					print 'passed'
					break
			ii=ii+1
		if flag==0:
			count=-1
	if count==-1:	
		res.append('NOT POSSIBLE')
	else:
		res.append(str(count))
	i=i+1

i=0
while i < T :
	f1.write("Case #"+str(i+1)+": "+res[i])
	#print "Case #"+str(i+1)+": "+str(res[i])
	if not i == (T-1):
		f1.write('\n')
	i=i+1

f.close()
f1.close()