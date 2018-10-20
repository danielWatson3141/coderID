import sys

input = open(sys.argv[1], "r").readlines()#[1:]
output = open(sys.argv[2], "w")

def parse(lines):
	def inner_parse():
		line = (yield None)
		while True:
			line = (yield None)
			outlets = [[bool(int(socket)) for socket in list(outlet)] for outlet in line]
			line = (yield None)
			requirements = [[bool(int(socket)) for socket in list(outlet)] for outlet in line]
			line = (yield (outlets, requirements))
		
	parser = inner_parse()
	next(parser)
	for raw_line in lines:
		line = raw_line.strip().split(" ")
		result = parser.send(line)
		if not result is None:
			yield result

def difference(input, compare):
	output = []
	for (i, (a, b)) in enumerate(zip(input, compare)):
		if not a == b:
			output.append(i)

	return tuple(output)
	
def solve(outlets, requirements):
	# generate substrings ...
	constraints = [set([difference(outlet, requirement) for requirement in requirements]) for outlet in outlets]
	tally = constraints[0]
	for constraint in constraints[1:]:
		tally = tally.intersection(constraint)
	return min(list(map(len, tally))) if len(tally) > 0 else "NOT POSSIBLE"
		
for (i, (outlets, requirements)) in enumerate(parse(input[1:])):
	#import pdb; pdb.set_trace()
	result = solve(outlets, requirements)
	print("Case #" + str(i+1) + ": " + str(result))
	output.write("Case #" + str(i+1) + ": " + str(result) + "\n")