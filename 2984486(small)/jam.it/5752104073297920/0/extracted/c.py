#!/usr/bin/env python3
import sys
argc = len(sys.argv)
filename = sys.argv[1]
if argc > 2:
	casenumbers = list(map(int, sys.argv[2:]))
file = open(filename)
T = int(file.readline().rstrip())
for case in range(1,T+1):
	N = int(file.readline().strip())
	permutation = list(map(int, file.readline().rstrip().split()))
	if argc > 2 and not(case in casenumbers):
		continue
	notpermuted = 0
	for index in range(N):
		if permutation[index] == index:
			notpermuted += 1
	print ("Case #", case, ": ", sep="", end="")
	if notpermuted > 2:
		print("BAD")
	else:
		print("GOOD")
