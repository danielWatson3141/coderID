from itertools import permutations

DEVICES = []

def is_conf_pass(outlets):
	set_diff = list(set(outlets) - DEVICES)

	return len(set_diff) == 0

def flip_switches(outlet, switches):
	lst = map(int, list(outlet))
	
	for i, switch in enumerate(switches):
		if switch == 1:
			lst[i] =  0 if lst[i] == 1 else 1
	
	return "".join(map(str, lst))

def solve(outlets, L):
	if is_conf_pass(outlets):
		return 0
		
	switches_to_flip = 1
	while switches_to_flip < L:
		base = [1] * switches_to_flip + [0] * (L - switches_to_flip)
	
		checks = list(set(permutations(base)))
		
		for to_check in checks:
			test_outlets = map(lambda x: flip_switches(x, to_check), outlets)

			if is_conf_pass(test_outlets):
				return switches_to_flip 
		
		switches_to_flip += 1
		
	return "NOT POSSIBLE"

def string_to_vect(value):
	return map(int, value.split(" "))

if __name__ == "__main__":
	test_cases = input()
     
	for case in xrange(1, test_cases + 1):
		N, L = string_to_vect(raw_input())
		outlets = raw_input().split(" ")
		DEVICES = set(raw_input().split(" "))
		
		print "Case #%i: %s" % (case, solve(outlets, L))
