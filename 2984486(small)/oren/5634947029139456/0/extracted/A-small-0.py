import copy
from collections import defaultdict
DEBUG=1

filename='A-small-0'
def split(x): return [int(y) for y in x]

def do(initial, final, N, L, level, cost, finals):
    if level==L:
        print 'SOLUTION', cost
        return cost

    sols=[]
    for i in [0,1]:
        if i==1:
            for n in range(N):
                initial[n][level]^=1

        count=copy.deepcopy(finals[level])
        print 'count antes', count, initial
        for n in range(N):
            
            r=''.join([str(x) for x in initial[n][0:level+1]])
            print 'level', level,'r', r, initial[n][0:level+1]
            count[r]-=1
        sirve=1
        print 'i', i,repr(count.values())
        print 'count despues', count
        for  k in count.keys():
            v=count[k]
            print 'k',k,'v',v
            if v!=0:
                sirve=0
                break
        if sirve:
            r=do(copy.deepcopy(initial), final, N, L, level+1, cost+i, finals)
            if r!=None:
                sols.append(r)
    if not sols: return None
    return min(sols)


def solve():
    T=getInt()
    for t in range(T):
        N, L=getInts()
        initial= map(split, inputFile.readline().split())
        final= map(split, inputFile.readline().split())

        finals={}
        for l in range(L):
            finals[l]=defaultdict(int)
            for n in range(N):
                r=''.join([str(x) for x in final[n][0:l+1]])
                print 'l', l,'n', n, 'R=', r
                finals[l][r]+=1
        answer=do(copy.deepcopy(initial),final, N, L, 0, 0, finals)
        print N, L
        print initial
        print final

        if answer==None:answer='NOT POSSIBLE'
        else: answer=str(answer)

        outputFile.write( "Case #%d: %s\n"%(t+1,answer))


############# TEMPLATE ##########
 
def getInt():
    r=inputFile.readline()
    try:
        r= int(r)
        if DEBUG:
            print 'getInt: ', r
        return r
    except:
        print 'Error parsing %r'%r
        raise
def getInts():
    r=inputFile.readline().split()
    try:
        r= map(int, r)
        if DEBUG:
            print 'getInts: ', r
        return r
    except:
        print 'Error parsing %r'%r
        raise

inputFile=file('%s.in'%filename, 'r')
outputFile=file('%s.out'%filename, 'w')

solve()
