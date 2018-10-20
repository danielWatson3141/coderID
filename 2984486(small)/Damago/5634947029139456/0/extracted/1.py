T = int(raw_input())

for i in xrange(T):
  N, L = raw_input().split()
  N = int(N)
  L = int(L)
  F = raw_input().split()
  D = raw_input().split()
  # get flows
  flows = []
  for item in F:
    flows.append(int(item,2))
  flows.sort()
  # get devices  
  devices = []
  for item in D:
    devices.append(int(item,2))
  devices.sort()

  # Compute
  min = L
  mal = 1
  for j in xrange(2**L):
    micopy = [item for item in flows]
    for k in xrange(N):
      micopy[k] = micopy[k] ^ j
    micopy.sort()
    if micopy == devices:
      mal = 0
      if bin(j).count("1") < min:
        min = bin(j).count("1")
    #print micopy, devices
  
  if mal == 0:
    print 'Case #%d: %d' % (i+1, min)
  else:
    print 'Case #%d: NOT POSSIBLE' % (i+1)
