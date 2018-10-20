my $kases = <> ;
for (my $kase=1; $kase<=$kases; $kase++) {
   print "Case #$kase: " ;
   $lin = <> ;
   chomp $lin ;
   my $n = +$lin ;
   $lin = <> ;
   chomp $lin ;
   my @a = split " ", $lin ;
   my $border = 484912 ;
   my $m1 = 0 ;
   for ($i=0; $i<$n; $i++) {
       $m1 += ($a[$i] + $n - $i - 1) % $n ;
   }
   if ($m1 > $border) {
       print "GOOD\n" ;
   } else {
       print "BAD\n" ;
   }
}
