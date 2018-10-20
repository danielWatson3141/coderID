# -*- coding: utf-8 *-*
from ContestSolver import ContestSolver


def num(ios, N):
	if N == 0:
		return 0
	
	ioszeros = [[[x[1:] for x in i if x[0] == '0'] for i in io] for io in ios]
	iosones = [[[x[1:] for x in i if x[0] == '1'] for i in io] for io in ios]
	
	found = False
	result = -1
	#print N, 0, ios
	#print N, ioszeros, '-', iosones
	if all([len(io[0]) == len(io[1]) for io in ioszeros]):
		#print N, 1#, ios
		#print ioszeros, iosones
		tmp = num(ioszeros + iosones, N-1)
		if tmp >= 0:
			found = True
			result = tmp
		#print N, tmp, result
	if all([len(ioszeros[i][0]) == len(iosones[i][1]) for i in range(len(ios))]):
		#print N, 2#, ios
		#print ioszeros, iosones
		tmp = num([[iosones[i][0], ioszeros[i][1]] for i in range(len(ioszeros))] + [[ioszeros[i][0], iosones[i][1]] for i in range(len(ioszeros))], N-1)
		if tmp >= 0:
			if found:
				result = min(result, tmp + 1)
			else:
				result = tmp + 1
				found = True
		#print N, tmp, result
	
	return result


def solver(case):
	#print "\n"
	L = int(case[0][1])
	inputs = case[1]
	outputs = case[2]
	ans = num([[inputs, outputs]], L)
	if ans == -1:
		return ["NOT POSSIBLE"]
	else:
		return [ans]


solution = ContestSolver(solver)
#solution.run("A-test", ints=False, test=True)
solution.run("A-small-attempt0", ints=False)
#solution.run("A-large", ints=False, watch=True)
