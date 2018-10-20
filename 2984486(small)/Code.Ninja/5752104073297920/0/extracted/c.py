import Code_Ninja_Contest_Utilities as cncu
def count_runs(pmtn):
	r=0
	for n in range(len(pmtn)-1):
		if pmtn[n]>pmtn[n+1]: r+=1
	return r
def comp(pmtn):
	idn=list(range(0,1001))
	z=0
	for i in range(len(pmtn)): 
		if idn[i]==pmtn[i]: z+=1
	return z
dc,infile=cncu.read_infile("in.txt",True)
i=0
cases=[n for n in infile if len(n)>1]
cases=[[int(z) for z in n] for n in cases]
rns=[comp(n) for n in cases]
mx=max(rns)
mn=min(rns)
mdn=sum(rns)/float(len(rns))

rns2=[count_runs(n) for n in cases]
mx2=max(rns2)
mn2=min(rns2)
mdn2=sum(rns2)/float(len(rns2))

#answrs=["BAD" if n>mdn and  else "GOOD" for n in rns]
answrs=[]
for n in range(len(rns)):
	if rns[n]>mdn and rns2[n]>mdn2: answrs.append("BAD")
	else: answrs.append("GOOD")
cncu.write_outfile(answrs,"out.txt")
