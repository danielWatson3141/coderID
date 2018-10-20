from __future__ import division

import os
import os.path, time
import itertools



fo=open("A-small-attempt2.in")
fw=open("A-small-attempt2.txt","w")
'''fo=open("test.txt")
fw=open("A-small-attem.txt","w")'''
c=int(fo.readline())
for p in range(0,c):
        Device=[]
        Outlet=[]
        Line=fo.readline()
        n=int(Line.split()[0])
        l=int(Line.split()[1])
        Outlet=fo.readline().split()
        Device=fo.readline().split()
        #print len(Outlet)
        #print Device
        Matrix = [[0 for x in xrange(n)] for x in xrange(n)]
        for i in range(0,n):
                for j in range(0,n):
                        outl=map(int, list(Outlet[i]))
                        dev=map(int,list(Device[j]))
                        res=[abs(outl-dev) for outl,dev in zip(outl,dev)]
                        Matrix[i][j]=''.join(str(e) for e in res)
        #print Matrix
        comme=Matrix[0]
        for i in range(0,n):
               comm=list(set(Matrix[i]).intersection(comme))
               comme=comm
        print comme
        commec=[]
        for i in range(0,len(comme)):
                num=0
                listco=list(comme[i])
                for j in range(0,len(listco)):
                        if listco[j]=='1':
                                num += 1
                commec.append(num)
        
        #print commec
        commec=sorted(commec)
        if len(commec)>0:
                word=str(commec[0])
        else:
                word="NOT POSSIBLE"
               
        
        fw.write("Case #"+ str(p+1)+": "+word+"\n")
                      
               
fw.close()       
        
                





