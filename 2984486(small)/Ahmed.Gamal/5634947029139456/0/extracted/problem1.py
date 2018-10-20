def gen(initial,K,L):
    result=[]
    for i in initial:
        result.append("{0:b}".format(int(i,2)^K).zfill(int(L)))
    return result

def test(target,sol):
    return(all(x in target for x in sol))

import sys
f = file("data.txt")

for i in range(int(f.next())):
    (N,L) = f.next().split()
    initial = f.next().split()
    target = f.next().split()
    numPro = 2**int(L)
    have = 0
    solutions = []
    for k in range(numPro):
        res=gen(initial,k,L)
        if(test(target,res)):
           K = "{0:b}".format(k)
           solutions.append(K.count('1'))
           sol = min(solutions)
           have=1
    if(have):
        print "Case #" + str(i+1) + ": " + str(sol)
    else:
        print "Case #" + str(i+1) + ": NOT POSSIBLE"
