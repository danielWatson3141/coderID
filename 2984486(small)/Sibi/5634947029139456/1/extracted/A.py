import sys

iFile = open(sys.argv[1],"r")

size = int(iFile.readline().strip())

for i in range(size):

  line = iFile.readline().strip().split()
  
  N = int(line[0])
  L = int(line[1])

  outlets = iFile.readline().strip().split()
  devices = iFile.readline().strip().split()
  
  totalSet = set()
  initFlag = True
  
  for outlet in range(N):
    singleSet = set()
    for device in range(N):
      singleSet.add(int(outlets[outlet],2) ^ int(devices[device],2))
    
    if initFlag:
      totalSet = singleSet
      initFlag = False
    
    totalSet = totalSet & singleSet
    
  if not totalSet:
    output = "NOT POSSIBLE"
  else:
    output = str(min([bin(a)[2:].count("1") for a in totalSet]))
  
  print("Case #"+str(i+1)+": "+output)
