
import sys
import random
from numpy import *

#fileName = "test"
fileName = "C-small-attempt0"

fin = open(fileName + ".in")
fout = open(fileName + ".out", 'w')

NCases = int(fin.readline())
sys.stderr.write("NCases = " + str(NCases) + "\n")

def gen(N) :
	p = range(1, N+1)
	for i in range(0, N-1) :
		k = random.randint(i, N-1)
		t = p[i]
		p[i] = p[k]
		p[k] = t
	
	print p
	return p

def prop(p) :
	N = len(p)
	f = 0
	for i in range(N) :
		if p[i] > i :
			f += 1
		
	return f
		
for nline in range(0, NCases) :
	print "\n############################"
	print "# Case " + str(nline)
	
	N = int(fin.readline().strip())
	p = map(int, fin.readline().strip().split())
	
	pr = prop(p)
	print pr
	
	if pr > 520 :
		s = "BAD"
	else :
		s = "GOOD"
	fout.write("Case #" + str(nline+1) + ": " + s + "\n")

fin.close()
fout.close()