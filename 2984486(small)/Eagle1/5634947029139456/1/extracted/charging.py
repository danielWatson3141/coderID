def countbits(n):
  count = 0
  while n>0:
    count += n & 1
    n >>= 1
  return count;

T=int(input())

for t in range(0,T):
  L1=input().split()
  N=int(L1[0])
  L=int(L1[1])
  S=input().split()
  E=input().split()
  V1=[]
  V2=[]
  for s in range(0,N):
      b=1
      V1.append(0)
      s2=int(S[s])
      for l in range(0,L):
          if s2 & 1:
              V1[s]=V1[s]+b
          b*=2
          s2=int(s2/10)
      b=1
      V2.append(0)
      s2=int(E[s])
      for l in range(0,L):
          if s2 & 1:
              V2[s]=V2[s]+b
          b*=2
          s2=int(s2/10)
  V1.sort()
  V2.sort()
  if set(V1)==set(V2):
      print("Case #%d: 0"%(t+1))
  else:
    switches=L+2
    for n in range(0,N):
      if n>0:
          if V2[n]==V2[n-1]:
              continue
      x=V1[0]^V2[n]
      sw=countbits(x)
      if sw<switches:
        V3=[]
        for n1 in range(0,N):
            V3.append(V1[n1]^x)
        V3.sort()
        if set(V2)==set(V3):
          switches=sw
    if switches==L+2:
      print("Case #%d: NOT POSSIBLE"%(t+1))
    else:
      print("Case #%d: %d"%(t+1,switches))
