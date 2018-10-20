# Problem A. Charging Chaos
import sys

if not len(sys.argv):
	sys.exit()
input = open(sys.argv[1], 'r+')
T = int(input.readline())
for case in range(1, T+1):
	n, l = input.readline().split()
	n, l = int(n), int(l)
	outlets = [int(x, 2) for x in input.readline().split()]
	devices = set([int(x, 2) for x in input.readline().split()])
	min = l + 1
	num = 0
	for pattern in range(0, (1<<(l))):
		num += 1
		o_set = set()
		switch_count = 0
		for o in outlets:
			for i in range(0, l+1):
				o = o^(1<<i) if (1<<i)&pattern else o
			o_set.add(o)
		if o_set == devices:
			for i in range(0, l+1):
				if (1<<i)&pattern:
					switch_count += 1
			if switch_count < min:
				min = switch_count
	if min == l+1:
		print 'Case #%d: NOT POSSIBLE'%(case)
	else:
		print 'Case #%d: %d'%(case,min)
					