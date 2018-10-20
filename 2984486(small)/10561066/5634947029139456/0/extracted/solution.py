# Python 3.4

# Codejam, 2014, Round 1A, Problem A

import pprint
import sys

def main() :
    TT = int( input() )
    for case in range( 1 , 1+TT ) :
        NN , LL = ( int( x ) for x in input().split() )
        OUTLETS = [ [ bool( int( digit ) ) for digit in str( x ) ] for x in input().split() ]
        DEVICES = [ [ bool( int( digit ) ) for digit in str( x ) ] for x in input().split() ]
        INV_OUTLETS = [ list( x ) for x in zip( *OUTLETS ) ]
        INV_DEVICES = [ list( x ) for x in zip( *DEVICES ) ]
        count , result = check( OUTLETS , DEVICES , INV_OUTLETS , INV_DEVICES , LL , NN , 0 , 0 )
        if result :
            print( "Case #{case}: {answer}".format( case=case , answer=count ) )
        else :
            print( "Case #{case}: NOT POSSIBLE".format( case=case ) )            
    #end-for    
    return 0 # EXIT_SUCCESS
#end-def-main

def check( OUTLETS , DEVICES , INV_OUTLETS , INV_DEVICES , LL , NN , start , count ) :
    # pprint.pprint( "start : ")
    # pprint.pprint( start )
    # pprint.pprint( "Count : ")
    # pprint.pprint( count )
    # if start > 0 :
    #     pprint.pprint( "C" )
    #     pprint.pprint( INV_OUTLETS[start-1] )

    for ii in range( start , LL ) :
        sum_io = sum( INV_OUTLETS[ii] )
        sum_id = sum( INV_DEVICES[ii] )
        # pprint.pprint( sum_io )
        # pprint.pprint( sum_id )
        if sum_io == sum_id :
            # check_both
            cc , result = check( OUTLETS , DEVICES , INV_OUTLETS , INV_DEVICES , LL , NN , 1+ii , count )
            if result : 
                return ( cc , result )
            # test with flip
            # count += 1
            # pprint.pprint( "A" )
            # pprint.pprint( INV_OUTLETS[ii] )
            for jj , elem in enumerate( INV_OUTLETS[ii] ) :
                INV_OUTLETS[ii][jj] = not INV_OUTLETS[ii][jj]
            # pprint.pprint( "B" )
            # pprint.pprint( INV_OUTLETS[ii] )
            cc , result = check( OUTLETS , DEVICES , INV_OUTLETS , INV_DEVICES , LL , NN , 1+ii , 1+count )
            # flip back - may not be necessary
            for jj , elem in enumerate( INV_OUTLETS[ii] ) :
                INV_OUTLETS[ii][jj] = not INV_OUTLETS[ii][jj]
            return ( cc , result )
            pass
        elif sum_io == NN - sum_id :
            # flip switch
            # count += 1
            for jj , elem in enumerate( INV_OUTLETS[ii] ) :
                INV_OUTLETS[ii][jj] = not INV_OUTLETS[ii][jj]
            cc , result = check( OUTLETS , DEVICES , INV_OUTLETS , INV_DEVICES , LL , NN , 1+ii , 1+count )
            for jj , elem in enumerate( INV_OUTLETS[ii] ) :
                INV_OUTLETS[ii][jj] = not INV_OUTLETS[ii][jj]
            return ( cc , result )

        else :
            return ( count , False )
        #end-if-elif-else
    #end-for
    RE_INV_OUTLETS = set( zip( *INV_OUTLETS ) )
    RE_INV_DEVICES = set( zip( *INV_DEVICES ) )
    # pprint.pprint( RE_INV_OUTLETS )
    # pprint.pprint( RE_INV_DEVICES )
    # pprint.pprint( count )
    # pprint.pprint( RE_INV_OUTLETS == RE_INV_DEVICES )
    return ( count , RE_INV_OUTLETS == RE_INV_DEVICES )
#end-def


if __name__ == "__main__" :
    sys.exit( main() )
    #end-if


