import sys, itertools

sys.setrecursionlimit(10000)

def flip(i, outlets):
	res = []
	for outlet in outlets:
		s = outlet[:i] + ("1" if outlet[i] == "0" else "0") + outlet[i+1:]
		res += [s]

	return res


T = int(input())
# T = 1
for case in range (T):
	print (case, file=sys.stderr)
	N, L = [int(x) for x in input().strip().split()]
	devices = [x for x in input().strip().split()]
	outlets = [x for x in input().strip().split()]
	
	# N, L = 4, 4
	# devices = ["0010", "1000", "0010", "1100"]
	# outlets = ["1100", "0110", "1100", "0010"]

	devsets = [len([x for x in i if x == "1"]) for i in zip(*devices)]
	outsets = [len([x for x in i if x == "1"]) for i in zip(*outlets)]
	
	#print (devsets, outsets)
	
	s = 0
	for i in range (L):
		if devsets[i] != outsets[i]:
			s+=1
			outlets = flip(i, outlets)

	if (sorted(devices) != sorted(outlets)):
		data = [i for i in range(L) if devsets[i] == outsets[i] == N//2]

		Min = 9999999999999
		for i in range (2**len(data)):
			outlets2 = [x for x in outlets]

			binary = bin(i)[2:]
			binary = "0"*(len(data)-len(binary)) +binary 
			flips = [int(x) for x in binary]

			for j in itertools.compress (data, flips):
				outlets2 = flip(j, outlets2)

			if sorted(devices) == sorted(outlets2):
				Min = min (Min, s+sum(flips))

		if Min == 9999999999999:
			print ("Case #{}: NOT POSSIBLE".format(case+1))		
			continue

		else :
			print ("Case #{}: {}".format(case+1, Min))
			continue

	print ("Case #{}: {}".format(case+1, s))