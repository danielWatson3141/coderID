import sys

T = int(sys.stdin.readline())
for t in range(1, T+1):
	N, L = [int(x) for x in sys.stdin.readline().split()]
	outlets = [long(x, 2) for x in sys.stdin.readline().split()]
	devices = [long(x, 2) for x in sys.stdin.readline().split()]
	devices.sort()

	candidates = None
	result = -1

	for y in range(L+1):
		for outlet in outlets:
			matches = [x ^ outlet for x in devices]
			matches = [x for x in matches if bin(x).count("1") == y]
			if len(matches) == 0:
				candidates = None
				break
			if candidates:
				candidates = candidates & set(matches)
			else:
				candidates = set(matches)

		if candidates:
			for candidate in candidates:
				noutlets = [x ^ candidate for x in outlets]
				noutlets.sort()
				if devices == noutlets:
					result = y
					break

		if result >= 0:
			break

	if result >= 0:
		print "Case #%d: %d" % (t, y)
	else:
		print "Case #%d: NOT POSSIBLE" % t

