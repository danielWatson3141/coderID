#!/usr/bin/env python

from fileinput import FileInput

class MyFileInput(FileInput):

	def matrix(self, m, type):
		return [self.array(type) for i in range(m)]

	def array(self, type):
		return map(type, self.readline().split())

	def single(self, type):
		return type(self.readline())

	def readCase(self):
		self.single(int)
		return self.array(int)

def solve(perms):
	def avg(x):
		return sum(x[:400] + x[900:]) / float(len(x))

	i_perms = list(enumerate(perms))
	i_perms.sort(key = lambda x: avg(x[1]))
	bads = set()
	for i_perm in i_perms:
		if avg(i_perm[1]) < 490:
			bads.add(i_perm[0])

	for i, perm in enumerate(perms):
		printResult(i, "BAD" if i in bads else "GOOD")

def printResult(i, out):
	print "Case #%d: %s" % (i+1, out)

if __name__ == '__main__':
	f = MyFileInput()
	N = f.single(int)
	solve([f.readCase() for i in range(N)])