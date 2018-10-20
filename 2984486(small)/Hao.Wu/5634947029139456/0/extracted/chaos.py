import sys

def comp(s1,s2):
	string = ''
	for i in range(0,len(s1)):
		if s1[i]==s2[i]:
			string = string+s1[i]
		elif s1[i]=='2':
			string = string+s2[i]
		elif s2[i]=='2':
			string = string+s1[i]
		else:
			return None
	return string


def rec(outlets,devices):
	if len(outlets[0])==0:
		return ''

		
	outlet0 = [outlet for outlet in outlets if outlet[0]=='0']
	outlet1 = [x for x in outlets if x[0]=='1']


	
	dev0 = [d for d in devices if d[0]=='0']
	dev1 = [d for d in devices if d[0]=='1']

	next_dev0 = [d[1:] for d in dev0]
	next_dev1 = [d[1:] for d in dev1]

	next_out0 = [o[1:] for o in outlet0]
	next_out1 = [o[1:] for o in outlet1]


	print "starting with,"
	print outlets
	print devices	
	raw_input()
	print outlet0
	print outlet1
	print dev0
	print dev1

	raw_input()
	print next_out0
	print next_out1
	print next_dev0
	print next_dev1
		
	raw_input()
	nflip = False
	yflip = False

	if not (len(outlet0)==len(dev0) or len(outlet0)==len(dev1)):
		return None
	if len(outlet0)==len(dev0):
		print "no flip in my round"
		if len(dev0)==0:
			left0 = rec(next_out1,next_dev1)
			right0 = left0
		elif len(dev1)==0:
			left0 = rec(next_out0,next_dev0)
			right0 = left0
		else:
			left0 = rec(next_out0,next_dev0)
			right0 = rec(next_out1,next_dev1)
		nflip = True
	if len(outlet0)==len(dev1):
		print "flipping"
		if len(dev1)==0:
			left1 = rec(next_out1,next_dev0)
			right1 = left1
		elif len(dev0)==0:
			left1 = rec(next_out0,next_dev1)
			right1 = left1
		else:
			left1 = rec(next_out0,next_dev1)
			right1 = rec(next_out1, next_dev0)
		yflip = True	
	
	
		

	raw_input()
	print "I started with"
	print outlets
	print devices
	print "LEFT", left
	print "RIGHT", right
	if (not (left==None)) and (not (right==None)) and not(comp(left,right)==None):
		if yflip and nflip:
			flip = '2'
		elif yflip:
			flip = '1'
		else:
			flip = '0'
		print "RETURNING ",flip+comp(left,right)
		return flip+comp(left,right)
	else:
		return None
def solve(fname,outname):
	f = open(fname,'r')
	out = open(outname,'w')
	T = int(f.readline())

	for t in range(0,T):
		line = f.readline()
		tokens = line.split()
		N = int(tokens[0])
		L = int(tokens[1])
	 
		outl = f.readline().split()
		dev = f.readline().split()


#		sol = rec(outl,dev)
#		ans = -1
#		if not (sol==None):
#			ans=0
#			for i in range(0,len(sol)):
#				if sol[i]=='1':
#					ans +=1
#		out.write('Case #%d: '%(t+1))
#		if ans==-1:
#			out.write("NOT POSSIBLE\n")
#		else:
#			out.write("%d\n"%ans)
		
		stat = [0 for i in range(0,L+1)]
		i = 0
		dev.sort()
		while stat[L]==0:
			stat[i] = stat[i]+1
			for j in range(0,N):
				outl[j]= outl[j][:i-2]+ flipt(outl[j][i]) + outl[j][i+1:]
			outl.sort()		
			print "out", outl
			good = True
			print "dev", dev	
		#	raw_input()
			for j in range(0,N):
				if not (outl[j]==dev[j]):
					good = False

			if good:
				break
			if stat[i]==2:
				stat[i]=0
				i = i + 1
		out.write('Case #%d: '%(t+1))
		print stat
		acc = 0
		if good:
			for i in range(0,len(outl)-1):
				if stat[i]==1:
					acc+=1
			out.write('%d\n'%acc)
		else:
			out.write('NOT POSSIBLE\n')
		
		

			

	f.close()
	out.close()
def flipt(s):
	if s=='1':
		return '0'
	else:
		return '1'

if __name__=="__main__":
	solve(sys.argv[1],sys.argv[2])
