#! /usr/bin/env perl

use strict;
use warnings;
#use bigint;
use Memoize;
use Class::Struct;


$| = 1;

sub out {
#    print @_;
}

my $T;
my $N;
my @n;

$T = <>;

sub f {
	my $count=0;
	for my $j (0..499) {
		if ($n[$j] <500) {
			$count++;
		}
	}

	if ($count > 253) {
		return "BAD";
	} else {
		return "GOOD";
	}
}

for my $case (1..$T) {
	$N = <>;
	@n = split /\s+/, <>;

	printf "Case #$case: %s\n", f();
}


