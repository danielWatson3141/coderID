#!/usr/bin/python
# -*- coding: utf-8 -*-

from __future__ import division
from __future__ import print_function
from __future__ import unicode_literals
import itertools

def generatecombs(items, n):
	if(n==0):
		yield []
	else:
		for i in range(len(items)):
			for comb in generatecombs(items[i+1:], n-1):
				yield [items[i]] + comb

T = int(raw_input())

for caseNo in range(T):
	(N, L) = map(int, raw_input().split(" "))
	outletstrs = raw_input().split(" ")
	devicestrs = raw_input().split(" ")

	outlets = []
	devices = []
	for i in range(N):
		outlets.append(int(outletstrs[i], 2))
		devices.append(int(devicestrs[i], 2))

	ans = -1

	bits = []
	for i in range(L):
		bits.append(1 << i)

	for i in range(1+L):
		if(ans != -1):
			break
		for switches_to_flip in itertools.combinations(range(L), i):
			curoutlets = outlets[:]
			switch = 0
			for s in switches_to_flip:
				switch |= bits[s]

			flg = 1
			for j in range(N):
				curoutlets[j] ^= switch
				if(not(curoutlets[j] in devices)):
					flg = 0
					break
			if(flg):
				ans = i
				break

	print("Case #" + str(caseNo + 1) + ": " + (str(ans) if ans != -1 else "NOT POSSIBLE"))
