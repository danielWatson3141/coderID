#!/usr/intel/bin/perl -w

use strict;

my $debug;
$debug = 1;
main();

sub solve {
  my $line = <>;
  my ($N, $L) = split /\s+/, $line;
  debug("N=$N L=$L\n");
  $line = <>;
  my @flows = split /\s+/, $line;
  debug("flows =    " .scalar(@flows) . ": " . join(' ', @flows) . "\n");
  $line = <>;
  my @required = split /\s+/, $line;
  debug("required = " .scalar(@required) . ": " . join(' ', @required) . "\n");

  @required = map {oct("b$_")} @required;
  @required = sort @required;

  @flows = map {oct("b$_")} @flows;

  my $min;
  for(my $i=0; $i<(2**$L); $i++) {
    my @flows1 = @flows;
    foreach my $f (@flows1) {
      $f ^= $i;
    }
    @flows1 = sort @flows1;
    my $match = 1;
    for (my $k=0; $k<@required; $k++) {
      if ($flows1[$k] != $required[$k]) {
        $match = 0;
        last;
      }
    }
    if ($match) {
      debug("Found $i: ");
      debug("flows = " . join(' ', @flows) . "\n");
      my $ibin = sprintf("%b", $i);
      my @digits = split //,$ibin;
      my @ones = grep {/1/} @digits;
      my $ones = @ones;
      if (!defined $min || $min > $ones) {
        $min = $ones;
      }
    }
  }
  if (defined $min) {
    print $min;
  } else {
    print "NOT POSSIBLE";
  }
}

sub main {
  my $T = <>;
  for (my $i = 1; $i <= $T; $i++) {
    print "Case #$i: ";
    #$debug = $i % int($T/10+0.5) == 0;
    #$debug = $i == 1 || $i == $T;
    debug("#$i: \n");
    solve();
    print "\n";
  }
}

sub debug {
  return if !$debug;
  my @args = @_;
  $args[0] = "\tDebug: " . $args[0];
  print STDERR @args;
}
