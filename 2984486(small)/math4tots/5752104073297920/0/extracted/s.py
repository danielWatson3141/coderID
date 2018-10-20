'''
BAD: numbers at lower positions are more likely to stay at lower positions
'''
T = int(input())
for t in range(1,T+1):
	N = int(input())
	nums = tuple(map(int,input().split()))
	print('Case #%d: %s'%(t,'BAD' if len(tuple(n for n in nums[:N//2] if n < N//2)) >= N//4 else 'GOOD'))
