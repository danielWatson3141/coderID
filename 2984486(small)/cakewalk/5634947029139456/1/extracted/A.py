from sys import stdin
readline = stdin.readline

T = int(readline())
for t in xrange(1, T+1):
	N, L = map(int, readline().strip().split())
	Flows = [int(x,2) for x in readline().strip().split()]
	Needed = [int(x,2) for x in readline().strip().split()]
	Needed.sort()
	ans = L+1
	for i in xrange(1):
		for j in xrange(N):
			edit = Flows[i] ^ Needed[j]
			NewFlows = [Flows[k]^edit for k in xrange(N)]
			NewFlows.sort()
			if (Needed == NewFlows):
				tmpans = 0
				for k in xrange(L):
					if (edit & 1):
						tmpans += 1
					edit >>= 1
				ans = min(ans,tmpans)
	if ans == L+1:
		ans = 'NOT POSSIBLE'
	print 'Case #%d:' % (t), ans
