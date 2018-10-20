my $kases = <> ;
for (my $kase=1; $kase<=$kases; $kase++) {
   print "Case #$kase: " ;
   $lin = <> ;
   chomp $lin ;
   ($N, $L) = split " ", $lin ;
   $lin = <> ;
   chomp $lin ;
   my @a = split " ", $lin ;
   $lin = <> ;
   chomp $lin ;
   my @b = split " ", $lin ;
   my $r = 1000000 ;
   for ($i=0; $i<@a; $i++) {
      my $s1 = $b[$i] ^ $a[0] ;
      my @c = map { $s1 ^ $_ } @a ;
      %seen = () ;
      $seen{$_}++ for @b ;
      delete $seen{$_} for @c ;
      if (scalar %seen == 0) {
         my $t = 0 ;
         for ($j=0; $j<$L; $j++) {
            $t++ if substr($b[$i], $j, 1) ne substr($a[0], $j, 1) ;
         }
         $r = $t if $t < $r ;
      }
   }
   if ($r > $L) {
      print "NOT POSSIBLE\n" ;
   } else {
      print "$r\n" ;
   }
}
