import sys

def solve(line1,line2,bit=0,sofar=[]):
    n = len(line1)
    l = len(line1[0])
    if bit > l: return 0
    # print " "*(bit*4),line1,line2, " uso el bit ", bit, sofar

    if( len(sofar) > 0 ):
        # tomar los 1os caracteres de sofar, compararlos con el target, considerando solo los primeros 
        # caracteres de line2
        l2 = [ x[:bit] for x in line2 ]
        if sorted(l2) != sorted(sofar):
           # print " "*(bit*4),"^ no sirve EXITING ...", sorted(l2), "!=", sorted(sofar)
           return l+1

    if bit == l: return 0

    l1 = [ x[bit] for x in line1 ]
    l1f = [ str(1-int(x[bit])) for x in line1 ]
    
    # tomar 2 posibilidades los bits tal como vienen
    copysofar = sofar
    if len(sofar) > 0:
       sofar = [ sofar[i] + l1[i] for i in xrange(len(l1)) ]
    else:
       sofar = [ l1[i] for i in xrange(len(l1)) ]
    # print " "*(bit*4),"1a invocacion recursiva con valor ", bit+1
    p1 = solve( line1, line2, bit + 1, sofar )

    # cambiar los bits de l1
    if len(copysofar) > 0:
       sofar = [ copysofar[i] + l1f[i] for i in xrange(len(l1)) ]
    else:
       sofar = [ l1f[i] for i in xrange(len(l1)) ]
    # print " "*(bit*4),"2a invocacion recursiva con valor ", bit+1
    p2 = 1 + solve( line1, line2, bit + 1, sofar )

    return min(p1,p2)

# main()

# read 1 number, use it to control the loop
for tc in xrange(1, int(sys.stdin.readline())+1):
    N, L = [int(w) for w in sys.stdin.readline().split()]
    # print "N = ", N, " L = ", L
    line1 = sys.stdin.readline().strip().split(" ")
    # print line1
    line2 = sys.stdin.readline().strip().split(" ")
    target = "".join(sorted(line1))

    best = solve(line1,line2)

    if best > L: 
       best = "NOT POSSIBLE"
    else: 
       best = str(best)
   
    print 'Case #%d: %s' % (tc, best)
    # print 'Case #%d: %f' % (tc, best)


