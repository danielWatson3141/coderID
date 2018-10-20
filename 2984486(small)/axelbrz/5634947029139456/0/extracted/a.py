f = open("A-small-attempt0.in", "r")
d = f.read()
f.close()

def copyini(ini):
	return [[e for e in v] for v in ini]

def solveEasy(ini, end):
	N = len(ini)
	L = len(ini[0])
	#print ini, end, N, L
	end.sort()
	#print "JO", 2**L
	NO = 10000000000000
	minbits = NO
	for i in xrange(2**L):
		num = i
		c = copyini(ini)
		nbits = 0
		bits = []
		#print num,
		for ibit in xrange(L):
			bit = num % 2
			bits.append(bit)
			if bit == 1:
				nbits += 1
				for k in xrange(len(c)):
					c[k][ibit] = 1 - c[k][ibit]
			num /= 2
		c.sort()
		#print bits
		#raw_input()
		if c == end:
			minbits = min(minbits, nbits)
	if minbits < NO:
		return minbits
	return "NOT POSSIBLE"
			
	c = 0
	for i in xrange(len(ini[0])):
		v = (ini[0] == end[0])
		if not v: c += 1
		for j in xrange(1, len(ini)):
			if v != (ini[j] == end[j]): return "NOT POSSIBLE"
	return str(c)

def dontSolve(ini, end):
	c = 0
	for i in xrange(len(ini[0])):
		v = (ini[0] == end[0])
		if not v: c += 1
		for j in xrange(1, len(ini)):
			if v != (ini[j] == end[j]): return "NOT POSSIBLE"
	return str(c)


d = d.split("\n")[:-1]
n = int(d[0])
d = d[1:]

f = open("a.out", "w")
j = 0
for i in xrange(n):
	d[j+1] = d[j+1].split(" ")
	d[j+2] = d[j+2].split(" ")
	for k in xrange(len(d[j+1])):
		d[j+1][k] = list(d[j+1][k])
		d[j+2][k] = list(d[j+2][k])
		d[j+1][k] = [int(e) for e in d[j+1][k]]
		d[j+2][k] = [int(e) for e in d[j+2][k]]
	s = "Case #%d: %s" % (i+1, solveEasy(d[j+1], d[j+2]))
	print s
	f.write(s+"\n")
	j += 3
f.close()

