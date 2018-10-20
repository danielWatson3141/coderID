inn=open("c:/downloads/in.in",'r')
rs=open("c:/downloads/rs.rs",'w')
T=int(inn.readline())
def discr (l1,l2, L):
    #discrepancy btwn 2 strings of 0-1s of length L
    n=0
    for i in range(L):
        if l1[i]!=l2[i]:
            n+=1
    return n
def vectad (l1,l2,L):
    #does Z/2 addition=subtraction of two string of 0-1s of length L
    l=''
    for i in range(L):
        l+=str(int((l1[i]!=l2[i])))
    return l
def difoutj (dc,j,L,N):
    #produces N-1 set of differences of dc's with dc[j]
    dc1=[]
    for i in range(N):
        if i!=j:
            dc1.append(vectad(dc[i],dc[j],L))
    return set(dc1)
for I in range(T):
    s=inn.readline()
    sl=s.split()
    N=int(sl[0])
    L=int(sl[1])
    s=inn.readline()
    dc=s.split()
   # print dc
    s=inn.readline()
    ot=s.split()
  #  print ot
    possible=False
    #y is our answer possible is whether possible or not
    if N==1:
        possible=True
        y=discr(ot[0],dc[0],L)
    else:
        ot1=[]
        for j in range(N-1):
            ot1.append(vectad(ot[j+1],ot[0],L))
        #now ot is a list of v2-v1 ... vN-v1
        ot2=set(ot1)
        pplcs=[]
        for j in range(N):
            if (ot2==difoutj(dc,j,L,N)):
                pplcs.append(j)
        if (len(pplcs)>0):
            possible=True
        if possible:
            #now have to compute min discr knowing all the possible matchings
            y=L+1
            for j in pplcs:
                if y>discr(ot[0],dc[j],L):
                    y=discr(ot[0],dc[j],L)
##        #now wanna create lists of differences       
##        y=L+1
##        imin=0
##        jmin=0
##        for i in range(N):
##            for j in range(N):
##                if (y>discr(dc[i],ot[j],L)):
##                    y=discr(dc[i],ot[j],L)
##                    imin=i
##                    jmin=j
##        #so now min dicr pair is dc[imin] ot[jmin]
##       # dc1=[]
##        ot1=[]
##        shiftt=vectad(dc[imin],ot[jmin],L)
##        for j in range(N):
##            ot1.append(vectad(ot[j],shiftt,L))
##        #print dc1
##        #print ot1
##        dc2=set(dc)
##        ot2=set(ot1)
##        possible=(dc2==ot2)
    #now just have to write an output
    if not possible:
        rs.write("Case #"+str(I+1)+": NOT POSSIBLE\n")
    else:
        rs.write("Case #"+str(I+1)+": "+str(y)+"\n")
inn.close()
rs.close()
        
    
    
