"""import random

def BAD(n):
	a = [i for i in xrange(n)]
	for k in xrange(n):
		p = random.randint(0, n - 1)
		a[k], a[p] = a[p], a[k]
	return "".join([str(c) for c in a])
def GOOD(n):
	a = [i for i in xrange(n)]
	for k in xrange(n):
		p = random.randint(k, n - 1)
		a[k], a[p] = a[p], a[k]
	return "".join([str(c) for c in a])
n = 8
N = 10000
m = [0.0] * n
for i in xrange(N):
	b = BAD(n)
	for j in xrange(n):
		m[j] += b.find(str(j))
for j in xrange(n):
	m[j] /= N
l = []
for j in xrange(n):
	l.append((m[j], j))
l.sort()
print (n-1) / 2.0
for e in l:
	print e


exit()
"""
f = open("c.in", "r")
d = f.read()
f.close()

G = 0
B = 0
MM = 0.51

def solve(p):
	global G, B, MM
	p = p.split()
	p = [int(e) for e in p]
	n = 0
	for i in xrange(len(p)):
		if p[i] < len(p) / 2 and i < len(p) / 2: n += 1
		if p[i] > len(p) / 2 and i > len(p) / 2: n += 1
	#print n, len(p) * 0.5
	#print len(p) / 2.0, p.index(0)
	i0 = p.index(0)
	if n > len(p) * MM:
		B += 1
		return "BAD"
	else:
		G += 1
		return "GOOD"
	
	#return "BAD" if abs(i0 - (len(p) / 2)) < len(p) * 0.2 else "GOOD"


d = d.split("\n")[:-1]
n = int(d[0])
d = d[1:]

f = open("c.out", "w")
j = 0
for i in xrange(n):
	s = "Case #%d: %s" % (i+1, solve(d[i*2+1]))
	print s
	f.write(s+"\n")
f.close()

print B, G
