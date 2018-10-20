import sys 
from itertools import combinations

def checkEqual(dev, out):
    tmp1= sorted(dev)
    tmp2= sorted(out)

    for i , j in zip(tmp1, tmp2):
        if i != j :
            return False

    return True

def flipString(l, idxes):
    
    # idxes is list 
    tmp = map( int,  [ i for i in l  ] ) 
    
    for i in idxes:
        tmp[i] = 1 - tmp[i]
    
    return ''.join( map(str, tmp  )  )


def solve(device, outlet, N, L):
    
    if checkEqual(device , outlet):
        return 0

    flip = [ -2 for _ in range(L) ] # 0 not flip ; 1 flip; -1 either

    for i in range(L):
        sumbitDevice = 0 
        sumbitOutlet = 0 
        for j in range(N):
            if device[j][i] == '1':
                sumbitDevice += 1 
            if outlet[j][i] == '1':
                sumbitOutlet += 1 
        if sumbitDevice == sumbitOutlet :
            if sumbitDevice + sumbitOutlet == N :
                flip[i] = -1 
            else:
                flip[i] = 0

        elif sumbitDevice == N - sumbitOutlet:
            flip[i] = 1 

        else:
            return -1
    
    
    comb = []
    
    #print flip
    flipsC = 0
    # flip ness
    for idx, i in enumerate(flip):
        if i== -1:
            comb.append(idx)
        
        if i == 1:
            flipsC +=1 
            for n in range(N):
                tmp = device[n]
                device[n] = flipString(tmp, [idx])

    
    if checkEqual(device, outlet):
        return flipsC 

    # gen all flips 
    for l in range(1, len(comb) +1):
        for combOne in combinations(comb, l ):
            tmp = []
            for devS in device:
                tmp.append( flipString(devS,  combOne ) )

            if checkEqual(tmp, outlet):
                return flipsC + l 

    return -1


            




f = open(sys.argv[1])
cases = int( f.readline().strip()  )

for case in range(1, cases+1):
    
    N, L = map(int, f.readline().strip().split() )

    device = f.readline().strip().split()
    outlet = f.readline().strip().split() 

    ans = solve(device, outlet, N, L )
    if ans < 0:
        print "Case #%d: NOT POSSIBLE" % case
    else:
        print "Case #%d: %d" % ( case, ans ) 
