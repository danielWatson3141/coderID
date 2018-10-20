# Gonzalo Ciruelos
# Problem A

import itertools
import copy


def change_bit(code, position):
	copied = copy.deepcopy(code)
	if code[position] == '0':
		copied[position] = '1'
	else:
		copied[position] = '0'
	return copied


def solve(bits, initial, wanted):
	wanted = sorted(wanted)
	if sorted(initial) == wanted:
		return 0
		
	else:
		initial = map(list, initial)
		wanted  = map(list, wanted)
		for number_of_changes in range(1, int(bits)+1):
			for case in itertools.combinations(range(int(bits)), number_of_changes):
				changed_initial = initial
				for index in case:
					changed_initial = map(lambda x: change_bit(x, index), changed_initial)
				
				if sorted(changed_initial) == wanted:
					return number_of_changes


f = open('A-small-attempt0.in', 'r')
case_no = 1
for game in range(int(f.readline())):

	outlets, bits = tuple(f.readline().split(' '))
	initial = f.readline()[:-1].split(' ')
	wanted  = f.readline()[:-1].split(' ')
	
	#print str(outlets)+' '+str(bits)+str(initial)+str(wanted)
	
	
	result = solve(bits, initial, wanted)
	if result == None: result = 'NOT POSSIBLE'
	
	print 'Case #'+str(case_no)+': '+str(result)
	
	case_no+=1
