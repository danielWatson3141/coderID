import sys
input_file = open(sys.argv[1], 'r')
output_file = open(sys.argv[2], 'w')

cases = int(input_file.readline().strip())
for case in range(cases):
	n, l = map(int, input_file.readline().strip().split())
	initial_lst = [int(i, 2) for i in input_file.readline().strip().split()]
	final_set = set([int(i, 2) for i in input_file.readline().strip().split()])
	flag = 0
	for x in xrange(2 ** l):
		test_set = set([i ^ x for i in initial_lst])
		if test_set == final_set:
			flag = 1
			mark = bin(x)[2:].count('1')
			break
	if flag == 0:
		output_file.write('Case #%d: NOT POSSIBLE\n' % (case + 1))
	else:
		output_file.write('Case #%d: %d\n' % (case + 1, mark))
input_file.close()
output_file.close()

