
### PRECOMPUTE BAD PERMUTATIONS

N = 1000

BAD_PERMS = set()
for n in xrange(1, N):
	seed = range(1, n+1)
	seed.append(0)
	
	if len(seed) == N:
		BAD_PERMS.add(tuple(seed))
	
	# swap last 2 digits
	temp = seed[-1]
	seed[-1] = seed[-2]
	seed[-2] = temp
	if len(seed) == N:
		BAD_PERMS.add(tuple(seed))
		
	# keeping add
	n = len(seed)
	while len(seed) < N:
		seed.insert(-1, n)
		n += 1
	BAD_PERMS.add(tuple(seed))


### MAIN PROGRAM ###

input_filename  = "C-small-attempt1.in"
output_filename = "C-small-ans1.txt"

f = open(input_filename , "r")
g = open(output_filename, "w")

number_of_cases = int(f.readline())

case_cnt = 0
while case_cnt < number_of_cases:
	
	N = int(f.readline())
	perm_to_test = f.readline().strip().split(" ")
	perm_to_test = [int(x) for x in perm_to_test]
	perm_to_test = tuple(perm_to_test)
	
	if perm_to_test in BAD_PERMS:
		answer = "BAD"
	else:
		answer = "GOOD"


	# output to screen & file
	print   "Case #" + str(case_cnt+1) + ": " + answer
	g.write("Case #" + str(case_cnt+1) + ": " + answer + "\n")
	
	# move on to the next case
	case_cnt += 1

f.close()
g.close()

