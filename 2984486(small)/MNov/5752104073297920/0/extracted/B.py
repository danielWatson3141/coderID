import random
from utility import *

def good(n):
	a = range(0,n)
	for p in range(0,n):
		k = random.randint(p,n-1)
		a[p],a[k] = a[k],a[p]
	return a

def bad(n):
	a = range(0,n)
	for p in range(0,n):
		k = random.randint(0,n-1)
		a[p],a[k] = a[k],a[p]
	return a
	
def experiment():
	ca = 0
	cb = 0
	for x in range(0,1000):
		a = good(1000)
		b = bad(1000)
		for i in range(0,1000):
			if a[i] == i:
				ca += 1
			if b[i] == i:
				cb += 1
	return ca,cb
	
gstring = "Case #%d: GOOD\n"
bstring = "Case #%d: BAD\n"

def solveOne(arr):
	c = 0
	d = 0
	for i in range(0,len(arr)):
		if arr[i] == i:
			c+=1
		if arr[i] in range(i-3,i):
			d += 1
	if c > 1:
		return gstring
	else:
		if d > 2:
			return bstring
		else:
			return gstring

def solveAll(filename):
	tests = testsAsNumbers(filename,2)
	f = open("output " + filename,'w')
	for i in range(0,120):
		f.write(solveOne(tests[i][1]) % (i+1))
	f.close()