import sys

def solve(fname,outname):
	f = open(fname,'r')
	out = open(outname,'w')

	T = int(f.readline())
	scores = []
	for t in range(0,T):

		N = int(f.readline())
		s = [int(x) for x in f.readline().split()]
		acc = 0
		for i in range(0,N):
			acc = acc + abs(i-s[i])
		scores.append((acc,t))
		
	scores.sort()
	bads = [False for t in range(0,T)]
	thres = int(T/2)
	for i in range(0,T):
		if i<thres:
			bads[scores[i][1]]=True
		else:
			bads[scores[i][1]]=False

	for i in range(0,T):
		out.write("Case #%d: "%(i+1))
		if bads[i]:
			out.write("BAD\n")
		else:
			out.write("GOOD\n")	

	f.close()
	out.close()
	
if __name__=="__main__":
	solve(sys.argv[1],sys.argv[2])	
