import random
import sys
import time

def debug(s):
	sys.stderr.write(str(s) + '\n')

def get_params(*types):
	line = (raw_input()).split()
	params = []
	for i in range(len(types)):
		params += [types[i](line[i])]
		
	if len(params)==1:
		return params[0]
		
	return tuple(params)
	
def bin_search(s,e,v,cmpfunc):
	if e-s<=1:
		return s
	m = (s+e)/2

	if cmpfunc(m,v):
		return bin_search(s,m,v,cmpfunc)
	else:
		return bin_search(m,e,v,cmpfunc)
	
class time_est:
	def __init__(self,totnum,iternum):
		self.totnum = totnum
		self.iternum = iternum
		self.start_time = time.time()
		
	def calc_time(self,iter):
		if iter == self.iternum:
			till_now = time.time() - self.start_time
			till_end = till_now * (self.totnum - iter) / (iter)
			debug('Estimated time to finish = %f seconds' % (till_end))
			

def switches(num):
	sum = 0
	while num>0:
		sum += (num&1)
		num = num/2
	return sum

Output = []
T = get_params(int)
te = time_est(T,1)

for t in xrange(T):
	te.calc_time(t)
	if t % 10 == 0:
		debug('Started %d' % t)
		

	N,L = get_params(int,int)
	ief = [int(x,2) for x in raw_input().split()]
	ref = [int(x,2) for x in raw_input().split()]
	if N%2==1:
		z = 0
		for i in range(N):
			z ^= (ief[i]^ref[i])

		possibleAny = True
		for i in range(N):
			if (ief[i]^z) not in ref:
				possibleAny = False
				break
		if possibleAny:
			sw_num = switches(z)
	else:
		possibleAny = False
		for i in range(N):
			for j in range(N):
				z = ief[i]^ref[j]
				if possibleAny and switches(z)>=sw_num:
					continue
				possible = True
				for k in range(N):
					if (ief[k]^z) not in ref:
						possible = False
						break
				if possible:
					possibleAny = True
					sw_num = switches(z)
	if possibleAny:
		Output += ['Case #%d: %d' % (t+1, sw_num)]
	else:
		Output += ['Case #%d: NOT POSSIBLE' % (t+1)]
	

		
for l in Output:
	print l
