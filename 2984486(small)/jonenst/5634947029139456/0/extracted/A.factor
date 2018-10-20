! Copyright (C) 2014 Jon Harper.
! See http://factorcode.org/license.txt for BSD license.
USING: gcj.common io kernel math math.combinatorics math.parser
math.ranges sequences sorting splitting ;
IN: gcj.2014.1A.A

: ((switch)) ( n outlet -- ) [ CHAR: 1 = [ CHAR: 0 ] [ CHAR: 1 ] if ] change-nth ;
: (switch) ( n outlets -- ) [ ((switch)) ] with each ;
: switch ( switches outlets -- outlets' )
  [ clone ] map [ [ (switch) ] curry each ] keep ;
: match-switches ( switches outlets devices -- ? )
    [ switch natural-sort ] dip = ;
: A ( outlets devices -- n )
  [ natural-sort ] bi@
  [ drop first length 1 - [0,b] all-subsets ] 2keep
  [ match-switches ] 2curry find nip
  [ length number>string ] [ "NOT POSSIBLE" ] if* ;

SINGLETON: gcj.2014.1A.A
M: gcj.2014.1A.A solve-case ( class -- )
  drop
  readln drop
  readln " " split
  readln " " split A write ;
  
