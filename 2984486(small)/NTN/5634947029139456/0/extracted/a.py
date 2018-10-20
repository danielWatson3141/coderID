
def ones(x):
	c = 0
	for i in x:
		if i == "1":
			c += 1
	return c

def check_solution(solution, initial, needed):
	result = []
	for plug in initial:
		new = list(plug)
		for char in range(len(plug)):
			if (solution[char] == "1" or new[char] == "1") and not (solution[char] == "1" and new[char] == "1"):
				new[char] = "1"
			else:
				new[char] = "0"
		result.append("".join(new))

	if sorted(result) == needed:
		return True
	return False

def solve_case():
	n, l = input().split()
	n = int(n)
	l = int(l)

	initial = input().split()
	needed = input().split()
	needed.sort()

	num_initial = [ones(i) for i in zip(*initial)]
	num_needed = [ones(i) for i in zip(*needed)]

	FLIP = '1'
	NO_FLIP = '0'

	solution = [FLIP for _ in range(l)]
	unknown = []

	for i in range(l):
		if num_initial[i] == num_needed[i] and n - num_initial[i] == num_needed[i]:
			solution[i] = NO_FLIP
			unknown.append(i)
		elif num_initial[i] == num_needed[i]:
			solution[i] = NO_FLIP
		elif n - num_initial[i] == num_needed[i]:
			solution[i] = FLIP
		else:
			print("NOT POSSIBLE")
			return

	best = 1000000

	ii = 0
	while 1:
		end = bin(ii)[2:]
		if end == "0":
			end = ""
		if len(unknown) - len(end) < 0:
			break
		it = "0" * (len(unknown) - len(end)) + end
		for i in range(len(unknown)):
			solution[unknown[i]] = it[i]

		if check_solution(solution, initial, needed):
			best = min(ones(solution), best)

		ii += 1

	if best == 1000000:
		print("NOT POSSIBLE")
		return

	print(best)

for i in range(int(input())):
	print("Case #%i: " % (i+1), end="")
	solve_case()