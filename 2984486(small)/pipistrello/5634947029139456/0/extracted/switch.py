		

T = int(raw_input())

start = []
end = []
for i in xrange(T):
	flag = 0
	tmp = raw_input().split()
	N = int(tmp[0])
	L = int(tmp[1])
	start = raw_input().split()
	start = [int(j,2) for j in start]
	start.sort()
	end = raw_input().split()	
	end = [int(j,2) for j in end]
	#print start
	for j in xrange(2**L):
		switched = [int(j)^int(k) for k in end]
		switched.sort()
		#print switched
		if start == switched:
			c = bin(j).count('1')
			print "Case #"+str(i+1)+": "+str(c)
			flag = 1
			break
	if flag == 0:
		print "Case #"+str(i+1)+": NOT POSSIBLE"
		

#print start.sort()


