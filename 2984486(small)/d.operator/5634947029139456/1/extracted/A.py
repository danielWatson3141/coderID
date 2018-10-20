def getInt(s):
	x = 0
	for dig in s:
		x <<= 1
		x += int(dig)
	return x

def solve_case(s_in, s_req):
	A = map(getInt, s_in)
	B = map(getInt, s_req)
	A.sort()
	B.sort()
	A_set = set(A)
	
	minimumLng = 0
	truly_possible = False
	for a in A:
		cur = B[0]^a				# outlet a will charge device B[0]
		possible = True
		for b in B:
			if b^cur not in A_set:	# under this set of switch-flips, nothing can charge device b
				possible = False
				break
		if(possible):
			nrSwitched = bin(cur).count('1')
			if not(truly_possible) or nrSwitched < minimumLng:
				truly_possible = True
				minimumLng = nrSwitched
	
	if truly_possible:
		return minimumLng
	else:
		return "NOT POSSIBLE"


def solve(in_name, out_name):
	fin = open(in_name, 'r');
	L = [x.strip().split() for x in fin.readlines()]
	fin.close()
	
	casenr = 1
	res = []
	for i in xrange(1, len(L),3):
		switchstr = solve_case(L[i+1], L[i+2])
		res.append('Case #' + str(casenr) + ': ' + str(switchstr) + '\n')
		casenr = casenr + 1
	
	fout = open(out_name, 'w')
	fout.writelines(res)
	fout.close()
	
	return
	
#solve('A-small-attempt2.in', 'A-small-attempt2.out')
solve('A-large.in', 'A-large.out')

#solve('A-test.in', 'A-test.out')
