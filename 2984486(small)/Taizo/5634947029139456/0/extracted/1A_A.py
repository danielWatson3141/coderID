
# -*- coding: cp932 -*-

import sys

def switchBit(data,bit):
    xor = 1 << bit
    for i in range(len(data)):
        data[i] = data[i] ^ xor
    return

def check(d,c,N):
    c.sort()
    for i in range(N):
        if d[i] != c[i]:
            return False
    
    return True

def greedy(d,c,N,L):
    for i in range(2 ** L):
        cCopy = c[:] 
        addSwitch = 0
        switched = []
        for j in range(L):
            if ((1 << j) & i) != 0:
                switchBit(cCopy,j)
                addSwitch += 1
                switched.append(j)
        if check(d,cCopy,N):
            print(switched)
            return str(addSwitch)
    return "NOT POSSIBLE"


def mainFunc(d,c,N,L):
    dbit = [0 for i in range(L)]
    cbit = [0 for i in range(L)]
    for i in range(L):
        mask = 1 << i
        for j in range(N):
            if d[j] & mask != 0:
                dbit[i] += 1
        for j in range(N):
            if c[j] & mask != 0:
                cbit[i] += 1


    switch = 0
    for i in range(L):
        if dbit[i] != cbit[i]:
            if dbit[i] != N - cbit[i]:
                return  "NOT POSSIBLE" 
            #switch
            switchBit(c,i)
            switch += 1
    sameBC = []
    for i in range(L):
        if cbit[i] == N - cbit[i]:
            sameBC.append(i)
         
    ans = 10000

    for i in range(2 ** len(sameBC)):
        cCopy = c[:] 
        addSwitch = 0
        
        for j in range(len(sameBC)):
            if ((1 << j) & i) != 0:
                switchBit(cCopy,sameBC[j])
                addSwitch += 1
        
        if ans > switch + addSwitch:
            if check(d,cCopy,N):
                ans = switch + addSwitch
                
    if ans == 10000:
        return "NOT POSSIBLE"
    else:
        return str(ans) 

inputfile = "A-small-attempt2.in"
#inputfile = "sample.in"
f = open(inputfile)
sys.stdout = open(inputfile.replace(".in", ".txt"),'w')
tc_num = int(f.readline().rstrip())

for tc in range(tc_num):
    l = f.readline().rstrip().split()
    N = int(l[0])
    L = int(l[1])
    #print(str(N) + ":" +str(L))
    l = f.readline().rstrip().split()
    c = []
    for i in range(N):
        c.append(int( l[i],2))
    

    l = f.readline().rstrip().split()
    d = []
    for i in range(N):
        d.append(int( l[i],2))
    
    d.sort()
    ans = mainFunc(d,c,N,L)
    #ans = greedy(d,c,N,L)
    
    print("Case #" + str(tc+1) + ": " + ans)

   
