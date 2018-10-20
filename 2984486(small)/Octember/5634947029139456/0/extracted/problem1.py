fileIn = open('test1.in', 'r')
fileOut = open('x1.out', 'w')

import copy

T = int(fileIn.readline().strip())

def flip(c):
	if c == '1':
		return '0'
	else:
		return '1'

def switch(dict, index):
	for key in dict:
		words = dict[key]
		new  = []
		for word in words:
			new.append(word[:index] + flip(word[index]) + word[index + 1:])
		dict[key] = new

def s():
	N, L = (int(x) for x in fileIn.readline().strip().split())
	flow = fileIn.readline().strip().split()
	given = fileIn.readline().strip().split()
	d = {}
	for device in given:
		for outlet in flow:
			d[device] = flow[::]
	return solve(d, given, 0, L)


def solve(d, given, index, L):
	if index == L:
		return 0

	unswitched_fail, switched_fail = False, False
	removed_unswitched = {}
	
	for device in given:
		removed_unswitched[device] = []
		for outlet in d[device]:
			if device[index] != outlet[index]:
				removed_unswitched[device].append(outlet)

		if len(removed_unswitched[device]) == len(d[device]):
			unswitched_fail = True
			break

	switched_d = copy.deepcopy(d)
	switch(switched_d, index)
	removed_switched = {}
	for device in given:
		removed_switched[device] = []
		for outlet in switched_d[device]:
			if device[index] != outlet[index]:
				removed_switched[device].append(outlet)

		if len(removed_switched[device]) == len(d[device]):
			switched_fail = True
			break
	if switched_fail and unswitched_fail:
		return "NOT POSSIBLE"
	elif switched_fail:
		for device in removed_unswitched:
			for remove in removed_unswitched[device]:
				d[device].remove(remove)
		s = solve(d, given, index + 1,L)
		if s == "NOT POSSIBLE":
			return s
		return s
	elif unswitched_fail:
		for device in removed_switched:
			for remove in removed_switched[device]:
				switched_d[device].remove(remove)
		s = solve(switched_d, given, index + 1,L)
		if s == "NOT POSSIBLE":
			return s
		return s + 1
	else:
		for device in removed_unswitched:
			for remove in removed_unswitched[device]:
				d[device].remove(remove)
		for device in removed_switched:
			for remove in removed_switched[device]:
				switched_d[device].remove(remove)
		un, sw  = solve(d, given, index + 1,L) , solve(switched_d, given, index + 1,L)
		if sw == "NOT POSSIBLE":
			return un
		else:
			if un == "NOT POSSIBLE":
				return sw + 1
			else:
				return min(un, sw + 1)

for case in range(1, T+1):
	x = s()
	# 
	if x == -1:
		x = "NOT POSSIBLE"
	fileOut.write("Case #{}: {}\n".format(case, x))

