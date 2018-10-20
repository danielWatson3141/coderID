#!/usr/bin/env python3
import sys

def binstr2int(string):
	return int(string, 2)

def flip(initialflows, L):
	possibleflows = []
	for bitmask in range(2**L):
		flippedflows = []
		for flow in initialflows:
			flippedflow = flow ^ bitmask
			flippedflows.append(flippedflow)
		possibleflows.append(sorted(flippedflows))
	return possibleflows
			
argc = len(sys.argv)
filename = sys.argv[1]
if argc > 2:
	casenumbers = list(map(int, sys.argv[2:]))
file = open(filename)
T = int(file.readline().rstrip())
for case in range(1,T+1):
	if argc > 2 and not(case in casenumbers):
		continue
	N, L = list(map(int,file.readline().rstrip().split()))
	initialflows = list(map(binstr2int,file.readline().rstrip().split()))
	requiredflows = sorted(list(map(binstr2int,file.readline().rstrip().split())))
	possibleflows = flip(initialflows, L)
	if (requiredflows in possibleflows):
		possible = True
		index = possibleflows.index(requiredflows)
		flips = bin(index).count("1")
	else:
		possible = False
	print ("Case #", case, ": ", sep="", end="")
	if possible:
		print(flips)
	else:
		print("NOT POSSIBLE")
