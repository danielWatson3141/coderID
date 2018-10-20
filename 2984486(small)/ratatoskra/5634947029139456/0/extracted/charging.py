import sys,os,math,random

def switch(flows,flips):
    #flips is a list of 0's and 1's
    for k in range(len(flows)):
        charlist = [int(c) for c in flows[k]]
        for i in range(len(flips)):
            if flips[i]==1:
                charlist[i] = (charlist[i]+1)%2
        flows[k] = ''.join([str(c) for c in charlist])
    return flows

def matchflow(N,L,flows,devices):

    devices.sort()
    
    # 2^L different ways to switch
    x = range(2**L)
    binaries = [[int(d) for d in str(bin(i))[2:]] for i in x]

    for s in range(L+1):

        # all possible combinations of flipping (s+1) switches
        flips = [b for b in binaries if sum(b)==s]
        
        for f in flips:
            f.reverse()
            flipped = switch(list(flows),f)
            flipped.sort()
            if flipped == devices:
                return str(s)
    
    return 'NOT POSSIBLE'
    
def charging(infile,outfile):
    
    testcases = int(infile.readline())

    for t in range(testcases):
        # N: Number of devices
        # L: Length of charging flow number
        [N,L] = [int(i) for i in infile.readline().replace('\n','').split(' ')]
        flows = [i for i in infile.readline().replace('\n','').split(' ')]
        devices = [i for i in infile.readline().replace('\n','').split(' ')]
    
        answer = matchflow(N,L,flows,devices)
        outfile.write('Case #'+str(t+1)+': '+answer+'\n')
        

def main(argv):
    
    # read input file from command line arguments
    # pass input and output files to program
    if len(argv)!=1:
        print('Inputfile missing!')
    else:
        try:
            infile = open(argv[0],'r') 
            (fname,extension) = os.path.splitext(argv[0])
            outfile = open(fname+'.out','w')
            charging(infile,outfile)
            infile.close()
            outfile.close()
        except IOError as e:
            print(e)


if __name__ == "__main__":
  main(sys.argv[1:])