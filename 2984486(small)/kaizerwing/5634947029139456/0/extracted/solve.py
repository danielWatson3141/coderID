from sys import stdin
from collections import Counter

for case in xrange(int(input())):
	n,l = [int(x) for x in stdin.readline().split()]
	outlets = [int(x, 2) for x in stdin.readline().split()]
	devices = [int(x, 2) for x in stdin.readline().split()]
	pattern = [bin(int(x))[2:].rjust(l, '0') for x in range(2**l)]
	best = -1
	for p in pattern:
		temp = map(lambda x: x ^ int(p,2), outlets)	
		if Counter(temp) == Counter(devices):
			numswitch = p.count('1')
			if best < 0 or numswitch < best:
				best = numswitch
				x = p
	if best > -1:
		ans = best
	else:
		ans = 'NOT POSSIBLE'
	print('Case #{}: {}'.format(case + 1, ans))
