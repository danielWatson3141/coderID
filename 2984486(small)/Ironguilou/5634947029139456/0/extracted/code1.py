
import sys
from numpy import *

#fileName = "test"
fileName = "A-small-attempt0"

fin = open(fileName + ".in")
fout = open(fileName + ".out", 'w')

NCases = int(fin.readline())
sys.stderr.write("NCases = " + str(NCases) + "\n")

def f(N, L, outs, devs, index) :
	if index == L :
		o = sorted(outs)
		d = sorted(devs)
		return (o == d, 0)

	o1 = 0
	d1 = 0
	for n in range(N) :
		o1 += outs[n][index]
		d1 += devs[n][index]
			
	if o1 == d1 and o1 == N / 2 :
		ok, switch = f(N, L, outs, devs, index + 1)
		if ok :
			return (ok, switch)
		else :
			for n in range(N) :
				outs[n][index] = 1 - outs[n][index]
			ok, switch = f(N, L, outs, devs, index + 1)
			for n in range(N) :
				outs[n][index] = 1 - outs[n][index]
			return (ok, switch + 1)
	elif o1 == d1 :
		return f(N, L, outs, devs, index + 1)
	elif o1 == N - d1 :
		for n in range(N) :
			outs[n][index] = 1 - outs[n][index]
		ok, switch = f(N, L, outs, devs, index + 1)
		for n in range(N) :
			outs[n][index] = 1 - outs[n][index]
		return (ok, switch + 1)
	else :
		return (False, 0)
	
	

for nline in range(0, NCases) :
	print "\n############################"
	print "# Case " + str(nline)
	
	N, L = map(int, fin.readline().strip().split())
	outs = [map(int, s) for s in fin.readline().strip().split()]
	devs = [map(int, s) for s in fin.readline().strip().split()]
	ok, switch = f(N, L, outs, devs, 0)
	print ok, switch
	
	if ok :
		s = str(switch)
	else :
		s = "NOT POSSIBLE"
	
	fout.write("Case #" + str(nline+1) + ": " + s + "\n")

fin.close()
fout.close()