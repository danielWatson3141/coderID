import copy,time

def ev(n):
	avg = ((n * (n+1.))/2 - n) / n
	v = [i for i in range(n)]
	for i in range(n):
		tmp = copy.copy(v)
		for j in range(n):
			if j==i:
				tmp[j] = avg
			else:
				tmp[j] = (v[j] * (n-1.)/n) + (v[i]*1./n)
		v=copy.copy(tmp)
		#print v
	return v

e = ev(1000)

f=open('temp.txt')
q=open('submit.txt','wb')
for num in range(int(f.readline())):
	q.write( 'Case #' + str(num+1) +': ')
	g,b=0.,0.
	n = int(f.readline())
	n = map(int,f.readline().strip().split())
	for i in range(len(n)):
		g+=abs(n[i]-e[-1])
		b+=abs(n[i]-e[i])
	if g>b:
		q.write('BAD\n')
	else:
		q.write('GOOD\n')
		

