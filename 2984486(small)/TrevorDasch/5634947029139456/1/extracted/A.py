#!/usr/bin/python
import fileinput
import sys
import numpy
import copy

def prt(txt):
	sys.stdout.write(txt);

def sumCol(mat,col,rowCount):
	s = 0
	for i in range(0,rowCount):
		if mat[i][col]:
			s += 1
	return s

def main():
	count = int(raw_input())

	for c in range(0,count):
		prt("Case #" + str(c + 1)+": ")

		[Ns, Ls] = str.split(raw_input())
		(N, L) = (int(Ns), int(Ls))

		lines = str.split(raw_input());

		outlets = []

		for i in range(0,N):
			outlet = []
			for j in range(0,L):
				outlet.append(lines[i][j] == '1')
			outlets.append(outlet)

		devices = []

		lines = str.split(raw_input());

		for i in range(0,N):
			device = []
			for j in range(0,L):
				device.append(lines[i][j] == '1')
			devices.append(device)



		

		def recurse(l, socketOptions, switches):
			result = (False,None)
			devSum = sumCol(devices,l,N)
			outSum = sumCol(outlets,l,N)
			#print str(N)+ " = " + str(devSum) + " "+str(outSum) + " " + str(N - outSum)

			if(devSum != outSum and devSum != N - outSum):
				#print "Quitting because sums don't work"
				return result
			if(devSum == outSum):
				socketOptionsCopy = copy.deepcopy(socketOptions)
				valid = True
				for i in range(0,N):
					optCount = 0;
					for o in range(0,N):
						if(devices[i][l] != outlets[o][l]):					
							socketOptionsCopy[i][o] = False
						elif socketOptionsCopy[i][o]:
							optCount+=1;

					if optCount == 0:
						valid = False
						break
				if valid:
					if(l == L - 1):
						return (True, switches);
					result = recurse(l+1,socketOptionsCopy, switches)
			if(devSum == N - outSum):
				socketOptionsCopy = copy.deepcopy(socketOptions)
				valid = True
				for i in range(0,N):
					optCount = 0;
					for o in range(0,N):
						if(devices[i][l] == outlets[o][l]):					
							socketOptionsCopy[i][o] = False
						elif socketOptionsCopy[i][o]:
							optCount+=1;

					if optCount == 0:
						valid = False
						break
				if valid:
					if(l == L - 1):
						return (True,switches+1);
					result2 = recurse(l+1,socketOptionsCopy, switches+1)
					if result2[0]:
						if not (result[0] and result[1] < result2[1]):
							result = result2


			#print ("Failed on Switch "+str(l));
			#print socketOptions
			return result

		startOptions = []
		for i in range(0,N):
			startOptions.append([])
			for j in range(0,N):
				startOptions[i].append(True)

		x =  recurse(0, startOptions, 0)
		if(x[0]):
			switchedCount = x[1];
			prt(str(switchedCount)+"\n")
		else:
			prt("NOT POSSIBLE\n")


main()