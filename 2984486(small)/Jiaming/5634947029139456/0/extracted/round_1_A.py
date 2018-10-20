#!/usr/bin/env python

from fileinput import FileInput
from multiprocessing.pool import ThreadPool

class MyFileInput(FileInput):

	def matrix(self, m, type):
		return [self.array(type) for i in range(m)]

	def array(self, type):
		return map(type, self.readline().split())

	def single(self, type):
		return type(self.readline())

	def readCase(self):
		self.array(int)
		return self.array(lambda x: int(x,base=2)), \
		       self.array(lambda x: int(x,base=2))

def solve(a, b):
	b.sort()
	result = float('inf')
	for i in range(2**10):
		bits = bitCount(i)
		if bits > result:
			continue
		aa = sorted(map(lambda x: x ^ i, a))
		if aa == b:
			result = bits
	if result == float('inf'):
		return "NOT POSSIBLE"
	return result


def bitCount(i):
	count = 0
	while i:
		count += i & 1
		i >>= 1
	return count

def printResult(i, out):
	print "Case #%d: %s" % (i+1, out)

if __name__ == '__main__':
	f = MyFileInput()
	N = f.single(int)
	p = ThreadPool(4)
	map(printResult, range(N), p.map(lambda x: solve(*x), [f.readCase() for i in range(N)]))