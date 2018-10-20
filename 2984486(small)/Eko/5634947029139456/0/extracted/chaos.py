import os, re, sys
import unittest


#tCase = sys.stdin.readline().split()
tCase = int(sys.stdin.readline())

	
def flip(list, b):
	rlist = []
	for a in list:
		#print a, bin(a), b, bin(b), bin(a^b)
		rlist.append(a^b)
	return rlist
		
def main(OList, DList, max):
	original = list(OList)
	
	OList.sort()
	DList.sort()
	
	nflip = 0
	
	min = max + 1

	while (nflip + 1) < 2**max:
		i = 0
		certo = True
		while i < len(OList):
			if OList[i] == DList[i]:
				i += 1
				continue
			else:
				certo = False
				break
				
		if certo:
			if bin(nflip).count("1") < min:
				min = bin(nflip).count("1")
		
		nflip += 1
		if bin(nflip).count("1") < min:
			OList = flip(original, nflip)				
			OList.sort()
			#print nflip, DList, OList, original
			
		#print OList, DList	

	
	if min < max + 1:
		return min
	else:
		return "NOT POSSIBLE"
		
 
if __name__ == '__main__':
	#unittest.main()
	for i in xrange(tCase):	
		#frase = [str(x) for x in sys.stdin.readline().split(' ')]	
		#print "Case #%d: %s" % (i + 1, main(frase[0]))
		
		##Numbers
		N, max = [int(x) for x in sys.stdin.readline().split(' ')]
		OList = [int(x, 2) for x in sys.stdin.readline().replace('\n', '').split(' ')]
		DList = [int(x, 2) for x in sys.stdin.readline().replace('\n', '').split(' ')]
		#print E,R,N, NList
		print "Case #%d: %s" % (i + 1, main(OList, DList, max))
