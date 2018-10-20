import sys
from random import random,seed
from collections import Counter
fname = "C-small-attempt3.in.txt"
# fname = "A-large.in.txt"
# fname = "sample.in"
fi = open(fname)
fo = open("fo.txt","w")
counter = Counter()
gb = Counter()
s = ['BAD','GOOD']
for test in range(int(fi.readline())):
	n = int(fi.readline())
	a = [int(x) for x in fi.readline().strip().split()]
	good = 1
	count = 0
	for i in range(n):
		if a[i] == i:
			count += 1
	print count,(1./2) ** count
	seed()
	if random() > (2./10) ** (count): 
		good = 0
	counter[count] += 1
	gb[good] += 1
	print >>fo,"Case #%d: %s"%(test+1,s[good])

print counter
print  gb