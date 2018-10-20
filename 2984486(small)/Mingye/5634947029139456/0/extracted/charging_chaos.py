
def flips(outlet):
	if len(outlet) == 1:
		return [(0, outlet), (1, str(1 - int(outlet)))]
	first = outlet[0]
	remainder = outlet[1:]
	return [(f[0]+r[0], f[1]+r[1]) for f in flips(first) for r in flips(remainder)]

f = open('/Users/Wanli/Downloads/A-small-attempt0.in.txt')
# f = open('input.txt')
ncases = int(f.readline())

for case in range(ncases):
	config = f.readline().split()
	nstrings = int(config[0])
	length = int(config[1])

	outlets = f.readline().split()
	devices = f.readline().split()

	ocs = [{} for i in range(2 ** length)]
	for outlet in outlets:
		oc = flips(outlet)
		for i in range(2 ** length):
			ocs[i][oc[i][1]] = oc[i][0]

	n = -1
	for oc in ocs:
		match = True
		for device in devices:
			if device not in oc:
				match = False
				break
		if match:
			if n == -1:
				n = oc.values()[0]
			elif n > oc.values()[0]:
				n = oc.values()[0]

	if n != -1:
		print 'Case #%d: %d' % (case+1, n)
	else:
		print 'Case #%d: NOT POSSIBLE' % (case+1)


