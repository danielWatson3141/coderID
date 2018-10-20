# Graham Erickson


def flipBits(outlets,i):
  newoutlets=[]
  for j in range(len(outlets)):
    outlet=outlets[j]
    if outlet[i]=='0':
      outlet=outlet[:i]+'1'+outlet[i+1:]
    else:
      outlet=outlet[:i]+'0'+outlet[i+1:]
    newoutlets.append(outlet)
  return newoutlets

def isSolution(outlets,devices):
  #for device in devices:
  #  if device not in outlets:
  #    return False
  #else:
  #  return True
  return set(outlets)==set(devices)

def getMinFlips(outlets,devices,curflips,index,l):
  if isSolution(outlets,devices):
    return curflips
  if index>=l:
    return "NOT POSSIBLE"
  
  flippedOut = flipBits(outlets,index)
  
  flipRes = getMinFlips(flippedOut,devices,curflips+1,index+1,l)
  noFlipRes = getMinFlips(outlets,devices,curflips,index+1,l)

  if type(flipRes)==str and type(noFlipRes)==str:
    return "NOT POSSIBLE"
  elif type(flipRes)==int and type(noFlipRes)==str:
    return flipRes
  elif type(flipRes)==str and type(noFlipRes)==int:
    return noFlipRes
  else:
    return min(flipRes,noFlipRes)


f=open("A-small-attempt0.in",'r')

i=0
lines=f.readlines()
lines=lines[1:]
casen = 1
while i<len(lines):
  n,l=lines[i].split()
  l=int(l)
  outlets = lines[i+1].split()
  devices = lines[i+2].split()
  ans=getMinFlips(outlets,devices,0,0,l)
  print "Case #"+str(casen)+": "+str(ans)
  casen+=1
  i=i+3

