! Copyright (C) 2010 Jon Harper.
! See http://factorcode.org/license.txt for BSD license.
USING: formatting io io.encodings.utf8 io.files math.parser
math.ranges sequences splitting kernel ;
IN: gcj.common
GENERIC: solve-case ( problem-class -- )

: read-int ( -- n ) 
  readln 10 base> ;
: read-ints ( -- ints ) 
  readln " " split [ string>number ] map ;
: solve-cases ( problem-class -- )
  read-int [1,b]
  [ "Case #%d: " printf solve-case nl ] with each ;
: out-file ( in-file -- out-file )
    "." split but-last ".out" suffix concat ;
: solve-file ( problem-class file -- )
  dup out-file utf8 [ utf8 [ solve-cases ] with-file-reader ] with-file-writer ;


