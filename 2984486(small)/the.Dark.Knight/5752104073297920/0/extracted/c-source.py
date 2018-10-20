from random import randint
fi=open("C-small-attempt1.in",'r')#Input File
fo=open("C-small-attempt1.out",'w')#Output File

#fi=open("C-large.in",'r')#Input File
#fo=open("C-large.out","w")#Output File

#fi=open("C.in",'r')#Input File
#fo=open("C.out","w")#Output File
    
T=int(fi.readline())
for case in range(1,T+1,1):
	############################################
    	n = int(fi.readline())
    	arr = map(int, fi.readline().split())
    	out = ["GOOD", "BAD"]
    	cnt = 0
    	for i in range(n):
    	    if arr[i] == i:
    	        cnt += 1
    	if cnt < n/4:
    	    ans = "BAD"
    	else:    
    	    ans = out[randint(0, 1)]
    ############################################
	fo.write("Case #%s: %s\n"%(case, ans))
