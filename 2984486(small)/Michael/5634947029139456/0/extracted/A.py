import sys

def read_line():
    return sys.stdin.readline().rstrip( '\n' )

def read_integer():
    return int( read_line() )

def read_integers( base = 10 ):
    return [ int( x, base ) for x in read_line().split() ]

class memoized( object ):
   def __init__( self, function ):
      self.function = function
      self.cache = {}
   def __call__( self, *arguments ):
      try:
         return self.cache[ arguments ]
      except KeyError:
         value = self.function( *arguments )
         self.cache[ arguments ] = value
         return value



def bits( x ):
    c = 0
    while x:
        c += x & 1
        x >>= 1
    return c

def switch_count( o, d ):
    best = 2*L
    for s in xrange( 2**L ):
        u = set( d )
        for t in o:
            
            if t ^ s in u:
                u.remove( t ^ s )
            else:
                break
        if not u and bits( s ) < best:
            best = bits( s )
    return best if best < 2*L else 'NOT POSSIBLE'

T = read_integer()
for t in range( T ):
    N, L = read_integers()
    o = read_integers( 2 )
    d = read_integers( 2 )
    print 'Case #%i:' % ( t + 1 ), switch_count( o, d )
