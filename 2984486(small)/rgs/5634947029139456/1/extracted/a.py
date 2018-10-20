#!/usr/bin/env python
t = input()

def xorStr(s1, s2):
	return ''.join([('1' if x != y else '0') for x, y in zip(s1, s2)])

def turnchar(c, mc):
	if mc == '1':
		return '0' if c == '1' else '1'
	return c

def turn(s, m):
	return ''.join([turnchar(x, y) for x, y in zip(s, m)])

def equalList(a, b):
	return all(map(lambda (x, y): x == y, zip(a, b)))

def countOnes(a):
	return sum(map(lambda s: 1 if s == '1' else 0, a))

for ti in range (1, t+1):
	n, l = map(int, raw_input().split())
	left = raw_input().split()
	right = raw_input().split()
	
	first = left[0]
	masks = [xorStr(first, s) for s in right]

	ans = 1000
	for m in masks:
		switched = map(lambda s: turn(s, m), left)
		# print m, switched
		if equalList(sorted(switched), sorted(right)):
			# print ':)', countOnes(m)
			ans = min(ans, countOnes(m))

	print 'Case #' + str(ti) + ':', ans if ans != 1000 else 'NOT POSSIBLE'
