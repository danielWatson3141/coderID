def applyKey(initial,key,L):
    result=[]
    for i in initial:
        result.append("{0:b}".format(int(i,2)^key).zfill(int(L)))
    return result
def solFound(target,sol):
    return(all(x in target for x in sol))
with open ("data.txt", "r") as myfile:
    problem=myfile.read()
lines = problem.split('\n')
cases = int(lines[0])
for i in range(cases):
    index=3*i+1
    case=lines[index:index+3]
    N=case[0].split(' ')[0]
    L=case[0].split(' ')[1]
    initial=case[1].split(' ')
    target=case[2].split(' ')
    numPro = 2**int(L)
    ret=0
    numKeys=[]
    for k in range(numPro):
        res=applyKey(initial,k,L)
        val=solFound(target,res)
        if(val):
           key = "{0:b}".format(k)
           numKeys.append(key.count('1'))
           minKeys=min(numKeys)
           ret=1
        
        #if(len(numKeys)>1):
            #print("k:"+str(k)+ " , " + str(val))
            #print("sol:"+str(res))
            #print target
            #print("############################")
    #print numKeys
    if(ret):
        print "Case #" + str(i+1) + ": " + str(minKeys)
    else:
        print "Case #" + str(i+1) + ": NOT POSSIBLE"
