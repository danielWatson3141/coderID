def flipped(outs,i):
	return tuple(tuple(1-x if i==j else x for j,x in enumerate(xs)) for xs in outs)

def summarize(xxs,i):
	return tuple(sorted(xs[:i] for xs in xxs))

def check(inps,outs,i):
	return summarize(inps,i) == summarize(outs,i)

def solve(inps,outs,i,flips):
	if not check(inps,outs,i):
		return L+1
	
	if i == L:
		return flips

	return min(
		solve(inps,outs,i+1,flips),
		solve(inps,flipped(outs,i),i+1,flips+1))

T = int(input())
for t in range(1,T+1):
	N, L = map(int,input().split())
	outs = tuple(tuple(int(d) for d in xs) for xs in input().split())
	inps = tuple(tuple(int(d) for d in xs) for xs in input().split())
	answer = solve(inps,outs,0,0)
	
	print('Case #%d: %s'%(t,'NOT POSSIBLE' if answer == L+1 else answer))