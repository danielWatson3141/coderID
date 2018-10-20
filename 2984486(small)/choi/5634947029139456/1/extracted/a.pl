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
my ($N, $L);
my @elec;
my @dev;

$T = <>;

sub f {
	my @p=();
	my @db = split//,$dev[0];
	my $min = $L+1;
	foreach my $e (@elec) {
		my @eb = split//,$e;
		my $count = 0;
		for (my $i=0; $i<$L; $i++) {
			if ($db[$i] == $eb[$i]) {
				$p[$i] = 0;
			} else {
				$p[$i] = 1;
				$count++;
			}
		}
		if ($count > $min) {
			next;
		}

		my @test_e = ();
		foreach my $ee (@elec) {
			my @eeb = split//,$ee;
			for (my $i=0; $i<$L; $i++) {
				if ($p[$i] == 1) {
					$eeb[$i] = ($eeb[$i]+1)%2;
				}
			}
			push(@test_e, join("",@eeb));
		}
		@test_e = sort @test_e;

		my $match = 1;
		for (my $i=0; $i<$N; $i++) {
			if ($dev[$i] ne $test_e[$i]) {
				$match = 0;
				last;
			}
		}
		if ($match == 1) {
			$min = $count;
		}
	}

	if ($min == $L+1) {
		return "NOT POSSIBLE";
	} else {
		return $min;
	}
}

for my $case (1..$T) {
	($N,$L) = split /\s+/, <>;
	@elec = split /\s+/, <>;
	my @d = split/\s+/,<>;
	@dev = sort @d;

	printf "Case #$case: %s\n", f();
}


