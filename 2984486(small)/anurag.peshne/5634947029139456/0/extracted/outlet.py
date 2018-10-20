import sys
def doXor(iFlow, rFlow):
	retStr = ''
	for stringIndex in range(int(NL[1])):
		if iFlow[stringIndex] != rFlow[stringIndex]:
			retStr += '1'
		else:
			retStr += '0'
	return retStr

t = input()
for it in range(int(t)):
	NL = input()
	NL = NL.split()
	iniFlow = input()
	reqFlow = input()
	iniFlow = iniFlow.split()
	reqFlow = reqFlow.split()
	operation = []
	
	for iFlow in iniFlow:
		tempArray = []
		for rFlow in reqFlow:
			tempArray.append(doXor(iFlow, rFlow))
		operation.append(tempArray)
	
	ansXor = []
	for switch in operation[0]:
		presentInAll = True
		for row in operation:
			if not(switch in row):
				presentInAll = False;
		if presentInAll:
			ansXor.append(switch)

	if len(ansXor) > 0:
		smallest = sys.maxsize
		for ansX in ansXor:
			ans = 0
			for letter in ansX:
				if letter == '1':
					ans = ans + 1
			if ans < smallest:
				smallest = ans
		print("Case #",it+1,": ",smallest,sep='')
	else:
		print("Case #",it+1,": NOT POSSIBLE",sep='')





