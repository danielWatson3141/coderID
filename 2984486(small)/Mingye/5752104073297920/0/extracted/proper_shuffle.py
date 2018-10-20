
import numpy, random

def good(a):
	for k in range(len(a)):
		p = random.randint(k, len(a)-1)
		a[p], a[k] = a[k], a[p]
	return a

def bad(a):
	for k in range(len(a)):
		p = random.randint(0, len(a)-1)
		a[p], a[k] = a[k], a[p]
	return a

def pos(a):
	p = 0
	for i in range(len(a)):
		p += a[i] * i
	return p

def ggp(m, n):
	gp = []
	for i in range(m):
		a = good(range(n))
		p = pos(a)
		gp.append(p)
	return gp

def gbp(m, n):
	bp = []
	for i in range(m):
		a = bad(range(n))
		p = pos(a)
		bp.append(p)
	return bp

f = open('/Users/Wanli/Downloads/C-small-attempt4.in.txt')
# f = open('in.txt')
ncases = int(f.readline())
M = 1000
N = 1000

gp = ggp(M, N)
mgp = numpy.mean(gp)
bp = gbp(M, N)
mbp = numpy.mean(bp)

for case in range(ncases):
	n = int(f.readline())
	p = pos([int(x) for x in f.readline().split()])
	if numpy.absolute(mgp - p) < numpy.absolute(mbp - p):
		print 'Case #%d: GOOD' % (case+1)
	else:
		print 'Case #%d: BAD' % (case+1)


