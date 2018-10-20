import sys
from math import log, pow
#from itertools import combinations

input = open(sys.argv[1], "r").readlines()#[1:]
output = open(sys.argv[2], "w")

def parse(lines):
	def inner_parse():
		line = (yield None)
		n = int(line[0])
		while True:
			line = (yield None)
			perm = list(map(int, line))
			line = (yield perm)
			n = int(line[0])
		
	parser = inner_parse()
	next(parser)
	for raw_line in lines:
		line = raw_line.strip().split(" ")
		result = parser.send(line)
		if not result is None:
			yield result
			

def runs(input):
	output = 0
	current = 0
	for (last, item) in zip(input[:-1], input[1:]):
		if item == last + 1:
			current = 1
		else:
			if current == 1:
				output += 1
				current = 0
	
	if current == 1:
		output += 1
	
	return output
	
def in_order(input):
	c = 0
	for (index, num) in enumerate(input):
		if index == num:
			c += 1
			
	return c
			
def bad_prob(input):
	if in_order(input) > 0:
		return True
	else:
		return False

def solve(perm):
	result = bad_prob(perm)
	if result:
		return "BAD"
	else:
		return "GOOD"
		
outputs = []
for (i, perm) in enumerate(parse(input[1:])):
	#import pdb; pdb.set_trace()
	result = solve(perm)
	print("Case #" + str(i+1) + ": " + str(result))
	output.write("Case #" + str(i+1) + ": " + str(result) + "\n")
	outputs.append(result)
	
print("Goods: " + str(len(list(filter(lambda x: x == "GOOD", outputs)))))
print("Bads: " + str(len(list(filter(lambda x : x == "BAD", outputs)))))