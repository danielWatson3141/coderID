#/usr/bin/python

import sys

t = int(sys.stdin.readline())

def flipping(st, i):
	s = list(st)
	s[i] = '1' if s[i] == '0' else '0'
	return "".join(s)

def tryc(outlets, devices, flip, ii, n, l):
	pick = devices[ii]
	for i in range(l):
		if (flip[i] == -1):
			if (outlets[0][i] != pick[i]):
				flip[i] = 1
				for j in range(n):
					outlets[j] = flipping(outlets[j], i)
			else:
				flip[i] = 0
		elif (outlets[0][i] != pick[i]):
			return -1

	for i in range(n):
		if not (outlets[i] in devices):
			return -1
	return sum(flip)


for ii in range(t):
	m = map(int, sys.stdin.readline().split())

	outlets = sys.stdin.readline().split()
	devices = sys.stdin.readline().split()
	flip = [-1 for i in range(m[1])]

	obits = [0 for i in range(m[1])]
	dbits = [0 for i in range(m[1])]
	for i in range(m[0]):
		for j in range(m[1]):
			obits[j] += int(outlets[i][j])
			dbits[j] += int(devices[i][j])

	possible = True
	for i in range(m[1]):
		if (obits[i] + dbits[i] != m[0]):
			if (obits[i] == dbits[i]):
				flip[i] = 0
			else:
				possible = False
				break
		elif (obits[i] != dbits[i]):
			flip[i] = 1
			for j in range(m[0]):
				outlets[j] = flipping(outlets[j],i)

	if (possible):
		result = m[1]+1
		
		for i in range(m[0]):
			# print outlets, devices
			res = tryc(list(outlets), devices, list(flip), i, m[0], m[1])
			# print "try", i, res
			if (res != -1 and res < result):
				result = res
		if (result > m[1]):
			result = "NOT POSSIBLE"
	else:
		result = "NOT POSSIBLE"
	
	print "Case #{0:0d}:".format(ii+1), result
