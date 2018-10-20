import sys

def solve(outlet, device, N, L):
  for i in range(L):
  	#bconf = bin(i)[2:].zfill(L)
  	#print bconf
  	#config = outlet[:]
  	#print outlet
  	for j in range(pow(2,L)):
  		if bin(j).count('1') == i:
		  	config = [bin( int(x,2) ^ j )[2:].zfill(L) for x in outlet]
		  	#print config
		  	'''
		  	for j in range(L):
		  		if bconf[j] == '1':
		  			config = [ flip(x, j) for x in config]
		  	'''
		  	if valid(config, device):
		  		#print bconf
		  		#return str(cout(bin(i)))
		  		return str(i)
  return 'NOT POSSIBLE'
'''
def flip(i, pos):
	o = list(i[:])
	if o[pos] == '0':
		o[pos] = '1'
	else:
		o[pos] = '0'
	return "".join(o)
'''
def valid(config, device):
	for x in device:
		if not (x in config):
			return False
	return True
'''
def cout(bconf):
	return bconf.count('1')
'''

numcases = int(sys.stdin.readline())
for casenum in range(1,numcases+1):
  N, L = [int(x) for x in sys.stdin.readline().split()]
  o = sys.stdin.readline().split()
  d = sys.stdin.readline().split()
  print 'Case #' + repr(casenum) + ': ' + solve(o, d, N, L)

#print flip('000', 1)