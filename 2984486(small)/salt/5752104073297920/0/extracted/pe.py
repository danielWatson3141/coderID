import random
def test(N):
	
	a = []
	for k in range(N):
  		a.append(k)
	for k in range(N):
		p = random.randint(0,N-1)
		i = a[k]
		a[k] = a[p]
		a[p] = i
	return a

def test2(N):
	
	a = []
	for k in range(N):
  		a.append(k)
	for k in range(N):
		p = random.randint(k,N-1)
		i = a[k]
		a[k] = a[p]
		a[p] = i
	return a

def run(TOTAL, SEARCH,N):
	eight = {}
	counter = 0
	for i in range(TOTAL):
		gen = test(N)
		pos = 0
		
		for el in gen:

			if el == SEARCH:
				if pos < SEARCH:
					counter += 1
				if pos in eight:
					eight[pos] += 1.0/TOTAL
				else:
					eight[pos] = 1.0/TOTAL
			pos += 1

	print "a[%d] = " % SEARCH
	print eight
	print counter * 1.0 / TOTAL
	print counter


def check(a):
	pos = 0
	counter = 0
	for el in a:
		if el >= pos:
			counter += 1
		pos += 1
	return counter


T = int(raw_input())
for t in range(T):
	N = int(raw_input())
	a = raw_input().split(' ')
	b = []
	for el in a:
		b.append(int(el))
	result = check(b)*1.0 / N
	if result - 0.5 > 0.01:
		print "Case #%d: BAD" % (t+1)
	else:
		print "Case #%d: GOOD" % (t+1)

#for i in range(10):
	#run(1000000,i,10)




