#!/usr/bin/env python
import sys
sys.setrecursionlimit(2000)
t = input()

def dfs(g, w, f):
	#print 'in', w, f, g[w]
	maxfbh = []
	for x in g[w]:
		if x == f: continue
		#print 'to', x
		maxfbh.append(dfs(g, x, w))
	#print 'fbh:', maxfbh

	if len(maxfbh) < 2: return 1
	maxfbh = sorted(maxfbh, reverse=True)
	#print 'fhb_s:', maxfbh
	return maxfbh[0] + maxfbh[1] + 1

for ti in range (1, t+1):
	n = input()
	g = dict((i, []) for i in range(1, n+1))
	for _ in range(n-1):
		a, b = map(int, raw_input().split())
		g[a].append(b)
		g[b].append(a)

	ans = 1
	for v in range(1, n+1):
		res = dfs(g, v, 0)
		ans = max(ans, res)
		#print '---', res
	print 'Case #' + str(ti) + ':', (n - ans)