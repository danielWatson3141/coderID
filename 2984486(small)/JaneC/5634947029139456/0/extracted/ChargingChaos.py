# ChargingChaos.py
"""
author: Jane Chen
date: 2014-04-26
description: A program solving the 2014 Google Code Jam Problem A.
"""
import string
import itertools

def readfile(filename):
	fInput = open(filename, 'r')
	lstCases = []

	caseNum = int(fInput.readline())

	for case in range(0, caseNum):
		fInput.readline()
		flows = string.replace(fInput.readline(), '\n', '').split(' ')
		devices = string.replace(fInput.readline(), '\n', '').split(' ')
		lstCases.append([flows, devices])

	return lstCases

def process(lstCases):
	cnCase = 0
	fOutput = open('A-small-attempt1.out', 'w')

	for case in lstCases:
		cnCase += 1
		cnFlip = 0
		fOutput.write('Case #'+str(cnCase)+': ' )
		flows, devices = case[0], case[1]
		length = len(flows[0])
		abnormal = False
		for pos in range(0, length):
			flowZero = countZeros(flows, pos)
			flowOne = len(flows) - flowZero
			deviceZero = countZeros(devices, pos)
			# deviceOne = length - deviceZero
			if flowZero == deviceZero:
				continue # check the next position
			elif flowOne == deviceZero:
				flows = setPos(flows, pos) # set the positions
				cnFlip += 1
				continue
			else:
				fOutput.write('NOT POSSIBLE\n')
				abnormal = True
				break
		if abnormal:
			continue
		elif set(flows) == set(devices): # make another check
			fOutput.write(str(cnFlip)+'\n')
		else:
			result = bruteForce(case)
			if result != -1:
				fOutput.write(str(result)+'\n')
			else:
				fOutput.write('NOT POSSIBLE\n')

	fOutput.close()

def countZeros(elecs, pos):
	counter = 0

	for e in elecs:
		if e[pos] == '0':
			counter += 1

	return counter

def setPos(flows, pos):
	newFlows = []
	for f in flows:
		flist = list(f)
		if flist[pos] == '0':
			flist[pos] = '1'
		else:
			flist[pos] = '0'
		newFlows.append(''.join(flist))

	return newFlows

def bruteForce(case):
	flows, devices = case[0], case[1]
	length = len(flows[0])
	abnormal = False
	for num in range(1, length+1):
		allPossible = list(itertools.combinations(range(0, length), num))
		for elem in allPossible:
			tempFlow = flows[:]
			for pos in range(0, num):
				tempFlow = setPos(tempFlow, elem[pos])
			if set(tempFlow) == set(devices): # make another check
				return num
	return -1

def main():
	filename = 'A-small-attempt1.in'
	process(readfile(filename))

if __name__ == '__main__':
	main()