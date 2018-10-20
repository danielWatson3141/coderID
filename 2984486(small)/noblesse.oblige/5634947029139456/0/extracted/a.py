#!/usr/bin/env python3

import sys
from functools import partial

def configure_switches( unflipped, switch_number_base, flip_count ):

    best_flip_count = 0xffff
    for switch_number in range( switch_number_base, switch_count ):
        
        flipped = \
            set( map( partial( flip_switch, switch_number ), unflipped ) )

        if flipped == flipped.intersection( required ):
            return flip_count + 1

        new_flip_count = \
            configure_switches( flipped, switch_number + 1, flip_count + 1 )
        best_flip_count = min( new_flip_count, best_flip_count )

    return best_flip_count

def flip_switch( switch_number, outlet ):
    
    mask = 1 << switch_number
    if mask == mask & outlet:
        return ~mask & outlet
    return mask | outlet

readline = sys.stdin.readline

cases_count = int( readline( ) )

for case_number in range( 1, cases_count + 1 ):
    
    outlet_count, switch_count = tuple( map( int, readline().split() ) )

    initial = set( map( partial( int, base = 2 ), readline().split() ) )
    required = set( map( partial( int, base = 2 ), readline().split() ) )

    if initial == initial.intersection( required ):
        print( "Case #{0}: 0".format( case_number ) )
        continue

    flipped = initial
    best_flip_count = configure_switches( initial, 0, 0 )

    if 0xffff == best_flip_count:
        print( "Case #{0}: NOT POSSIBLE".format( case_number ) )
    else:
        print( "Case #{0}: {1}".format( case_number, best_flip_count ) )


# vim: set syntax=python ts=4 sts=4 sw=4 et tw=79:
