#import operator

#def read():
#	e = input().split()
#	#e.sort()
#	e = [[bool(j) for j in i] for i in e]
#	e = list(zip(*e))
#	return e

#def solver():
#	N, L = [int(i) for i in input().split()]
#	e1 = read()
#	e2 = read()
#	count1 = [sum(i) for i in e1]
#	count2 = [sum(i) for i in e2]
#	flipped = []
#	unsure = []
#	for i in range(L):
#		if count1[i] + count2[i] == N:
#			if count1[i] == count2[i]:
#				unsure.append(i)
#			else:
#				flipped.append(i)
#				e1[i] = map(operator.not_, e1[i])
#		elif count1[i] == count2[i]:
#			pass
#		else:
#			return None

def ones(n):
	ret = 0
	while n:
		ret += (n & 1)
		n >>= 1
	return ret
	
def solver():
	N, L = [int(i) for i in input().split()]
	e1 = [int(i, 2) for i in input().split()]	
	e2 = [int(i, 2) for i in input().split()]
	e1.sort()
	min_flipped = L + 1
	for i in range(N):
		flipped = e1[0] ^ e2[i]
		e = sorted([j ^ flipped for j in e2])
		if e == e1:
			min_flipped = min(min_flipped, ones(flipped))
	if min_flipped == L + 1:
		return None
	return min_flipped
	

	

def main():
	t = int(input())
	for i in range(1, t + 1):
		number = solver()
		print("Case #{:d}: {:s}".format(i, str(number) if number != None else "NOT POSSIBLE"))

if __name__ == "__main__":
	main()