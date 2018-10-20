# coding: cp932

lines = iter('''
3
3 2
01 11 10
11 00 10
2 3
101 111
010 001
2 2
01 10
10 01
'''.splitlines(False)[1:])


from math import sqrt
from datetime import datetime
import sys
class Out:
	def __init__(me, f):
		me.file = f
	def write(me, *args):
		sys.stdout.write(*args)
		me.file.write(*args)
out = sys.stdout
#sys.setrecursionlimit(1500)

#from decimal import Decimal, getcontext
#getcontext().prec = 64


date = datetime.now().strftime('%Y%m%d-%H%M%S')

lines = iter(open(r'A-small-attempt1.in').read().splitlines(False))
out = Out(open('a-small-' + date + '.answer', 'w'))

#lines = iter(open(r'A-large.in').read().splitlines(False))
#out = Out(open('a-large-' + date + '.answer', 'w'))


class OffsetedList:
	def __init__(me, size, offset, init=0):
		me.l = [init]*(size+offset)
		me.offset = offset
	def __getitem__(me, index):
		return me.l[index+me.offset]
	def __setitem__(me, index, value):
		me.l[index+me.offset] = value
	
from collections import namedtuple, defaultdict
from itertools import count

caseCnt = int(next(lines))
MAX = (1<<32)-1
def dfs(L, O, R, m):
	if m == L:
		return MAX
	
	ret0 = dfs(L, O, R, m+1)
	
	new = [0]*len(O)
	for j, o in enumerate(O):
		new[j] = o ^ (1<<m)
	new.sort()
	if new == R:
		return 1
	
	ret1 = dfs(L, new, R, m+1) + 1
	return min(ret0, ret1)

def solve(L, O, R):
	R.sort()
	O.sort()
	if R == O: return 0
	ret = dfs(L,O,R,0)
	if ret == MAX: return 'NOT POSSIBLE'
	return ret
	
def from_bin(s):
	return eval('0b'+s)
	

for case in range(1, caseCnt+1):
	N,L = map(int, next(lines).split())
	O   = list(map(from_bin, next(lines).split()))
	R   = list(map(from_bin, next(lines).split()))
	#solve(N,X,Y)
	print('Case #%d:'%(case), solve(L,O,R), file=out)
	# print()
	# print()
