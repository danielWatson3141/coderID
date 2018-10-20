import math
import sets

def switch(N, L, outlets, devices, index):
	N = len(outlets)
	if index == L:
		return ['']
	out = []
	outlets0 = []
	outlets1 = []
	devices0 = []
	devices1 = []
	for n in xrange(N):
		if outlets[n][index] == '0':
			outlets0.append(outlets[n])
		else:
			outlets1.append(outlets[n])
		if devices[n][index] == '0':
			devices0.append(devices[n])
		else:
			devices1.append(devices[n])

	if len(outlets0) == len(devices0) and len(outlets0) == len(devices1):
		out00 = switch(N, L, outlets0, devices0, index + 1)
		out01 = switch(N, L, outlets0, devices1, index + 1)
		out10 = switch(N, L, outlets1, devices0, index + 1)
		out11 = switch(N, L, outlets1, devices1, index + 1)
		hasOut = False
		if out00 != None and out11 != None:
			out00 = sets.Set(out00)
			out11 = sets.Set(out11)
			results = out00 & out11
			for result in results:
				out.append(''.join(result))
			if len(results) > 0:
				hasOut = True
		if out01 != None and out10 != None:
			out01 = sets.Set(out01)
			out10 = sets.Set(out10)
			results = out01 & out10
			for result in results:
				result = str(index) + result
				out.append(''.join(result))
			if len(results) > 0:
				hasOut = True
		if not hasOut:
			return None
	elif len(outlets0) == len(devices0):
		out00 = switch(N, L, outlets0, devices0, index + 1)
		out11 = switch(N, L, outlets1, devices1, index + 1)
		if out00 != None and out11 != None:
			out00 = sets.Set(out00)
			out11 = sets.Set(out11)
			results = out00 & out11
			for result in results:
				out.append(''.join(result))
		else:
			return None
	elif len(outlets0) == len(devices1):
		out01 = switch(N, L, outlets0, devices1, index + 1)
		out10 = switch(N, L, outlets1, devices0, index + 1)
		if out01 != None and out10 != None:
			out01 = sets.Set(out01)
			out10 = sets.Set(out10)
			results = out01 & out10
			for result in results:
				result = str(index) + result
				out.append(''.join(result))
		else:
			return None
	else:
		return None
	return out
	
# inFile = open("input.txt", "r")
inFile = open("A-small-attempt3.in", "r")
outFile = open("A.out", "w")
T = int(inFile.readline())

for i in range(T):
	N, L = inFile.readline().split()
	N = int(N)
	L = int(L)
	outlets = inFile.readline().split()
	outlets = [list(outlet) for outlet in outlets]
	devices = inFile.readline().split()
	devices = [list(device) for device in devices]
	out = switch(N, L, outlets, devices, 0)
	if out == None:
		result = "NOT POSSIBLE"
	else:
		out = [len(o) for o in out]
		result = str(min(out))
	outFile.write( ("Case #%d: " % (i + 1)) 
					+ result
					+ '\n'
				)
	
