import random

def solve(inp):
	l = [a == b for a,b in enumerate(inp)]
	res = sum([1 for i in l if i])
	return "GOOD" if res > 0 else "BAD"

number_cases = int(raw_input())
for i in xrange(number_cases):
	raw_input()
	data = [int(x) for x in raw_input().split(" ")]
	print "Case #{}: {}".format(i+1, solve(data))