#!/usr/bin/python

import sys

def numBits(num):
	return bin(num).count("1")
	
# returns a string left padded with zeros
def convertToBinaryString(i, length):
	return format(i, '0'+str(length) + 'b')
	
def toggleSwitches(inputOutlets, switches, constN, constL):
	switches = convertToBinaryString(switches,constL)
	switchedOutlets = []
	for outlet in range(constN):
		switchedOutlet = []
		for bit in range(constL):
			#xor each bit in inputOutlets with switches
			switchedOutlet += [inputOutlets[outlet][bit] != bool(int(switches[bit]))]

		switchedOutlets += [switchedOutlet]

	return switchedOutlets

def solveCharging(constN, constL, electricalFlow, appliances):
	for i in range(constL+1):
		for j in range(2**constL):
			if (numBits(j)==i):
				# this bit of code gets called for each possible j in order of how many set bits it has (number of switches to toggle)
				switchedOutlets = toggleSwitches(electricalFlow, j, constN, constL)
					
				# then we compare switchOutlets to appliances and see if they match
				if (sorted(appliances) == sorted(switchedOutlets)):
					#print sorted(appliances)
					#print sorted(switchedOutlets)
					#print j
					return i
	return None
	
f = open("input.txt")
numTests = int(f.readline())
output = ""
for i in range(numTests):
	[constN, constL] = f.readline().split(' ')
	constN = int(constN)
	constL = int(constL)
	electricalFlow = []
	for outlet in f.readline().split(' '):
		out = []
		for j in range(constL):
			out += [bool(int(outlet[j]))]
		electricalFlow += [out]
	
	appliances = []
	for outlet in f.readline().split(' '):
		out = []
		for j in range(constL):
			out += [bool(int(outlet[j]))]
		appliances += [out]

	answer = solveCharging(constN, constL, electricalFlow, appliances)
	if answer != None:
		output += "Case #" + str(i+1) + ": " + str(answer) + '\n'
	else:
		output += "Case #" + str(i+1) + ": NOT POSSIBLE\n"

fout = open("output.txt", "w")
fout.write(output)

