import sys
import itertools

def checkLists(list1, list2, n):
	current = -1
	for _n in xrange(n):
		if list1[_n] ^ list2[_n] != current and current != -1:
			return -1
		current = list1[_n] ^ list2[_n]
	num_switches = 0
	while current > 0:
		if current & 1:
			num_switches = num_switches + 1
		current = current >> 1
	return num_switches

if __name__ == "__main__":
	f = sys.stdin
	if len(sys.argv) >= 2:
		fn = sys.argv[1]
		if fn != '-':
			f = open(fn)

	t = int(f.readline())
	for _t in xrange(t):
		line_contents = f.readline().split(' ')
		n = int(line_contents[0])
		l = int(line_contents[1])
		outlets = f.readline().strip().split(' ')
		devices = f.readline().strip().split(' ')

		outlets = [int(outlet, 2) for outlet in outlets]
		devices = [int(device, 2) for device in devices]

		possibilities = list()

		outlet_permutations = itertools.permutations(outlets)
		for permutation in outlet_permutations:
			num_switches = checkLists(permutation, devices, n)
			if num_switches > -1:
				possibilities.append(num_switches)

		if len(possibilities) == 0:
			print "Case #%d: NOT POSSIBLE" % (_t + 1)
		else:
			print "Case #%d: %d" % (_t + 1, min(possibilities))
