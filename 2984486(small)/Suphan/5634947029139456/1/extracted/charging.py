f = open('A-large.in')
fw = open('A-large-output.txt', 'w')

cases = int(f.readline())
for case in range(cases):
	print case
	N, L = map(int, f.readline().split())
	e_flow = f.readline().split()
	devices = f.readline().split()
	possible = True
	flip = 0
	solution = [[''] * N]
	
	for i in range(L):
		one_count_1 = 0
		one_count_2 = 0
		for j in range(N):
			one_count_1 += int(e_flow[j][i])
			one_count_2 += int(devices[j][i])
		if one_count_1 != one_count_2 and one_count_1 != N - one_count_2:
			possible = False
			break
		solution_2 = []
		for sol in solution:
			if one_count_1 == one_count_2:
				sol_2 = []
				for j in range(N):
					sol_2.append(sol[j] + e_flow[j][i])
				solution_2.append(sol_2)
			if one_count_1 == N - one_count_2:
				sol_2 = []
				for j in range(N):
					sol_2.append(sol[j] + str(1 - int(e_flow[j][i])))
				solution_2.append(sol_2)
		solution = solution_2

		de = []
		for j in range(N):
			de.append(devices[j][:i+1])
		de.sort()
		solution_3 = []
		for sol in solution:
			sol_3 = list(sol)
			sol_3.sort()
			if de == sol_3:
				solution_3.append(sol)
		solution = solution_3
		#print solution

	if not possible or len(solution) == 0:
		ans = 'NOT POSSIBLE'
	else:
		min_count = 100 * L
		for sol in solution:
			this_count = 0
			for i in range(L):
				if e_flow[0][i] != sol[0][i]:
					this_count += 1
			if this_count < min_count:
				min_count = this_count
		ans = min_count
	fw.write('Case #' + str(case + 1) + ': ' + str(ans) + '\n')

fw.close()
f.close()
