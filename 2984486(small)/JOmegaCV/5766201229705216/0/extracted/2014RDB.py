'''
Created on Mar 11, 2014

@author: John Cornwell
'''
import operator,math,string,itertools,fractions,heapq,collections,re,array,bisect,random
from fractions import gcd
def lcm(a, b):
	return a * b / gcd(a, b)


# Called before solving any functions
def init(i_num, fc_in):
	return
	


# Parse next set of arguments
def parse_next(fc_in):
	n = int(fc_in.readline())
	edges = {}
	
	for i in range(1, n+1):
		edges[i] = []
	for i in range(n-1):
		a, b = map(int, fc_in.readline().split())
		edges[a].append(b)
		edges[b].append(a)
	
	return n, edges



# Solve individual instance
def solve(n, edges):
	print edges
	
	def num_nodes(cur, prev):
		tovisit = [x for x in edges[cur] if x != prev]
		return 1 + sum([num_nodes(x, cur) for x in tovisit])
	
	def min_tree(cur, prev):
		tovisit = [x for x in edges[cur] if x != prev]
		
		if len(tovisit) == 0:
			return 0, 1
		
		if len(tovisit) == 1:
			tree, nodes = min_tree(tovisit[0], cur)
			return nodes, nodes + 1
		
		# two more more children
		keep1 = 0
		keep2 = 0
		tot_nodes = 0
		for n in tovisit:
			tree, nodes = min_tree(n, cur)
			tot_nodes += nodes
			diff = tree - nodes
			keep2 = min(diff, keep2)
			if keep2 < keep1:
				keep1, keep2 = keep2, keep1
		return (tot_nodes + keep1 + keep2), tot_nodes + 1
	
	ret = 10e100
	for i in range(1, n+1):
		ret = min(ret, min_tree(i, -1)[0])
		
	return ret



def _run_main():
	# Config
	s_let = 'B'
	s_run = 1
	
	if s_run == 0:
		fc_in = open('infile.in', 'r')
	elif s_run == 1:
		fc_in = open('Z:\Users\John Cornwell\Downloads\%s-small-attempt0.in' % s_let, 'r')
	else:
		fc_in = open('Z:\Users\John Cornwell\Downloads\%s-large.in' % s_let, 'r')
	fc_out = open('out.txt', 'w')
	
	i_num = int(fc_in.readline())
	init(i_num, fc_in)
	
	# Pare and solve test cases
	for i in range(1, i_num+1):
		args = parse_next(fc_in)
		ret = solve(*args)
		s_line = 'Case #%i: %s' % (i, str(ret))
		print s_line
		fc_out.write(s_line + '\n')
		
		
if __name__ == '__main__':
	_run_main()