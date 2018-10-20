f=file("A-small-attempt0.in","r")
op=file("A.op","w")
total_line=f.readline()
total_line=int(total_line)


def ext(s,i):
	if i==1:
		ret=[]
		for ltr in s:
			ret.append(ltr)
		return ret
	
	curr=ext(s,i-1)
	
	ret=[]
	for ltr in s:
		for curr_ltr in curr:
			if curr_ltr!=ltr and ltr not in curr_ltr:
				temp=curr_ltr+ltr
				temp_s=[d for d in temp]
				temp_s.sort()
				
				add_str=''.join(temp_s)
				
				if add_str not in ret:
					ret.append(add_str)
	
	#for entry in ret:
	#	for ltrs in entry:
			
	return ret		

def get_str(string):
	
	l=len(string)
	
	for i in range(l):
		print ext(string,i+1)

def invert(out,i):
	ret=[]
	#print "out",out,i
	for each_ot in out:
		if each_ot[i]=='0':
			each_ot=list(each_ot)
			each_ot[i]='1'
			''.join(each_ot)
		elif each_ot[i]=='1':
			each_ot=list(each_ot)
			each_ot[i]='0'
			''.join(each_ot)
			
		ret.append(each_ot)
	return ret
	
	
def check(ot,goal,L):

	if ot==goal:
		return 0
	
	cnt=1
	string=''
	for l in range(L):
		string+=str(cnt)
		cnt+=1
		
	#print "string",string
	for l in range(L):
		try_list=ext(string,l+1)
		#print "try_list",try_list
		for t in try_list:
			temp_ot=ot
			for each_t in t:
				temp_ot=invert(temp_ot,int(each_t)-1)
					
			
			temp_ot.sort()	
			for i in range(len(temp_ot)):
				temp_ot[i]=''.join(temp_ot[i])
			#print "temp_ot",temp_ot,goal	
			if temp_ot==goal:
				#print "got it",l
				return l+1
				
	return L+1

for i in range(total_line):
	ln=f.readline().split('\n')[0]
	ln=ln.split(' ')
	
	N=int(ln[0])
	L=int(ln[1])
	
	#print "LN",L,N
	ots=f.readline()
	ot_list=ots.split(' ')
	ot_list[-1]=ot_list[-1].split('\n')[0]
	
	ot=[(data) for data in ot_list]
	
	ot.sort()
	#print ot
	
	ots=f.readline()
	ot_list=ots.split(' ')
	ot_list[-1]=ot_list[-1].split('\n')[0]
	
	goal=[(data) for data in ot_list]
	goal.sort()
	
	#print goal
	num=check(ot,goal,L)
	if num>L:
		string = "case #"+str(i+1)+": "+"NOT POSSIBLE"
	else:
		string = "case #"+str(i+1)+": "+str(num)	
	print string
	op.write(string+"\n")
