from sys import stdin
import sys
from Queue import Queue

def flip(arr,idx):
	newarr = []

	# for each "01", "10", "10", etc.
	for x in range(0, len(arr)):
		bitpattern = list(arr[x])
		for i in range(0, len(bitpattern)):
			if i == idx:
				if bitpattern[i] == '0':
					bitpattern[i] = '1'
				else:
					bitpattern[i] = '0'
		bitpattern = ''.join(bitpattern)
		newarr.append(bitpattern)
	return newarr

def bfs(arr,final_arr,case):

	assert len(arr) == len(final_arr)

	if len(set(arr).intersection(final_arr)) == len(final_arr):
		print "Case #" + str(case+1) + ": " + "0"
		return

	Q = Queue()
	V = set()

	Q.put( [arr,0] )
	V.add( tuple(arr) )

	soln_depths = set()

	while Q.empty() == False:
		t = Q.get()
		if len(set(t[0]).intersection(final_arr)) == len(final_arr):
			soln_depths.add( t[1] )
		for i in range( 0, len(t[0][0]) ):
			newarr = flip(t[0],i)
			if tuple(newarr) not in V:
				V.add( tuple(newarr) )
				Q.put( [newarr, t[1]+1] )

	if len(soln_depths) == 0:
		print "Case #" + str(case+1) + ": " + "NOT POSSIBLE"
	else:
		print "Case #" + str(case+1) + ": " + str(min(soln_depths))
	#print soln_depths

num_cases = int( stdin.readline().rstrip() )
for i in range(0, num_cases):
	tmp = stdin.readline().rstrip().split()
	previous = stdin.readline().rstrip().split()
	after = stdin.readline().rstrip().split()

	bfs(previous,after,i)

	#break