import sys

def read_line():
    return sys.stdin.readline().rstrip( '\n' )

def read_integer():
    return int( read_line() )

def read_integers():
    return [ int( x ) for x in read_line().split() ]

def algorithm( a ):
    o = N*[ 0 ]
    for i in range( N ):
        o[ ( a[ i ] - i - 1 ) % N ] += 1
    return 'GOOD' if sum( o[ : N/2 ] ) <= 1.09*sum( o[ N/2 : ] ) else 'BAD'

T = read_integer()
for t in range( T ):
    N = read_integer()
    a = read_integers()
    assert sorted( a ) == range( N )
    print 'Case #%i:' % ( t + 1 ), algorithm( a )
    algorithm( a )
