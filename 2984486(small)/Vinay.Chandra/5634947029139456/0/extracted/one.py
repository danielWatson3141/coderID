t = int(input())
x = 1;
cl = []

def f(x):
	if x == '1' :
		return '0'
	elif x == '0':
		return '1'
	else :
		print("WTF")

def cout(code) :
	ans = 0;
	for i in code :
		if i == "1" :
			ans += 1
	return ans

def magic(first,cl,l,n,second) :
	#print(cl)
	minc = 1000000
	first.sort()
	second.sort()
	for i in range(len(cl)):
		x = magic2(first,cl[i],l,n)
		x.sort()
		if x == second :
			minc= min(minc,cout(cl[i]))
	if(minc == 1000000) :
		return -1
	else :
		return minc

def magic2(first,code,l,n):

	#print("First :", end="")
	#print(first)
	#print("code :"+code)

	answer = []

	for i in range(n):
	   answer.append("")

	for i in range(l) :
		if code[i] == "0" :
			for j in range(n) :
				answer[j] += first[j][i]
		else :
			for j in range(n) :
				answer[j] += f(first[j][i])

	return answer
		

while x <= t :

	cl = [""]
	
	n,l = input().split()
	n = int(n)
	l = int(l)

	first = input().split()
	second = input().split()

	success = True

	for i in range(l) :
		fi = [x[i] for x in first]
		si = [x[i] for x in second]

		fi.sort()
		si.sort()
		
		fir = [f(x) for x in fi]
		fir.sort()

		cl2=[]
		cl3=[]

		if fi == si :
			#code += "0"
			cl2 = [x+"0" for x in cl]

		if fir == si :
			#code += "1"
			cl3 = [x+"1" for x in cl]
		
		cl = cl2 + cl3

		if fi != si and fir != si :
			success = False;
			break

	second.sort()

	if success == True  :
		count = magic(first,cl,l,n,second)

	if success == False or count == -1:
		print ("Case #"+str(x)+": NOT POSSIBLE")

	else :
		print("Case #"+str(x)+": "+str(count))


	x += 1
