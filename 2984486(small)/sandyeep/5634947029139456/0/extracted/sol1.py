def f1(a,b):
	s = 0
	for i in range(b):
		if a&(2**i) != 0:
			s+=1
	return s
def fn(z):
	n,l = map(int, raw_input().split())
	ini = raw_input().split()
	fin = raw_input().split()
	for i in range(n):
		ini[i], fin[i] = int(ini[i], 2), int(fin[i], 2)
	fin.sort()
	f = 0
	lv = 0
	for i in range(2**l - 1):
		temp = []
		f = 0
		for j in ini:
			temp.append(j)
		for j in range(n):
			temp[j] = temp[j]^i
		temp.sort()
		for j in range(n):
			if temp[j]!=fin[j]:
				f = 1
		if f == 0:
			lv = i
			break
	if f == 1:
		ff.write("Case #" + str(z) +  ": NOT POSSIBLE" + "\n")
	else:
		ff.write("Case #"+ str(z)+ ": " +str(f1(lv,l)) + "\n")

t = int(raw_input())
ff = open('out.txt', 'w')
for i in range(t):
	
	fn(i+1)
ff.close()


