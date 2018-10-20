from sys import argv

with open(argv[1]) as f:
	data = f.read().split('\n')

out=[]
for case in range(int(data.pop(0))):
	print case
	N, L = map(int, data.pop(0).split())
	outlets = data.pop(0).split()
	devices = data.pop(0).split()

	# print outlets
	# print devices

	firstDevice = devices[0]
	devsToMatch = devices[1:]

	# print firstDevice
	# print devsToMatch

	switches = list(False for i in range(L))

	minSwitches = L+1
	for firstDeviceLocation in range(N):
		for s in range(L):
			if firstDevice[s]==outlets[firstDeviceLocation][s]:
				switches[s] = False
			else:
				switches[s] = True

		# print firstDeviceLocation
		# print switches

		testOutlets = outlets[:]
		for i in range(N):
			testOutlets[i] = ''.join(outlets[i][s] if switches[s]==False else str((int(outlets[i][s])+1)%2) for s in range(L))

		# print testOutlets

		for device in devsToMatch:
			if device not in testOutlets:
				break
		else:
			minSwitches = min(minSwitches, len(filter(None, switches)))
		continue

	if minSwitches==L+1:
		out.append('NOT POSSIBLE')
	else:
		out.append(minSwitches)


with open(argv[2], 'w') as f:
	for i in range(len(out)):
		f.write('Case #%d: %s\n'%(i+1, out[i]))