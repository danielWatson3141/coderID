def main(ifn='ain.txt',ofn='aout.txt'):
    #sys.setrecursionlimit(2000)
    with open(ifn) as inf:
        with open(ofn,'w') as ouf:
            noc = int(inf.readline())
            for tnoc in xrange(1,noc+1):
                ouf.write("Case #%d: " %(tnoc))
                print "Case #%d: " %(tnoc)
                n,l = map(int,inf.readline().strip().split())
                a = inf.readline().strip().split()
                a.sort()
                #print "a = ",a
                b = inf.readline().strip().split()
                #print "b = ",b
                bestAnswer = l+4
                total = 1<<l
                for i in xrange(total):
                    bits = [i&(1<<x)>0 for x in xrange(l)]
                    #print i," : ",bits
                    c = []
                    for j in xrange(n):
                        s = ''
                        for k in xrange(l):
                            if bits[k]:
                                s += '1' if b[j][k]=='0' else '0'
                            else:
                                s += b[j][k]
                        c.append(s)
                    #print i," : ",bits
                    c.sort()
                    #print "c = ",c
                    if len([1 for j in xrange(n) if c[j]==a[j]])==n:
                        tmp = len([1 for x in bits if x])
                        bestAnswer = min(tmp,bestAnswer)
                if bestAnswer>l:
                    ouf.write("NOT POSSIBLE\n")
                    print "NOT POSSIBLE"
                else:
                    ouf.write("%d\n" %(bestAnswer))
                    print "%d" %(bestAnswer)
