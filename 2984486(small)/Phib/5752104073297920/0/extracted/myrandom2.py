#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  
#  Copyright 2014 User <phib@ubuntu>
#  
#  This program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; either version 2 of the License, or
#  (at your option) any later version.
#  
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#  
#  You should have received a copy of the GNU General Public License
#  along with this program; if not, write to the Free Software
#  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
#  MA 02110-1301, USA.
#  
#  

N=1000

def GetInitial():
	out = []
	for i in range(N):
		out.append(i)
	return out

def GenGood(CaseNo):
	from random import randint
	feature = []
	label = []
	for i in range(CaseNo):
		initial = GetInitial()
		for k in range(N):
			p = randint(k,N-1)
			tmp = initial[k]
			initial[k] = initial[p]
			initial[p] = tmp
		feature.append(initial)
		label.append(1)
	return feature, label

def GenBad(CaseNo):
	from random import randint
	feature = []
	label = []
	for i in range(CaseNo):
		initial = GetInitial()
		for k in range(N):
			p = randint(0,N-1)
			tmp = initial[k]
			initial[k] = initial[p]
			initial[p] = tmp
		feature.append(initial)
		label.append(0)
	return feature, label

def main():
	import numpy as np
	from sklearn.ensemble import RandomForestClassifier

	case = input()
	for i in range(case):
		N = input()
		line = raw_input()
		seq = map(int, line.rstrip().split(' '))
		
		sumFront = sum(seq[:500])
		sumRear = sum(seq[500:])
		diff = abs(sumFront-sumRear)
		#print diff
		if diff>10000:
			print "Case #%d: %s"%(i+1, "GOOD")
		else:
			print "Case #%d: %s"%(i+1, "BAD")  
	return 0

if __name__ == '__main__':
	main()

