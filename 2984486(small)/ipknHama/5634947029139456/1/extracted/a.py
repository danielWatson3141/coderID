tn = input()
pn = 0
def numbit(x):
	b = 0
	while x:
		if x%2 == 1:
			b += 1
		x /= 2
	return b

while tn:
	tn -= 1
	pn += 1
	print 'Case #%d:'%pn,
	msg = 'NOT POSSIBLE'
	N,L = [int(x) for x in raw_input().split()]
	F = [int(x,2) for x in raw_input().split()]
	T = [int(x,2) for x in raw_input().split()]
	s = L+1
	FF = F[1:]
	FF.sort()
	for i in xrange(N):
		k = F[0]^T[i]
		if numbit(k) >= s:
			continue
		TT = [x^k for idx, x in enumerate(T) if i != idx]
		TT.sort()
		if FF==TT:
			s = numbit(k)
		
	if s == L+1:
		print msg
	else:
		print s
