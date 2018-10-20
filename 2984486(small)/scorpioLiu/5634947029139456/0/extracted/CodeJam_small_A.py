import itertools
import copy

fo = open('A-small-1.out', 'w')
data = open('A-small-attempt1.in').readlines()
print (data)
num = int(data[0].strip())

def get_change(x, N):
	t = []
	for i in range(N):
		t.append(i)
	return list(itertools.combinations(t, x))

def change(s, k, l, N):
	if k == 0:
		return [s]
	res = [s]
	t = get_change(k, l)
	for n in t:
		a = copy.deepcopy(s)
		for j in range(N):
			w = ''
			for x in range(l):
				if x in n:
					w = w + '0' if a[j][x] == '1' else w  + '1'
				else:
					w += a[j][x]
			a[j] = w
		res.append(a)
	return res

def check(s, t):
	for i in s:
		if i not in t:
			return False
	return True

for z in range(num):
	n, l = data[z * 3 + 1].split()
	N = int(n)
	l = int(l)
	s = data[z * 3 + 2].split()
	t = set(data[z * 3 + 3].split())
	res = 0
	flag = False
	for k in range(l + 1):
		tmp = change(s, k, l, N)
		for i in tmp:
			if check(i, t):
				flag = True
				break
		if flag:
			break
		res = k + 1
	if not flag:
		res = 'NOT POSSIBLE'
		
	print ('Case #%d: %s' % (z + 1, str(res)))
	fo.write('Case #%d: %s\n' % (z + 1, str(res)))

		