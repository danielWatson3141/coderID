import os.path
import sys
from random import randint

__location__ = os.path.realpath(os.path.join(os.getcwd(), os.path.dirname(__file__)))
filepath = os.path.abspath(os.path.join(__location__, "C-small-attempt1(1).in"))
f = open(filepath, "r")
filepath = os.path.abspath(os.path.join(__location__, "out.txt"))
fo = open(filepath, 'w')

def fun1(list1):
    cnt = 0    
    for i in range(0,N):
        for j in range (0,i):
            #print(i,j,list1[j])
            if (list1[j] == i):
                cnt = cnt + 1 
    return cnt



T=int(f.readline())
r=[]
for Case in range(0,T):
    N=int(f.readline())
    NumStr=f.readline()
    tmp=NumStr.split()
    list1=[int(x) for x in tmp]
    
    cnt= fun1(list1)
    r.append(cnt)
    #print(cnt)
        #if (cnt == 1):
        #    print('good')
        #    break
            
        #l1=rand1(N)
        #l2=rand2(N)
        #if list1==l1:
        #    cnt1 = cnt1 +1
        #if list1==l2:
        #    cnt2 = cnt2 +1
    #print(cnt1,cnt2)
    if(cnt>512):
        fo.write ("Case #" + str(Case+1) + ": BAD\n")
        #print('bad')
    else:
        fo.write ("Case #" + str(Case+1) + ": GOOD\n")
        #print('good')    
    

f.close()
fo.close()
#
#
#    for cnt in range(L1,4):
#        f.readline()
#        
#    L2=int(f.readline())
#    for cnt in range(1,L2):
#        f.readline()
#    NumStr=f.readline()
#    list2=NumStr.split()
#    for cnt in range(L2,4):
#        f.readline()
#    
#    rslt=set(list2) & set(list1)
#    
#    if (len(rslt)==0):
#        fo.write ("Case #" + str(Case+1) + ": Volunteer cheated!\n")
#    elif len(rslt)>1:
#        fo.write ("Case #" + str(Case+1) + ": Bad magician!\n")
#    elif len(rslt)==1:
#        fo.write ("Case #" + str(Case+1) + ": " + next(iter(rslt)) + "\n")
