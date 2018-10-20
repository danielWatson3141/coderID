from __future__ import division

import sys, os


def num_ones(i):
	ret = 0
	while i:
		i &= i - 1
		ret += 1
	return ret
		

def do_case(devices, outlets, size):
	hash_dev = {}
	best = size + 10
	for dev in devices:
		hash_dev[dev] = True
	for i in range(2**size):
		i_outs = map(lambda l: l ^ i, outlets)
		bad = False
		for i_o in i_outs:
			if i_o not in hash_dev:
				bad = True
				break
		if bad:
			continue
		best = min(best, num_ones(i))
	if best > size:
		return "NOT POSSIBLE"
	return str(best)
	
f = open(sys.argv[1], 'r')
out = open(sys.argv[2], 'w')

num_cases = int(f.readline())
for i in range(1,num_cases+1):
	num_outdev, size = map(int, f.readline().split())
	outs = list(map(lambda l: int(l,2), f.readline().split()))
	devs = list(map(lambda l: int(l,2), f.readline().split()))
	
	res = do_case(devs, outs, size)
	print "Case #%d:" % (i), res
	out.write("Case #%d: %s\n" % (i, res))

	
	