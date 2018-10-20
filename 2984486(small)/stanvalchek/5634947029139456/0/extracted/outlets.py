def mix(x,y):
	if int(x)+int(y)==2:
		return '0'
	else:
		return str(int(x)+int(y))
		
def mixarrays(x,y):
	ret =''
	for i in range(len(x)):
		ret+=mix(x[i],y[i])
	return ret
	
def getcombos(num,sofar=[]):
	if num==0:
		return [sofar]
	ret =[]
	ret += getcombos(num-1,sofar+[0])
	ret += getcombos(num-1,sofar+[1])
	return ret
	
	
f=open('temp.txt')
g=open('submit.txt','wb')
for num in range(int(f.readline())):
	g.write( 'Case #' + str(num+1) +': ')
	[n,l] = map(int,f.readline().strip().split())
	outlets = f.readline().strip().split()
	devices = f.readline().strip().split()
	combos = getcombos(l)
	min = 9999999999999999999999999
	for i in combos:
		dev = [0]*n
		out = [0]*n
		for j in range(n):
			temp = mixarrays(i,outlets[j])
			for k in range(n):
				if temp == devices[k] and dev[k]==0 and out[j]==0:
					out[j],dev[k]=1,1
		if sum(out) == n and sum(dev) == n:
			if sum(i)<min:
				min = sum(i)
	if min<9999999999999999999999999:
		g.write(str(min) + '\n')
	else:
		g.write("NOT POSSIBLE" + '\n')
				
				
	
	