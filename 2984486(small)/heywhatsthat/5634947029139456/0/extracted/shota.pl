#! /usr/bin/env perl

use strict;
use warnings;
#use bigint;
#use Memoize;

$\ = "\n";

sub out {
#    print @_;
}

my $T;
my $N;
my $L;
my @flows;
my @devs;



$T = <>;


# memoize('f', NORMALIZER => sub { join ':', join(' ', sort @{$_[1]}), @_[2..$#_]; })

for my $case (1..$T) {
  # Memoize::flush_cache('f');
  out '--------------------------------------------------------------------------------';
  ($N, $L) = split /\s+/, <>;
  @flows = map oct "0b$_", split /\s+/, <>;
  @devs = sort { $a <=> $b } map oct "0b$_", split /\s+/, <>;

  my $t = 10000 + $N;
  for my $mask (0..(1<<$L)-1) {
      my $tt = grep $_ eq "1", split//, sprintf "%b", $mask;
      next if $tt > $t;
      my @f = sort { $a <=> $b } map $_ ^ $mask, @flows;
      next if grep $f[$_] != $devs[$_], 0..$N - 1;
      $t = $tt;
      last if $t <= 1;
  }
  

  printf "Case #$case: %s\n", $t > 10000? 'NOT POSSIBLE' : $t;
}

