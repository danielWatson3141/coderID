import sys

if len(sys.argv)<2:
  exit()
  

	
			

fname = sys.argv[1]
f = open(fname, "r")

T = int(f.readline())




for i in range(T):
	n,l = [int(x) for x in f.readline().split()]
	outlets = f.readline().split()
	flow = f.readline().split()
	
	candidates = []
	for c2 in flow:
		candidates.append(int(outlets[0],2) ^ int(c2,2))

	for c1 in outlets[1:]:
		candidates1 = []
		for c2 in flow:
			candidates1.append(int(c1,2) ^ int(c2,2))
		
		
		candidates = filter(lambda x: x in candidates, candidates1)
		if len(candidates)==0:
			break

	if len(candidates)==0:
		print "Case #%d: NOT POSSIBLE" % (i+1)	
	else:
		m = l		
		for x in candidates:
			m1 = bin(x).count("1")
			if m1 < m:
				m = m1

		print "Case #%d: %d" % (i+1, m)
	
f.close()