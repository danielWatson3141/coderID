import copy
import itertools

def is_matching(switches, outlets, devices, length):
	outlets_list = []
	for outlet in outlets:
		outlet_list = list(outlet)
		for i in range(length):
			if switches[i] == 1: outlet_list[i] = '1' if outlet_list[i] == '0' else '0'
		outlets_list.append(outlet_list)

	for device in devices:
		matching = False
		for outlet in outlets_list:
			if device == ''.join(outlet):
				matching = True
				break
		if not matching:
			return False
	return True

def calculate_switches_tree(switches):
	num_trues = 0
	for switch in switches:
		if type(switch) is bool:
			num_trues += 1

	tree = []
	for option in itertools.product('01', repeat = num_trues):
		true_number = 0
		c = copy.copy(switches)
		for i in range(len(c)):
			if type(c[i]) is bool:
				c[i] = 1 if option[true_number] == '1' else 0
				true_number += 1
		tree.append(c)

	return tree

def calculate(outlets, devices, n, length):
	switches = [None] * length
	for position in range(length):
		outlet_one_count = 0
		device_one_count = 0
		for outlet in outlets:
			if outlet[position] == '1': outlet_one_count += 1
		for device in devices:
			if device[position] == '1': device_one_count += 1

		i = position
		switches[i] = None
		if device_one_count == outlet_one_count:
			switches[i] = 0
		
		if device_one_count == n - outlet_one_count:
			if switches[i] == 0:
				switches[i] = True
			else:
				switches[i] = 1

		if switches[i] is None: return None

	switches_tree = calculate_switches_tree([True] * length)

	min_count = None
	for switches_o in switches_tree:
		if is_matching(switches_o, outlets, devices, length):
			count = 0
			for switch in switches_o:
				if switch == 1:
					count += 1
			if min_count is None or count < min_count:
				min_count = count
	return min_count


n = int(input())
for i in range(n):
	m, l = [int(x) for x in input().split(' ')]
	outlets = input().split(' ')
	devices = input().split(' ')
	num_switches = calculate(outlets, devices, m, l)
	if num_switches is not None: print('Case #%s: %s' % (i + 1, num_switches))
	else: print('Case #%s: NOT POSSIBLE' % (i + 1))