#!/usr/bin/python

#map(float, raw_input().split(" "))

def flip(word, bits):
	newWord = list(word)
	for i in range(len(bits)):
		if bits[i] == '1':
			newWord[i] = '1' if newWord[i] == '0' else '0'
	return ''.join(newWord)

for case in range(1,int(raw_input())+1):          #For all test cases
	N, L = map(int, raw_input().split(" "))
	dev = raw_input().split(" ")
	origOut = raw_input().split(" ")

	out = origOut[:]

	result = -1
	minResult = -1
	for i in range(int('1' * L, 2)+1):
		bits = "{0:b}".format(i)
		bits = ('0' * (L - len(bits))) + bits

		for word in out:
			if dev.count(flip(word, bits)) == 0:
				break
		else:
			if (result == -1):
				result = bits.count('1')
			else:
				result = min(result, bits.count('1'))

	if result == -1:
		strRes = "NOT POSSIBLE"
	else:
		strRes = str(result)

	print "Case #%d: %s" % (case, strRes)

