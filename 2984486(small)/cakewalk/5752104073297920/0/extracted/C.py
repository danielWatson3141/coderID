T = int(raw_input())

ids = []
ans = ['GOOD' for i in xrange(T)]
for t in xrange(T):
	N = int(raw_input())
	Nos = map(int, raw_input().strip().split())
	tmp = 0
	for i in xrange(N):
		tmp += (Nos[i]-i)
	ids.append([t, tmp])

ids.sort(key = lambda x: x[1])
for i in xrange(T/2):
	ans[ids[i][0]] = 'BAD'

for t in xrange(1, T+1):
	print 'Case #%d: %s' % (t, ans[t-1])
