import sys
import math
import itertools
import copy

def main(filename):
	f = open(filename)
	of = open(filename.split('.')[0]+'.out', 'w')
	T = int(f.readline())

	for t in range(T):
		n 	= f.readline().strip().split(' ')
		N 	= int(n[0])
		L 	= int(n[1])

		outlets = []
		devices = []
		n 	= f.readline().strip().split(' ')
		for outlet in n:
			bitArr = []
			for bit in outlet:
				bitArr.append(int(bit))
			outlets.append(bitArr)

		n 	= f.readline().strip().split(' ')
		for device in n:
			devices.append(int(device,2))

		#print '------'
		#print outlets
		#print '------' 
		#print devices
		#print '======' 
		indices = range(L)
		found = False
		minSwitch = -1
		for numSwitch in range(0, L+1):
			cbs = itertools.combinations(indices, numSwitch)
			ucbs = []
			for cb in cbs:
				ucbs.append(list(cb))
			for ucb in ucbs:		
				#print outlets		
				cp_outlets = copy.deepcopy(outlets)
				#print 'cp_outlets(Before):' + str(cp_outlets)
				for i in ucb:
					for outlet in cp_outlets:
						if outlet[i] is 0:
							outlet[i] = 1
						else:
							outlet[i] = 0
				#print 'cp_outlets(After):' + str(cp_outlets)
				
				intOutlets = []
				for outlet in cp_outlets:
					joined = ''.join(str(x) for x in outlet)
					intOutlets.append(int(joined, 2))
				#print 'intOutlets:' + str(intOutlets)
				equal = True
				for device in devices:
					if device not in intOutlets:
						equal = False
				if equal is True:
					found = True
					break
			if found is True:
				minSwitch = numSwitch
				break
		if found is False:
			of.write('Case #'+str(t+1)+': '+'NOT POSSIBLE\n')
			#print 'Case #'+str(t+1)+': '+'NOT POSSIBLE'
		else:
			of.write('Case #'+str(t+1)+': '+str(minSwitch)+'\n')
			#print 'Case #'+str(t+1)+': '+str(minSwitch)
	f.close()
	of.close()

if __name__ == '__main__':
	if len(sys.argv)==1:
		print 'missing a filename'
		exit(1)
	main(sys.argv[1])
	sys.exit(0)

