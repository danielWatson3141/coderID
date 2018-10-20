import sys

def map(func, l):
	return [func(i) for i in l]

def toArray(strlist):
	return [[int(i) for i in s] for s in strlist]

def parseCase(instrm):
	args = instrm.readline().strip().split()
	N = int(args[0]); L = int(args[1])
	outlets = toArray(instrm.readline().strip().split())
	flows = toArray(instrm.readline().strip().split())
	return (N,L, outlets, flows)

def getForest(outlets):
	if (len(outlets)==0 or len(outlets[0])==0):
		return None
	sub0 = []
	sub1 = []
	for i in range(len(outlets)):
		if (outlets[i][0] == 0):
			sub0.append(outlets[i][1:])
		else:
			sub1.append(outlets[i][1:])
	return [(len(sub0), getForest(sub0)), (len(sub1), getForest(sub1))]

def alignForests(f1, f2):
	if (f1 == []):
		return 0
	#check match without switch
	dmatch = True
	for i in range(int(len(f1)/2)):
		if (f1[2*i][0] != f2[2*i][0]):
			dmatch = False
			break
	
	dmatchScore = None
	if (dmatch):
		sf1 = []
		sf2 = []
		for i in range(len(f1)):
			if (not f1[i][1] is None):
				sf1.append(f1[i][1][0]);sf1.append(f1[i][1][1])
				sf2.append(f2[i][1][0]);sf2.append(f2[i][1][1]) 
		dmatchScore = alignForests(sf1, sf2)
	
	#check match with switch
	rmatch = True
	for i in range(int(len(f1)/2)):
		if (f1[2*i][0] != f2[2*i+1][0]):
			rmatch = False
			break
	#switch f1
	f1s = []
	for i in range(int(len(f1)/2)):
		f1s.append(f1[2*i + 1])
		f1s.append(f1[2*i])
	f1 = f1s
	rmatchScore = None
	if (rmatch):
		sf1 = []
		sf2 = []
		for i in range(len(f1)):
			if (not f1[i][1] is None):
				sf1.append(f1[i][1][0]);sf1.append(f1[i][1][1])
				sf2.append(f2[i][1][0]);sf2.append(f2[i][1][1]) 
		rmatchScore = alignForests(sf1, sf2)
	
	if (rmatchScore is None and dmatchScore is None):
		return None
	if (rmatchScore is None):
		return dmatchScore
	if (dmatchScore is None):
		return 1+rmatchScore
	return min(dmatchScore, 1+rmatchScore)
	
	

def solveCase(input):
	(N,L,outlets,flows) = input
	f1 = getForest(outlets)
	f2 = getForest(flows)
	score = alignForests(f1, f2)
	if (score is None):
		return "NOT POSSIBLE"
	return score


if __name__=="__main__":
	instrm = open(sys.argv[1])
	cases = int(instrm.readline().strip())
	for i in range(cases):
		input = parseCase(instrm)
		print("Case #" + str(i+1) +": "+str(solveCase(input)))
	instrm.close()