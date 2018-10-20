import sys
from itertools import combinations, chain

def main(input_file):
	number_of_cases = int(input_file.readline().strip("\n"))
	for case_number in xrange(1, number_of_cases + 1):
		print "Case #%d: %s" % (case_number, case(input_file, case_number))
#		if case_number >= 10:
#			break

def case(input_file, case_number):
#	print "###CASE_NUMBER: %d###" % (case_number, )
	n, l = [int(value) for value in input_file.readline().strip("\n").split(" ")]
	initial = [[int(c) for c in conf] for conf in input_file.readline().strip("\n").split(" ")]
	desired = [[int(c) for c in conf] for conf in input_file.readline().strip("\n").split(" ")]
	desired.sort()
	
	initial_data, desired_data = bla(initial, desired, n, l)
	changes = 0
	changeables = []
	for i in xrange(l):
		if initial_data[i] == desired_data[i]:
			if initial_data[i][0] == initial_data[i][1]:
				changeables.append(i)
			continue
		elif list(reversed(initial_data[i])) == desired_data[i]:
			switch(initial, i)
			changes += 1
			continue		
		return "NOT POSSIBLE"

#	if case_number == 10:
#		from pdb import set_trace; set_trace()
	works, new_changes = check(initial, desired, changeables)
	if works:
		return "%d" % (changes + new_changes, )
	return "NOT POSSIBLE"

def check(initial, desired, changeables):
	for subset in all_list_subsets(changeables):
#		if subset == [5]:
#			from pdb import set_trace; set_trace()
		if check_subset(initial, desired, subset):
			return True, len(subset)
	return False, 0

def check_subset(initial, desired, subset):
	for i in subset:
		switch(initial, i)
	initial.sort()
	if initial == desired:
		return True
	for i in subset:
		switch(initial, i)
	return False

def check2(initial, desired, l, i):
	if i == l:
		initial.sort()
		if desired == initial:
			return True, 0
		return False, 0
	else:
		works, changes = check2(initial, desired, l, i + 1)
		if works:
			return True, changes
		else:
			switch(initial, i)
			works, changes = check2(initial, desired, l, i + 1)
			if works:
				return True, changes + 1
			else:
				switch(initial, i)
				return False, changes
			

def switch(curr_list, i):
	for d in curr_list:
		d[i] = 1 - d[i]

def all_list_subsets(full_list):
	als = allsubsets(len(full_list))
	for s in als:
		curr_s = []
		for i in s:
			curr_s.append(full_list[i])
		yield curr_s

def allsubsets(n):
	return list(chain(*[combinations(range(n), ni) for ni in range(n+1)]))

def bla(initial, desired, n, l):
	initial_data = [[0, 0] for i in xrange(l)]
	desired_data = [[0, 0] for i in xrange(l)]

	for i in xrange(n):
		for j in xrange(l):
			initial_data[j][int(initial[i][j])] += 1
			desired_data[j][int(desired[i][j])] += 1
	
	return initial_data, desired_data

if __name__ == '__main__':
	main(open(sys.argv[1]))


