

##            
## PROBLEM SOLVING ALGORITHM 
##

def subProblem(l):

    ## Test FIRST DIGIT
    ## sol = 0 : do not switch
    ## sol = 1 : switching required
    ## sol = 2 : might have to switch possibly...
    sol = 2
    for outlets,devices in l:

        if outlets[0]=='':
            return 0

        outOnes = sum([item[0]=='1' for item in outlets])
        outZeros = len(outlets)-outOnes
        devOnes = sum([item[0]=='1' for item in devices])
        devZeros = len(devices)-devOnes

        if outOnes==outZeros==devOnes==devZeros:
            pass
        elif outOnes==devOnes and outZeros==devZeros:
            if sol==1:
                return None
            sol = 0
        elif outZeros==devOnes and outOnes==devZeros:
            if sol==0:
                return None
            sol = 1
        else:
            return None

    ## prepare sublists for switched and non-switched case
    nextL = []
    nextLSwitched = []
    for outlets,devices in l:
        out0 = [item[1:] for item in outlets if item[0]=='0']
        out1 = [item[1:] for item in outlets if item[0]=='1']
        dev0 = [item[1:] for item in devices if item[0]=='0']
        dev1 = [item[1:] for item in devices if item[0]=='1']
        if out0!=[]:
            nextL.append([out0,dev0])
            nextLSwitched.append([out0,dev1])
        if out1!=[]:
            nextL.append([out1,dev1])
            nextLSwitched.append([out1,dev0])

    ## recursively test sublists
    n1 = None
    n2 = None
    if sol==0 or sol==2:
        n1 = subProblem(nextL)
    if sol==1 or sol==2:
        n2 = subProblem(nextLSwitched)
        if n2!=None:
            n2 += 1

    if n1!=None and n2!=None:
        return min(n1,n2)
    if n1!=None:
        return n1
    return n2
    

def solve(n, l, outlets, devices):
    sol = subProblem([[outlets,devices]])
    if sol==None:
        return 'NOT POSSIBLE'
    return str(sol)
    
##            
## MAIN LOOP: read(from stdin) - solve - print(to stdout) 
##
T = int(input())
for t in range(T):
    
    ## read case
    n,l = [int(item) for item in input().rstrip().split()]
    outlets = list(input().rstrip().split())
    devices = list(input().rstrip().split())
    
    ## solve and print result
    result = solve(n, l, outlets, devices)
    print('Case #'+str(t+1)+': '+str(result))
