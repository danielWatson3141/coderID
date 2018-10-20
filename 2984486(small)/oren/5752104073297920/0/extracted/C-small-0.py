import random
DEBUG=1

filename='C-small-0'

def solve():
    T=getInt()
    for t in range(T):
        N=getInt();
        l=map(int, getInts())
        ct=0
        for k in range(1000):
            if l[l[k]]==k:
                ct+=1

        if ct>=2:
            outputFile.write( "Case #%d: %s\n"%(t+1,'BAD'))
        else:
            outputFile.write( "Case #%d: %s\n"%(t+1,'GOOD'))


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
#test()
