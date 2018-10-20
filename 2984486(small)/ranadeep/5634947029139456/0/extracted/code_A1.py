def c1(b):
	rt = 0
	while(b):
		rt += b & 1
		b >>= 1
	return rt

def f(A,B,k):
	B.sort()
	rt = k+1
	for s in range(1<<k):
		if B == sorted([s^i for i in A]):
			c = c1(s)
			if(c<rt):
				rt = c
	return rt


def inp():
	for t in range(int(input())):
		n,k = map(int,input().split())
		A = [int(i,2) for i in input().split()]
		B = [int(i,2) for i in input().split()]
		ans = f(A,B,k)
		if ans > k: ans = "NOT POSSIBLE"
		print("Case #{}: {}".format(t+1,ans))
		
inp()