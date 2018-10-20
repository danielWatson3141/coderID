import sys
inp = sys.stdin
T = int(inp.readline())

def read_ints():
	return [int(x) for x in raw_input().strip().split()]
def read_floats():
	return [float(x) for x in raw_input().strip().split()]

for t in range(1, T+1):
  print 'Case #'+str(t)+':',
  n = int(inp.readline())
  a = read_ints()
  count1=0
  count2=0
  for k in range(n):
	if a[k]<k: count1+=1
	if a[k]>k: count2+=1
  if count2-count1<30: print 'GOOD'
  else: print 'BAD'
