def distance(a11):
		ans = 0
		while a11:
				if a11&1:
						ans+=1
				a11 = a11 >> 1
		return ans

def makeamatch(l1,l2):
		for i in range(0,len(l1)):
				if l1[i] != l2[i]:
						return False
		return True

f = open("output.txt","w")
t = int(raw_input())
for kk in range(0,t):
		N,L = map(int,raw_input().split())
		config = raw_input().split()
		ndc = raw_input().split()
		ndc.sort()
		for i in range(0,N):
				config[i] = int(config[i],2)
				ndc[i] = int(ndc[i],2)
		t = pow(2,L)
		ans = []
		for i in range(0,t+1):
				newc = []
				for j in range(0,N):
						newc.append(config[j] ^ i)
				newc.sort()
				if makeamatch(newc,ndc):
						ans.append(distance(i))
		if ans == [] :
				f.write("Case #"+str(kk+1)+": NOT POSSIBLE\n")
				print "NOT POSSIBLE"
				continue
		f.write("Case #"+str(kk+1)+": "+str(min(ans))+"\n")
		print min(ans)
f.close()
		
		
