import collections
import functools

class memoized(object):
	'''Decorator. Caches a function's return value each time it is called.
	If called later with the same arguments, the cached value is returned
	(not reevaluated).
	'''
	def __init__(self, func):
		self.func = func
		self.cache = {}
	def __call__(self, *args):
		if not isinstance(args, collections.Hashable):
			
			
			return self.func(*args)
		if args in self.cache:
			return self.cache[args]
		else:
			value = self.func(*args)
			self.cache[args] = value
			return value
	def __repr__(self):
		'''Return the function's docstring.'''
		return self.func.__doc__
	def __get__(self, obj, objtype):
		'''Support instance methods.'''
		return functools.partial(self.__call__, obj)
		
import sys
from itertools import combinations

input = open(sys.argv[1], "r").readlines()#[1:]
output = open(sys.argv[2], "w")

def parse(lines):
	def inner_parse():
		line = (yield None)
		n = int(line[0])-1
		while True:
			edges = []
			for i in range(n):
				line = (yield None)
				edges.append([int(line[0])-1, int(line[1])-1])
			nodes = [[] for i in range(n+1)]
			for edge in edges:
				nodes[edge[0]].append(edge[1])
				nodes[edge[1]].append(edge[0])
			nodes = tuple([tuple(links) for links in nodes])
			
			line = (yield nodes)
			n = int(line[0])-1
		
	parser = inner_parse()
	next(parser)
	for raw_line in lines:
		line = raw_line.strip().split(" ")
		result = parser.send(line)
		if not result is None:
			yield result

def expand(parent, current, tree):
	return filter(lambda x: not x == parent and not x == current, tree[current])

@memoized
def size(parent, current, tree):
	sum = 1
	for child in expand(parent, current, tree):
		sum += size(current, child, tree)
	return sum

@memoized
def binarize(parent, current, tree):
	children = set(expand(parent, current, tree))
	if len(children) == 0:
		return 0
	elif len(children) == 1:
		return size(current, list(children)[0], tree)
	elif len(children) == 2:
		sum = 0
		for child in children:
			sum += binarize(current, child, tree)
		return sum
	else:
		possibilities = []
		for selecteds in combinations(children, 2):
			removeds = children.difference(selecteds)
			removal_cost = 0
			for removed in removeds:
				removal_cost += size(current, removed, tree)
			binarize_cost = 0
			for selected in selecteds:
				binarize_cost += binarize(current, selected, tree)
			possibilities.append(removal_cost+binarize_cost)
		return min(possibilities)
	
def solve(nodes):
	return min([binarize(None, i, nodes) for i in range(len(nodes))])
		
for (i, nodes) in enumerate(parse(input[1:])):
	#import pdb; pdb.set_trace()
	result = solve(nodes)
	print("Case #" + str(i+1) + ": " + str(result))
	output.write("Case #" + str(i+1) + ": " + str(result) + "\n")