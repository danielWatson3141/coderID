import sys

f = open(sys.argv[1])
for t in range(1, int(f.readline())+1):
	N, L = map(int, f.readline().split())
	flows = map(lambda x: int(x, 2), f.readline().split())
	devices = sorted(map(lambda x: int(x, 2), f.readline().split()))
	
	mins = L+1;
	for i in range(2**L):
		flows_corrected = sorted([i^x for x in flows])
		if flows_corrected == devices:
			num_ones = bin(i)[2:].count('1')
			if num_ones < mins:
				mins = num_ones
	if mins < L+1:
		print 'Case #%d: %d' % (t, mins)
	else:
		print 'Case #%d: %s' % (t, "NOT POSSIBLE")
