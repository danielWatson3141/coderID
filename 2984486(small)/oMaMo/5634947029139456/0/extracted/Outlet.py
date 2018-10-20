'''
Created on Apr 12, 2014

@author: ononon1
'''


fname = "../Outlet3.txt"
f = open(fname, 'r')
fout = open(fname.replace(".txt","_out.txt"), 'w')
s = f.readline()
for i in range(1,int(s)+1):
    (N,L) = map(int,f.readline().split())
    #print(L)
    a = f.readline().split()
    #print(a)
    b = f.readline().split()
    #print(b)
    A = []
    B = []
    for ii in range(N):
        A.append(int(a[ii],base=2))
        B.append(int(b[ii],base=2))
    #print(A)
    #print(B)
    sw = (2**L)

    flip=0
    m = 2**40
    for ss in range(0,sw):
        c =[]
        #print(ss,A)
        for j in range(N):
            c.append(A[j]^ss)
        if(set(B) == set(c)):
            flip = bin(ss).count("1")
            if(m > flip):
                m = flip
                #print(ss,c)
        #print(c,flip)

    if(m!=2**40):
        fout.write("Case #"+str(i)+": "+str(m)+"\n")
    else:
        fout.write("Case #"+str(i)+": NOT POSSIBLE\n")



