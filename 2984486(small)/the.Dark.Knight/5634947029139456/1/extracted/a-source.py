import copy
#fi=open("A-small-attempt1.in",'r')#Input File
#fo=open("A-small-attempt1.out",'w')#Output File

fi=open("A-large.in",'r')#Input File
fo=open("A-large.out","w")#Output File
def count(arr, n, ind):
    one = 0
    zero = 0
    for j in range(n):
        if arr[j][ind] == "0":
            zero += 1
        else:
            one += 1    
    return zero, one
def revert(arr, n, ind):
    #print arr, ind
    for i in range(n):
        if arr[i][ind] == "1":
            arr[i][ind] = "0"
        else:
            arr[i][ind] = "1"
    arr.sort(key=lambda x: x[:i+1])
    #print arr
    return arr
def check(out, bit, n, ind):
    #print out, bit, ind
    for i in range(n):
        if out[i][ind] != bit[i][ind]:
            return False
    #print "Yes"
    return True                    
    
def find(out, bit, n, l, ind):
    if ind == l:
        return 0
    ans = 0
    o0, o1 = count(out, n, ind)
    d0, d1 = count(bit, n, ind)
    bit.sort(key=lambda x: x[:ind+1])
    out.sort(key=lambda x: x[:ind+1])
    if o0==d0 and o1==d1 and o0==o1:
        temp = "NOT POSSIBLE"
        outt = copy.deepcopy(out)
        
        if check(out, bit, n, ind):
            temp = find(out, bit, n, l, ind+1)
            ans = 0
        if check(revert(outt, n, ind), bit, n, ind):
            temp2 = find(outt, bit, n, l, ind+1)
            if temp == "NOT POSSIBLE":
                temp = temp2
                ans = 1
                out = outt
            elif temp2 != "NOT POSSIBLE" and temp2+1<temp:
                temp = temp2
                ans = 1
    elif o0==d0 and o1==d1 and ind==0:
        temp = find(out, bit, n, l, ind+1)
    elif o0==d0 and o1==d1 and check(out, bit, n, ind):
        temp = find(out, bit, n, l, ind+1)
    elif o0==d1 and o1==d0 and check(revert(out, n, ind), bit, n, ind):
    	ans = 1
    	temp = find(out, bit, n, l, ind+1)
    else:
    	return "NOT POSSIBLE"
    if temp == "NOT POSSIBLE":
        return temp
    return ans+temp
           
#fi=open("A.in",'r')#Input File
#fo=open("A.out","w")#Output File
    
T=int(fi.readline())
for case in range(1,T+1,1):
	############################################
    	n, l = map(int, fi.readline().split())
    	out = map(list, fi.readline().split())
    	bit = map(list, fi.readline().split())
    	ans = find(out, bit, n, l, 0)
    	#print ans
    	"""
    	for i in range(l):
    	    o0, o1 = count(out, n, i)
    	    d0, d1 = count(bit, n, i)
    	    bit.sort(key=lambda x: x[:i+1])
    	    out.sort(key=lambda x: x[:i+1])
    	    print bit, out
    	    if o0==d0 and o1==d1 and i==0:
    	        continue
    	    elif o0==d0 and o1==d1 and check(out, bit, n, i):
    	        continue
    	    elif o0==d1 and o1==d0 and check(revert(out, n, i), bit, n, i):
    	        ans += 1
    	        continue        
    	    else:
    	        ans = "NOT POSSIBLE"
    	        break
    	"""        
	############################################
	fo.write("Case #%s: %s\n"%(case, ans))
