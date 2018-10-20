import sys
data = [line.split() for line in sys.stdin.readlines()]
tn = int(data[0][0])
for ti in xrange(tn):
	best = 1000
	n = int(data[3*ti+1][0])
	l = int(data[3*ti+1][1])
	outlet = data[3*ti+2]
	device = data[3*ti+3]
	def solve(list, ind, score):
		global best
		if score >= best:
			return
		if ind == l:
			if score < best:
				best = score
			return
		poss0 = poss1 = True
		for devs, outs in list:
			dev1 = out1 = 0
			for d in devs:
				if d[ind] == '1':
					dev1 += 1
			for o in outs:
				if o[ind] == '1':
					out1 += 1
			if dev1 != out1:
				poss0 = False
			if dev1 != len(outs)-out1:
				poss1 = False
			if not poss0 and not poss1:
				return
		if poss0:
			listx = []
			for devs, outs in list:
				dx0 = []
				dx1 = []
				ox0 = []
				ox1 = []
				for d in devs:
					if d[ind] == '1':
						dx1.append(d)
					else:
						dx0.append(d)
				for o in outs:
					if o[ind] == '1':
						ox1.append(o)
					else:
						ox0.append(o)
				if len(dx0) > 0:
					listx.append((dx0, ox0))
				if len(dx1) > 0:
					listx.append((dx1, ox1))
			solve(listx, ind+1, score)
		if poss1:
			listx = []
			for devs, outs in list:
				dx0 = []
				dx1 = []
				ox0 = []
				ox1 = []
				for d in devs:
					if d[ind] == '1':
						dx1.append(d)
					else:
						dx0.append(d)
				for o in outs:
					if o[ind] == '1':
						ox1.append(o)
					else:
						ox0.append(o)
				if len(dx0) > 0:
					listx.append((dx0, ox1))
				if len(dx1) > 0:
					listx.append((dx1, ox0))
			solve(listx, ind+1, score+1)
	solve([(device, outlet)], 0, 0)
	print "Case #%d:" % (ti+1),
	if best == 1000:
		print "NOT POSSIBLE"
	else:
		print best

