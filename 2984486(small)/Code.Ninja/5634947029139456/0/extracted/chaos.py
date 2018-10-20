import Code_Ninja_Contest_Utilities as cncu

def solve(power,devices):
#	print devices
	solns=[]
	i=0
	while i<len(power):
		d=devices[i]
		s=[]
		for n in range(len(power)):
			p=power[n]
			s.append([p[a]!=d[a] for a in range(len(d))])
		if i>0: solns=[k for k in s if k in solns]
		else: solns=s
		if len(solns)==0: return "NOT POSSIBLE"	
		i+=1
	if len(solns)==0: return "NOT POSSIBLE"
	return min(solns,key=lambda x:x.count(True)).count(True)


dc,infile=cncu.read_infile("in.txt",True)
infile=cncu.grouplist(infile,3)
infile = [n[1:] for n in infile]
#print infile
cases=[]
for t in infile:
	for z in t:
		cases.append([[True if c=="1" else False for c in n] for n in z])
cases=cncu.grouplist(cases,2)

#print cases[0], "\n"
#print cases
answr=[solve(n[0],n[1]) for n in cases]
cncu.write_outfile(answr,"out.txt")
	
		
