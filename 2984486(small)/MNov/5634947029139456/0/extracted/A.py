from utility import *

success = "Case #%d: %d\n"
failure = "Case #%d: NOT POSSIBLE\n"

def hamming(s1,s2):
	dist = 0
	for i in range(0,len(s1)):
		if s1[i] != s2[i]:
			dist+=1
	return dist

def flip(strings,switches):
	splitStrings = strings.split()
	output = ['' for string in splitStrings]
	for string in range(0,len(splitStrings)):
		for switch in range(0,len(switches)):
			if switches[switch] == '0':
				output[string] += splitStrings[string][switch]
			else:
				if splitStrings[string][switch] == '0':
					output[string] += '1'
				else:
					output[string] += '0'
	return output
	
def compare(outlets,devices):
	outlets.sort()
	devices.sort()
	for outlet in xrange(0,len(outlets)):
		if outlets[outlet] != devices[outlet]:
			return False
	return True
	
def solveOne(outlets,devices,case):
	n = len(outlets.split()[0])
	min = n + 1
	for i in xrange(0,2**n):
		switches = bin(i)[2:]
		switches = '0'*(n-len(switches)) + switches
		if compare(flip(outlets,switches),flip(devices,n*'0')):
			if min > hamming(n*'0',switches):
				min = hamming(n*'0',switches)
	if n >= min:
		return success % (case,min)
	else:
		return failure % case
		
def solveAll(filename):
	tests = divideIntoTests(filename,3)
	f = open("output " + filename, 'w')
	for test in xrange(0,len(tests)):
		f.write(solveOne(tests[test][1],tests[test][2],test+1))
	f.close()