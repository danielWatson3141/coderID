import sys
import networkx as nx
from pprint import pprint

def write(st):
    sys.stdout.write(st)
def writecase(i):
    if i == 0:
        print 'i is 0!!!!!!!!!!!!!!!!!'
    write("Case #%d: " % i)


def prune(G, from_node, start):
#	print 'inspecting', start
	num_children = len(G[start])
	if from_node != None:
		num_children -= 1

	if num_children == 0:
#		print 'single node, returning 0'
		return 0

	# prune below
#	print 'has', num_children, 'children'

	# remove all but two highest count children
	prune_counts = {}
	for node in G[start]:
		if node == from_node:
			continue
#		print 'pruning below in node', node
		prune_counts[node] = prune(G, start, node)
	n = sum(prune_counts.values())
	if num_children == 1:
		n += 1
	elif num_children != 2:
		n += num_children-2
#	print 'all pruned for node',start,', returning', n
	return n

f = open(sys.argv[1])
T = int(f.readline())

for t in range(1, T+1):
	line = f.readline()
	parts = line.split()
	N = int(parts[0])
    
	G = nx.Graph()
	while True:
		line = f.readline()
		parts = line.split()
		if len(parts) != 2:
			f.seek(-len(line),1)
			break
		x = parts[0]
		y = parts[1]
		G.add_path([x, y])
	best = 100000
	for node in G:
		n = prune(G, None, node)
#		print 'pruned = ', n
		if n < best:
			best = n
	writecase(t)
	write('%d\n' % best)

f.close()