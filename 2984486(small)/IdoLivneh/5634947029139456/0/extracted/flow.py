import sys
import time
import itertools #use combinations!
import random

def iterate_cases_1lpc(filepath):	#1lpc = 1 line per case
	with file(filepath, 'rb') as f_in:
		for line_index, line in enumerate(f_in):
			if line_index == 0: #T
				continue
			yield line_index, line.strip().split(' ')

def iterate_cases_nlpc(filepath, n):	#1lpc = n line per case
	with file(filepath, 'rb') as f_in:
		case_counter = 1
		case = []
		for line_index, line in enumerate(f_in):
			if line_index == 0: #T
				continue
			case.append(line.strip().split(' '))
			if not line_index % n:
				yield case_counter, case
				case_counter += 1
				case = []

def iterate_cases_glpc(filepath):		#glpc - given lines per case
	with file(filepath, 'rb') as f_in:
		case_counter = 0
		new_case = True
		for line_index, line in enumerate(f_in):
			if line_index == 0: #T
				continue
			if new_case:
				new_case = False
				case_counter += 1
				case = []
				assert len(line.strip().split(' ')) == 1
				lines_left = int(line.strip())
				if not lines_left:
					new_case = True
					yield case_counter, case
				continue
			if lines_left:
				lines_left -= 1
				case.append(line.strip().split(' '))
			if not lines_left:
				new_case = True
				yield case_counter, case
			
def part_of_list_to_int(array, flags):
	assert len(array) == len(flags)
	output = []
	for index, elem in enumerate(array):
		if flags[index]:
			output.append(int(elem))
		else:
			output.append(elem)
	return output

def list_to_int(array):
	return part_of_list_to_int(array, [True] * len(array))

def part_of_list_to_float(array, flags):
	assert len(array) == len(flags)
	output = []
	for index, elem in enumerate(array):
		if flags[index]:
			output.append(float(elem))
		else:
			output.append(elem)
	return output

def list_to_float(array):
	return part_of_list_to_float(array, [True] * len(array))

def get_max_array_on_index(array, index):
	elem_len = len(array[0])
	assert index < elem_len
	for elem in array:
		assert elem_len == len(elem)
	max_sub = array[0][index]
	max_elem = array[0]
	for elem in array:
		if elem[index] > max_sub:
			max_sub = elem[index]
			max_elem = elem
	return max_elem

def list_index_in_sorted_with_position(a_list, value, pos):
	list_len = len(a_list)
	if list_len == 1:
		if a_list[0] == value:
			return pos
		return -1
	if a_list[list_len/2] > value:
		return list_index_in_sorted_with_position(a_list[:(list_len/2)], value, pos)
	else:
		return list_index_in_sorted_with_position(a_list[(list_len/2):], value, pos + (list_len/2))
	
def list_index_in_sorted_list(a_list, value):
	return list_index_in_sorted_with_position(a_list, value, 0)

def copy_list(list):
	res = []
	for elem in list:
		res.append(elem)
	return res	

############################################################
#### add solution here 									####
#### don't forget to change data from str to int/float  ####
############################################################

def get_all_indexes(A, a):
	res = []
	new_A = copy_list(A)
	while True:
		try:
			res.append(new_A.index(a))
			new_A.remove(a)
		except Exception:
			break
	return res

def do_rec(num_to_select, vects, rows_selected, N):
	if num_to_select == N:
		return True
	for i in xrange(len(vects)):
		if num_to_select in vects[i]:
			if i not in rows_selected:
				new_rows_selected = copy_list(rows_selected)
				new_rows_selected.append(i)
				return do_rec(num_to_select + 1, vects, new_rows_selected, N)
	return False
	
		
	
def is_good_match(vects, N):
	rows_selected = []
	return do_rec(0, vects, rows_selected, N)
	
def solve(N, L, flow, req):
	res = None
	
	A = [[[0 for _ in xrange(L)] for __ in xrange(N)] for ___ in xrange(N)]
	for i in xrange(N):
		for j in xrange(N):
			for k in xrange(L):
				if req[i][k] != flow[j][k]:
					A[i][j][k] = 1
	
	#print A
	
	#create possible solutions - same vector
	poss = []
	for i in xrange(N):
		in_all = True
		for j in xrange(N):
			if A[0][i] not in A[j]:
					in_all = False
		if in_all:
			poss.append(A[0][i])
	print 'poss=',poss
	
	if not poss:
		return 'NOT POSSIBLE'
	
	#hatama
	final_poss = []
	for elem in poss:
		vects = []
		print '\t-->', elem
		for i in xrange(N):
			new_vect = get_all_indexes(A[i], elem)
			print '\t', new_vect
			vects.append(new_vect)
		if is_good_match(vects, N):
			final_poss.append(elem)
	
	if not final_poss:
		return 'NOT POSSIBLE'
	
	print 'final:', final_poss

	sizes = []
	for elem in final_poss:
		sizes.append(sum(elem))
	
	return str(min(sizes))
	
def calc_result(case):
	result = None
	
	N = list_to_int(case[0])[0]
	L = list_to_int(case[0])[1]
	flow = case[1]
	req = case[2]
	
	print N, L
	print flow
	print req
	
	result = solve(N, L, flow, req)
	
	#str_out = mat_to_str(result)
	#m = str_out.count('*')
	#assert (m==0 or m==M)
	#print str_out
	
	return result

def main(filepath):
	start_time = time.time()
	with file('output.txt', 'wb') as f_out:
		
		######################################
		#### select input iteration type: ####
		####	- iterate_cases_1lpc	  ####
		####	- iterate_cases_nlpc +n	  ####
		####	- iterate_cases_glpc	  ####
		######################################
		for case_index, case in iterate_cases_nlpc(filepath, 3):
			
			print "case #%d: time:%.02f" % (case_index, time.time() - start_time)
			result = calc_result(case)
			
			#######################
			#### format output ####
			#######################
			f_out.write("Case #%d: %s\n" % (case_index, result))
				
if __name__ == '__main__':
	main(sys.argv[1])
