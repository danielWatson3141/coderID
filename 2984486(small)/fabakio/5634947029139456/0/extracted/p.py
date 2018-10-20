# 

import math
import Queue
import copy

def and_str(b1, b2):
	result = ''
	for b1,b2 in zip(b1,b2):
		if b1 == b2:
			result += '0'
		else:
			result += '1'
	return result

def bits_str(bits):
	result = 0
	for b in bits:
		if b == '1':
			result += 1
	return result

def solve(flow, devices):
	result = 999999

	for i,f in enumerate(flow):
		pat = and_str(devices[0], f)

		usado = [0] * len(flow)
		usado[i] = 1

		# print devices[0], f, pat, bits_str(pat)

		flag1 = True
		for j,d in enumerate(devices):
			if j == 0:
				continue

			# print '  ', d

			flag2 = False
			for k,fl in enumerate(flow):
				if usado[k]:
					continue

				# print '    ', fl, and_str(d, fl)

				if and_str(d, fl) == pat:
					# print '      ', 'OK'
					flag2 = True
					usado[k] = 1
					break

			if not flag2:
				flag1 = False

		if flag1 == True:
			# print "OK!"
			result = min(result, bits_str(pat))

	if result == 999999:
		return 'NOT POSSIBLE'
	return result

def main():
	# fp = open('a.in')
	fp = open('A-small-attempt0.in')
	# fp = open('A-large.in')
	# fp = open('A-small-practice.in')
	# fp = open('A-large-practice.in')

	for case in xrange(int(fp.readline())):
		n,l = map(int, fp.readline().split())
		
		flow = fp.readline().split()
		devices = fp.readline().split()

		result = solve(flow, devices)

		print 'Case #{0}: {1}'.format(case+1, result)

		# break

if __name__ == "__main__":
	main()
