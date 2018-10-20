f = open("input.txt","r")
n = int(f.readline())
C = []
for k in range(n):
   ok = -1
   num = f.readline().strip().split(" ")
   N = int(num[0])
   L = int(num[1])
   chx = "10"
   L1 = f.readline().strip().split(" ")
   L2 = f.readline().strip().split(" ")
   list1 = [str(L1[i]) for i in range(N)]
   list2 = [str(L2[i]) for i in range(N)]
   for i in range(2**L):
      A = list1[:]
      B = list2[:]
      D = ["" for k in range(N)]
      b = bin(i)[2:]
      c = 0
      b = "0"*(L-len(b))+b
      print(b)
      for j in range(len(b)):
         if int(b[j]) == 1:
            c+=1
            for l in range(N):
               print(l,j,A,int(A[l][j]))
               D[l] = D[l] + chx[int(A[l][j])]
         else:
            for l in range(N):
               D[l] = D[l] + A[l][j]
      A = D[:]
      A = sorted(A)
      B = sorted(B)
      if A == B:
         ok = c
         break
      print(N,L,i,A,B)   
   C = C + [ok]
f.close()
f = open("output.txt","w")
for k in range(n):
   if C[k] == -1:
      f.write("Case #"+str(k+1)+": NOT POSSIBLE\n")
   if C[k] >= 0:
      f.write("Case #"+str(k+1)+": "+str(C[k])+"\n")
f.close()