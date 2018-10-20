#!/usr/bin/python
# -*- coding: utf-8 -*-
import itertools

def after_switch(outlets,switches):
	outlets_out = []
	for j in range(len(outlets)):
			# The ith switch flips the ith bit of the electric flow from each outlet in the house
		i = 0
		o = ''
		for s in outlets[j]:
			# print i
			if i in switches:
				o = o+'1' if s=='0' else o+'0'
			else:
				o = o+outlets[j][i]
			i += 1
		outlets_out.append(o)
	return outlets_out

def match_OtoD(so, dev):
	l = [i for i in so if i in dev]
	if len(l)==len(so):
		return True
	else:
		return False


def main():
	filestr = 'A-small-attempt0'
	# filestr = 'A-large'
	# filestr = 'A-verysmall'
	fin = open(filestr+'.in','r')
	fout = open(filestr+'.out','w')

	lines = fin.read().splitlines()
	T = int(lines[0])
	for i in range(T):
		line = lines[i*3+1].split(' ')
		N = int(line[0]) # number of devices and outlets
		L = int(line[1]) # number of switches
		outlets = lines[i*3+2].split(' ')
		devices = lines[i*3+3].split(' ')
		# print outlets, devices

		possible = False
		# For each number of combination
		for j in range(0,L+1):
			# list combinations
			combi = list(itertools.combinations(range(L),j))
			# for each combination
			for c in combi:
				# print c
				# compute new state of the outlets
				switched_outlets = after_switch(outlets,c)
				# print switched_outlets
				# try to match
				possible = match_OtoD(switched_outlets,devices)
				if possible == True:
					break
			if possible == True:
				break
		
		if possible==True:
			str=  'Case #%d: %d'%(i+1,j)
		else:
			str=  'Case #%d: NOT POSSIBLE'%(i+1)
		fout.write(str+'\n')
		print str

	fin.close()
	fout.close()


if __name__ == "__main__":
    main()
