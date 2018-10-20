import string
import sys

def getIndex(value,array):
	if value in array:
		return [k for k in range(len(array)) if array[k] == value][0]

def pretreatment(array):
	for i in range(len(array)):
		array[i] = list(array[i])

def switch(outlets,k):
	for i in range(len(outlets)):
		if outlets[i][k] == '1':
			outlets[i][k] = '0'
		else:
			outlets[i][k] = '1'
	return outlets

def checkAll(outlets,devices):
	for i in range(len(outlets)):
		if outlets[i] in devices:
			devices.pop(getIndex(outlets[i],devices))
		else:
			return False
	return True

def checkBit(outlets,devices,k):
	for i in range(len(outlets)):
		if outlets[i][k] != devices[i][k]:
			return False
	return True

def flip(outlets,devices,L,k,count):
	if k == L:
		return -1

	if checkAll(outlets,list(devices)) == False:
		temp = flip(outlets,devices,L,k + 1,count)
		if temp != -1:
			return temp
	else:
		return count

	outletsSwitch = switch(list(outlets),k)
	if checkAll(outletsSwitch,list(devices)) == False:
		return flip(outletsSwitch,devices,L,k + 1,count + 1)
	else:
		return count + 1

if __name__ == '__main__':
	num = string.atoi(raw_input())
	
	for i in range(num):
		data = raw_input().split(' ')
		N = string.atoi(data[0])
		L = string.atoi(data[1])
		outlets = raw_input().split(' ')
		devices = raw_input().split(' ')
		pretreatment(outlets)
		pretreatment(devices)

		result = flip(outlets,devices,L,0,0)

		if result == -1:
			print 'Case #%r: NOT POSSIBLE' % (i + 1)
		else:
			print 'Case #%r: %r' % (i + 1,result)
	
