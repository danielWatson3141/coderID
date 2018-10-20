from collections import defaultdict

lines = open('B-small-attempt2.in', 'r').read().splitlines()
line = iter(lines)

numCases = int(line.next())

outputFile = open('B-small-attempt2.out', 'w')

def is_critical(g, v):
	if len(g[v]) == 2:
		return True
	else:
		return False	

def remove_vertex(g, v):
	v1, v2 = g[v]
	# print v, v1, v2
	# print g[v1]
	# print g[v2]
	g[v1].remove(v)
	g[v2].remove(v)

	g[v1].append(v2)
	g[v2].append(v1)
	g.pop(v, None)

for i in range(numCases):
	numEdges = int(line.next()) - 1
	# print numEdges

	g = defaultdict(list)
	
	for j in range(numEdges):

		(v1, v2) = map(lambda t: int(t), line.next().strip().split(" "))
		# print (v1, v2)

		g[v1].append(v2)
		g[v2].append(v1)

	# print g

	total_count = 0
	# print "***"

	critical_vertices_exist = True
	while critical_vertices_exist:
		critical_vertices_exist = False
		for vertex in g:
			if is_critical(g, vertex):
				critical_vertices_exist = True
				critical_vertex = vertex
				continue						

		if critical_vertices_exist:
			# print "Removing", critical_vertex
			remove_vertex(g, critical_vertex)
			# print g
			total_count += 1

	total_count = max(total_count - 1, 0)

	outputFile.write("Case #" + str(i + 1) + ": " + str(total_count) + "\n") 


