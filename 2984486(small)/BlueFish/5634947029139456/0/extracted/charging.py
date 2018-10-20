infile=file('A-small-attempt1.in','rb+'); outfile=file('A-small-attempt1.out','wb+')

def solve(a,b):
 a=sorted([int(x,2) for x in a]); b=sorted([int(x,2) for x in b])
 candidates=[a[0]^x for x in b]; bestcandlen=100
 for cand in candidates:
  k=sorted([x^cand for x in a])
  if k==b:
   m=0
   while cand!=0: m+=cand%2; cand/=2
   if m<bestcandlen: bestcandlen=m
 if bestcandlen!=100: return bestcandlen
 return 'NOT POSSIBLE'

for casen in range(1,int(infile.readline())+1):
 unused=infile.readline()
 outfile.write('Case #%i: %s\r\n'%(casen,solve(infile.readline().strip().split(),infile.readline().strip().split())))