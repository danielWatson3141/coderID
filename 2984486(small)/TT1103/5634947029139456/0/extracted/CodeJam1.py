'''
Created on 2014-04-24

@author: Tiger
'''
import itertools



def getAns(case, n,l,outlets,devices):
    switches = range(1,l+1)
    '''
    for i in range(l):
        switches.append(0)
        '''
    s=[0,1]
    
    res = itertools.product(s,repeat= l)
    
    small = 999999999999
    
    
    for i in res:
        
        
        d = devices[:]
        o = outlets[:]
        o = map(str,o)
        for x in range(len(i)):
            for t in range(len(o)):
               
                if i[x] == 1:
                    n = list(o[t])
                    if n[x]=="1":
                        n[x]="0"
                        
                    else:
                        n[x]="1"
                    o[t] = n
        c=0
        for x in i:
            if x == 1:
                c+=1
        
       
        state =True
        for x in d:
            
            if list(str(x)) in o :
                o.remove(list(str(x)))
            elif str(x) in o:
                o.remove(str(x))
            else:
              
                state = False
        
        if state and c < small:
            small = c
    
    if small == 999999999999:
        small = "NOT POSSIBLE"
    print "Case #" +str(case)+": "+str(small)
                
        
            
                
            
            
                

f = open ("A-small-attempt1.in","r")
case =1
tests = f.readline().strip()
for i in range(int(tests)):
    t = f.readline().strip().split()
    n = t[0]
    l = int(t[1])
    outlets = f.readline().strip().split()
    devices = f.readline().strip().split()
    
    getAns(case, n,l,outlets,devices)
    
    case+=1