def checkmatch(olets,devices):
	outlets = list(olets)
	for device in devices:
		find = False
		fi = -1

		ol = len(outlets)
		for i in range(0,ol):
			if (outlets[i] == device):
				fi = i
				find = True
				break
		if (find):
			outlets.remove(device)
		else:
			return False
	return True

def getcombinarial(L,pre):
	cur = []
	for p in pre:
		if len(p) > 0 and p[-1] >= L:
			continue
		
		if (len(p) > 0):
			s = p[-1] + 1
		else:
			s = 1

		for j in range(s,L+1):
			p.append(j)
			cur.append(list(p))
			p.remove(j)
	return cur

def applyflip(flip,outlets):
	ret = []
	for outlet in outlets:
		fo = list(outlet)
		for f in flip:
			fo[f-1] = 1-fo[f-1]
		ret.append(fo)
	return ret

linearray = []

fp = open('A-small-attempt0.in','r')
for line in fp:
	linearray.append(line.rstrip('\n'))
fp.close()

T = int(linearray[0])
op = open('output.txt','w')
for i in range(0,T):
	paras = linearray[3*i+1].split()
	N = int(paras[0])
	L = int(paras[1])

	stroutlets = linearray[3*i+2].split()
	strdevices = linearray[3*i+3].split()

	outlets = []
	for stroutlet in stroutlets:
		outlet = []
		for j in range(0,L):
			if (stroutlet[j] == '1'):
				outlet.append(1)
			else:
				outlet.append(0)
		outlets.append(outlet)

	devices = []
	for strdevice in strdevices:
		device = []
		for j in range(0,L):
			if (strdevice[j] == '1'):
				device.append(1)
			else:
				device.append(0)
		devices.append(device)

	if (checkmatch(outlets,devices)):
		op.write("Case #%s: 0\n" % (i+1))
		continue
	
	flips = [[]]
	suc = False
	for j in range(1,L+1):
		flips = getcombinarial(L,flips)
		for flip in flips:
			flipoutlets = applyflip(flip,outlets)
			if (checkmatch(flipoutlets,devices)):
				op.write("Case #%s: %s\n" % (i+1,j))
				suc = True
				break
		if (suc):
			break
	if (not suc):
		op.write("Case #%s: NOT POSSIBLE\n" % (i+1))
op.close()