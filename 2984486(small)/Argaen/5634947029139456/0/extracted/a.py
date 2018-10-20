#encoding: utf-8

import itertools

t = int(raw_input())

for case in range(t):
	line = raw_input().split()
	n = int(line[0])
	l = int(line[1])

	line = raw_input().split()
	line.sort()
	outlets = []
	for o in line:
		ou = []
		for b in o:
			if b == '0':
				ou.append(False)
			else:
				ou.append(True)
		outlets.append(ou)

	line = raw_input().split()
	line.sort()
	devices = []
	for o in line:
		ou = []
		for b in o:
			if b == '0':
				ou.append(False)
			else:
				ou.append(True)
		devices.append(ou)

	#print devices
	#print outlets

	min = l + 1
	permutations = ["".join(seq) for seq in itertools.product("01", repeat=l)]

	for p in permutations:
		flips = p.count('1')
		if flips > min:
			continue
		for b in range(l):
			if p[b] == '1':
				for i in range(n):
					outlets[i][b] = not outlets[i][b]

		outlets.sort()
		#print outlets
		if outlets == devices:
			min = flips
		for b in range(l):
			if p[b] == '1':
				for i in range(n):
					outlets[i][b] = not outlets[i][b]

	if min == l + 1:
		print 'Case #'+str(case+1)+': NOT POSSIBLE'
	else:
		print 'Case #'+str(case+1)+': '+str(min)
