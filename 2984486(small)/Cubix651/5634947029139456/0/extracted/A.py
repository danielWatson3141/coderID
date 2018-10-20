from sys import argv

def bin2int(seq):
	_pow = 1
	r = 0
	for c in seq:
		r += int(c) * _pow
		_pow *= 2
	return r

def solve(n, l, outs, devs):
	res = 50
	for o in outs:
		flip = o^devs[0]
		conv = map(lambda x: x^flip, outs)
		if set(conv) == set(devices):
			res = min(res, bin(flip).count('1'))
	if res != 50:
		return res
	else:
		return 'NOT POSSIBLE'


f = open(argv[1])
t = int(f.readline())
for i in range(t):
	n, l = map(int, f.readline().split(' '))
	outlets = map(lambda x: int(x, 2), f.readline().strip().split(' '))
	devices = map(lambda x: int(x, 2), f.readline().strip().split(' '))
	print 'Case #{0}: {1}'.format(i+1, solve(n, l, outlets, devices))