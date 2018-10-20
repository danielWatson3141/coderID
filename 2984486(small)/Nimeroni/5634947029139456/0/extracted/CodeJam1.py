# -*-coding:Utf-8 -*

import sys
import copy

# Parse args
with open("A-small-attempt0.in") as f:
	arg = f.readlines()

T = int(arg[0])
N = [0 for i in range(T)]
L = [0 for i in range(T)]
matrixInput = [0 for i in range(T)]
matrixOutput = [0 for i in range(T)]
for ct in range(T):
	line1 = arg[ct*3+1].split()
	N[ct] = int(line1[0])
	L[ct] = int(line1[1])
	matrixInput[ct] = arg[ct*3+2].split()
	matrixOutput[ct] = arg[ct*3+3].split()

f = open('A-small.out','w')

# Transform string list into int
def checksum(state, L):
	checksum = 0
	state = state[::-1] #Reverse for easy printing
	for e in range(len(state)):
		checksum += int(state[e]) * (10**(e*L))
	return checksum

# Compute each case
for ct in range(int(T)):
	# Print data in memory
##	print "case number " + str(ct)
##	print "N: " + str(N[ct]) + " L: " + str(L[ct])
##	print "matrixInput: "
##	print matrixInput[ct]
##	print "matrixOutput: "
##	print matrixOutput[ct]

	# Build graph
	graph = dict()

	# Build a checksum for the matrix state
	check = checksum(matrixInput[ct], L[ct])

	# Initialise Graph
	graph[check] = matrixInput[ct]

	# Build the solution
	solution = map(int, matrixOutput[ct])
	solution.sort()

	# Explore graph
	pile = []
	pile.append(check)
	pile.append(-1)
	solutionDist = 0
	
	while(len(pile) != 0):
		node = pile.pop(0)

		# Distance check
		if(node == -1):
			if(len(pile) == 0):
				break
			pile.append(-1)
			solutionDist +=1
			continue
		
		string = graph[node]

		# Check end condition
		switch = map(int, graph[node])
		switch.sort()
		if(solution == switch):
			break

		# Build nearby node
		for i in range(L[ct]):
			# Nearby nodes are ones with one switch changed
			newNode = copy.deepcopy(string)
			for j in range(len(newNode)):
				e = list(newNode[j])
				e[i] = '1' if e[i] == '0' else '0'
				newNode[j] = "".join(e)
			check = checksum(newNode, L[ct])
			
			# New node found
			if check not in graph :
				graph[check] = newNode
				pile.append(check)

	if(len(pile) != 0):
		f.write ("Case #" + str(ct+1) + ": " + str(solutionDist) + "\n")
	else:
		f.write ("Case #" + str(ct+1) + ": " + "NOT POSSIBLE"  + "\n")
			
