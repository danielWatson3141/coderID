import re

fr = open("input.txt", 'r')
fw = open("output.txt", 'w')

lines = fr.readlines()

numTests = int(lines[0].strip())
curTest = 0
curLine = 1

def getLine():
	global curLine
	global lines
	curLine += 1
	return lines[curLine-1]
	
def getMult():
	return getLine().strip().split()

def getMultInt():
	return map(int, getMult())
	
def getMultFloat():
	return map(float, getMult())
	
		
def flipBits(mask, arr):
	out = []
	for a in arr:
		n = int(a, 2) ^ mask
		out.append(n)
		
	return out

def countBits(n):
	total = 0
	b = n
	while b > 0:
		total += 1
		b &= (b-1)
		
	return total
	
while curTest < numTests:	
	
	# ...
	N, L = getMultInt()
		
	shota = getMult()
	outlets = getMult()

	outletsN = flipBits(0, outlets)
	min = 10000

	s = "NOT POSSIBLE"
	for a in shota:
		for b in outlets:
			g = abs(int(a, 2) ^ int(b, 2))
			if set(flipBits(g, shota)) == set(outletsN):
				m = countBits(g)
				
				if m < min:
					min = m
					s = str(m)
		
	fw.write("Case #%d: %s\n" % (curTest+1, s))
	curTest += 1
					
fr.close()
fw.close()