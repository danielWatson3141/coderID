import itertools

def bc(x):
	return bin(x).count("1")

t = input()
for i in xrange(t):
	print "Case #" + str(i + 1) + ":",
	[n, l] = map(int, raw_input().split())
	outlets = [int(x, 2) for x in raw_input().split()]
	devices = [int(x, 2) for x in raw_input().split()]
	ans = l + 1
	for j in xrange(2 ** l):
		if bc(j) >= ans: continue
		for k in outlets:
			if k ^ j not in devices: break
		else:
			ans = bc(j)
	if ans == l + 1: print "NOT POSSIBLE"
	else: print ans