

def solve(initial, desired, switchs):
	ans = 999
	for mask in xrange(2**switchs):
		identical = True
		for i in initial:
			
			if i ^ mask not in desired:
				identical = False
				break
		
		if identical:

			ans = min(ans, bin(mask).count('1'))
	return ans

for case in xrange(1, input()+1):
	outputs, switchs = map(int, raw_input().split(' '))
	initial = [int(x, 2) for x in raw_input().split(' ')]
	desired = set([int(x, 2) for x in raw_input().split(' ')])
	
	ans = solve(initial, desired, switchs)
	if ans == 999:
		print "Case #%d: NOT POSSIBLE" % case
	else:
		print "Case #%d: %s" % (case, ans)

	



