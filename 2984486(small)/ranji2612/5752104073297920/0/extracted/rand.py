
f = open('C-small-attempt1.in', 'r')
f1 = open('C-large.out', 'w')



#T=int(raw_input())
T=int(f.readline())

i=0
res=[]

i=0
while i < T:
	N=int(f.readline())
	
	#s=raw_input().split()
	s=f.readline().split()
	ss=''.join(s)
	
	st='GOOD'
	for j in range(N):
		if j==int(s[j]):
			st='BAD'
	print s[0],s[int(s[0])],s[int(s[int(s[0])])]
	res.append(st)
	i=i+1

i=0
while i < T :
	f1.write("Case #"+str(i+1)+": "+res[i])
	print "Case #"+str(i+1)+": "+str(res[i])
	if not i == (T-1):
		f1.write('\n')
	i=i+1

f.close()
f1.close()