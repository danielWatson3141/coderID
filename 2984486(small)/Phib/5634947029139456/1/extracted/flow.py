#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  Copyright 2014 User <phib@ubuntu>
#  
#  This program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; either version 2 of the License, or
#  (at your option) any later version.
#  
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#  
#  You should have received a copy of the GNU General Public License
#  along with this program; if not, write to the Free Software
#  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
#  MA 02110-1301, USA.
#  
#  

def ReadBlock():
	line = raw_input()
	lineSpl = line.rstrip().split(' ')
	output = []
	for flow in lineSpl:
		tmpFlow = []
		for e in flow:
			tmpFlow.append(int(e))
		output.append(tmpFlow)
	return output

def ReadCase():
	deviceFlow = ReadBlock()
	outletFlow = ReadBlock()
	return deviceFlow, outletFlow

def GetDiffBlock(deviceFlow, outletFlow):
	output = []
	for r in range(len(deviceFlow)):
		tmpRow = []
		currDevice = deviceFlow[r]
		for c in range(len(outletFlow)):
			currOutlet = outletFlow[c]
			diffVal = []
			for n in range(len(currOutlet)):
				if currDevice[n]!=currOutlet[n]:
					diffVal.append(n)
			tmpRow.append(diffVal)
		output.append(tmpRow)
	return output

def Solve(deviceFlow,outletFlow):
	diffBlock = GetDiffBlock(deviceFlow,outletFlow)
	if len(diffBlock)==1:
		#print "how to solve"
		#print diffBlock[0][0]
		return len(diffBlock[0][0])
	candidate = diffBlock[0]
	candidate.sort(key=lambda x: len(x))
	for i in candidate:
		isMiss = False
		for j in range(1, len(diffBlock)):
			if i not in diffBlock[j]:
				isMiss = True
				break
		if isMiss==False:
			#print "how to solve"
			#print i
			return len(i)
	return -1

def outputPrint(result, caseNo):
	resultStr = ""
	if result==-1:
		resultStr="NOT POSSIBLE"
	else:
		resultStr = str(result)
	print "Case #%d: %s"%(caseNo, resultStr)

def main():
	NCase = input()
	for n in range(NCase):
		line = raw_input()
		#print line
		N,L = map(int, line.rstrip().split())
		deviceFlow,outletFlow = ReadCase()
		#print deviceFlow
		#print outletFlow
		#print 
		#print 
		outputPrint(Solve(deviceFlow,outletFlow), n+1)
		#print '###########'
	return 0

if __name__ == '__main__':
	main()

