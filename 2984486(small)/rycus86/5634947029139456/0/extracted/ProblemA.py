SIZE    = 'small'
INPUT   = 'a-' + SIZE + '.in'
OUTPUT  = 'a-' + SIZE + '.out'

DATASET = []
RESULT  = []

def read_input():
    with open(INPUT) as infile:
        T = int( infile.readline() )
        for t in xrange(T):  # @UnusedVariable
            N, L = [ int(n) for n in infile.readline().split() ] # @UnusedVariable
            
            outlets = sorted( [ int(b, 2) for b in infile.readline().split() ] )
            devices = sorted( [ int(b, 2) for b in infile.readline().split() ] )
            
            DATASET.append( (outlets, devices, L) )
    
def write_result():
    C = 0
    with open(OUTPUT, 'w') as outfile:
        for r in RESULT:
            C = C + 1
            rline = 'Case #%d: %s' % (C, r)
            
            print rline
            outfile.write(rline)
            outfile.write('\n')

def solve():
    import itertools
    
    for outlets, devices, L in DATASET:
        result = None
        
        if matches(outlets, devices, []):
            result = 0
        
        for S in xrange(1, L):
            if result is not None: break
            perm = itertools.permutations(xrange(L), S)
            for p in perm:
                if matches(outlets, devices, p):
                    result = S
                    break
        
        if result is not None:
            RESULT.append( str(result) )
        else:
            RESULT.append( 'NOT POSSIBLE' )

def matches(o, d, s):
    dc = []
    dc.extend(d)
    
    for b in s:
        n = 1 << b
        for i in xrange(len(d)):
            dc[i] = dc[i] ^ n
    
    dc = sorted(dc)
    
    for i in xrange(len(dc)):
        if dc[i] != o[i]:
            return False
        
    return True

if __name__ == '__main__':
    read_input()
    solve()
    write_result()
