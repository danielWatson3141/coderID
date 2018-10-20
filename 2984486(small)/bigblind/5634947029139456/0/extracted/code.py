from copy import deepcopy
import plex

from mpmath import *
mp.dps = 20
import sys
inp = open("in.txt")
out = open("out.txt","w+")
sys.stdout = out
tc = 0


t = int(inp.readline())

def print_case(case, result):
	print "Case #%d: %s" % (case, str(result))

def debug(message):
	sys.stdout = sys.__stdout__
	print message
	sys.stdout = out

def enumerate_n_flips(l, n):
	#debug((l, n))
	
	if n == 0:
		yield l*[False]
	else:
		for i in xrange(l - (n-1)):
			for s in enumerate_n_flips(l-(i+1), n-1):
				 yield [False]*i + [True] + s


def enumerate_flips(l):
	for i in xrange(l+1):
		for s in enumerate_n_flips(l,i):
			debug((s, l))
			yield s, i
	
make_list = lambda x: [c=="1" for c in x]

def flip_outlets(outlets, flipstr):
	o = deepcopy(outlets)
	def flip_outlet(outlet):
		for i in xrange(len(outlet)):
			if flipstr[i]:
				outlet[i] = not outlet[i]
		return outlet
	return [flip_outlet(outl) for outl in o]

if __name__ == "__main__":
	for tc in xrange(t):
		N, L = [int(x) for x in inp.readline().split()]
		outlets = [make_list(x) for x in inp.readline().split()]
		devices = [make_list(x) for x in sorted(inp.readline().split())]
		
		found = False
		for s, flips in enumerate_flips(L):
			if sorted(flip_outlets(outlets, s)) == devices:
				print_case(tc+1, flips)
				found = True
				break
		
		if not found:
			 print_case(tc+1, "NOT POSSIBLE")