T = input()

for case in range(1, T + 1):
	N, L = map(int, raw_input().split())
	start = [int(x, 2) for x in raw_input().split()]
	end = sorted([int(x, 2) for x in raw_input().split()])

	least = 1000
	for s in start:
		for t in end:
			# print bin(s), bin(t), bin(s ^ t)
			flip = s ^ t
			arr = sorted(x ^ flip for x in start)
			if arr == end:
				least = min(least, len([x for x in str(bin(flip)) if x == '1']))

	print "Case #%d:" % case, least if least != 1000 else 'NOT POSSIBLE'