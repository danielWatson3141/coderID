import sys
import itertools

def diff(charger, outlet):
	must = ""
	for n, a in enumerate(zip(charger, outlet)):
		c, o = a
		if c != o:
			must += str(n)
	return must

def minimum(chargers_p, outlets):
	musts = None
	for n, (c, o) in enumerate(zip(chargers_p, outlets)):
		res = set(reqs(c, o))
		if musts == None:
			musts = res
		elif musts != res:
			return 200
	#print chargers_p, outlets, musts
	return len(musts)


def solve(chargers, outlets):
	total = len(chargers)
	result = {}
	for c, p in itertools.product(chargers, outlets):
		d = diff(c, p)
		if d not in result:
			result[d] = []
		result[d].append((c, p))
	l = list(len(x) for x in result if len(result[x]) == total)
	if not len(l):
		return "NOT POSSIBLE"
	return min(l)
	

number_cases = int(raw_input())
for i in xrange(number_cases):
	raw_input()
	outlets = raw_input().split(" ")
	chargers = raw_input().split(" ")
	print "Case #{}: {}".format(i+1, solve(chargers, outlets))