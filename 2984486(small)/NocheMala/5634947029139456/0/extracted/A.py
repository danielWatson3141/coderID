import sys

def Solve():
	m,l = [int(x) for x in my_file.readline().split()]
	flow2 = my_file.readline().split()
	dev2 = my_file.readline().split()
	cnt2 = l+1
	for i in range(m):
		flow2[i] = list(flow2[i])
		dev2[i] = list(dev2[i])
	for i in range(m):
		flow = []
		dev = []
		for h in range(m):
			flow.append(flow2[h][:])
			dev.append(dev2[h][:])
		cnt = 0
		match = True
		for j in range(l):
			if flow[i][j] != dev[0][j]:
				cnt += 1
				for k in range(m):
					if flow[k][j] == '0':
						flow[k][j] = '1'
					else:
						flow[k][j] = '0'
		for p in range(m):
			found = False
			for q in range(len(dev)):
				if flow[p] == dev[q]:
					del(dev[q])
					found = True
					break
			if not found:
				match = False
		if match:
			cnt2 = min(cnt2,cnt)
	if cnt2 == l+1:
		return 'NOT POSSIBLE'
	else:
		return str(cnt2)

def printCase(caseNum,strs):
	sys.stdout.write("Case #"+str(caseNum)+": "+strs+"\n")
	my_file2.write("Case #"+str(caseNum)+": "+strs+"\n")

my_file = open('Input.txt',"r")
my_file2 = open('Output.txt', "w")
N = int(my_file.readline())
for case in range(1,N+1):
	printCase(case,Solve())
my_file.close()
my_file2.close()