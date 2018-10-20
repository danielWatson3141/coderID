import sys
sys.setrecursionlimit(1005)
fname = "B-small-attempt0.in.txt"
fname = "B-large.in.txt"
# fname = "sample.in"
fi = open(fname)
fo = open("fo.txt","w")
def visit(i):
	avail[i] = False
	ret = []
	for j in a[i]:
		if avail[j]:
			ret.append(visit(j))
	avail[i] = True
	ret.sort()
	if len(ret) < 2:
		return 1
	else:
		return ret[-1] + ret[-2] + 1
for test in range(int(fi.readline())):
	n = int(fi.readline())
	a = [[] for i in range(n)]
	for k in range(n-1):
		i,j = [int(x) for x in fi.readline().strip().split()]
		print i,j
		i-=1
		j-=1
		a[i].append(j)
		a[j].append(i)
	print a
	avail = [True] * n
	ret = []
	for i in range(n):
		ret.append( visit(i))
	print >>fo,"Case #%d: %d"%(test+1,n - max(ret))
