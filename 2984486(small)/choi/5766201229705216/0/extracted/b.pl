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
my %edge;

$T = <>;

sub getS {
	my $p = shift;
	my $me = shift;
	my @size = ();
	foreach my $c (keys $edge{$me}) {
		if ($c == $p) {
			next;
		}
		push(@size, getS($me, $c));
	}

	my $nn = scalar(@size);
	if ($nn == 0 || $nn == 1) {
		return 1;
	} else {
		my @s = sort {$b <=> $a} @size;
		return $s[0]+$s[1]+1;
	}
}

sub f {
	my $max = 0;

	for (my $s=1; $s<=$N; $s++) {
		my $size = getS(0,$s);
		if ($max < $size) {
			$max = $size;
		}
	}

	return $N-$max;
}


for my $case (1..$T) {
	$N = <>;

	for (keys %edge)
    {
        delete $edge{$_};
    }
	
	for (my $i=0; $i<$N-1; $i++) {
		my ($n1,$n2) = split /\s+/, <>;
		$edge{$n1}{$n2} = 1;
		$edge{$n2}{$n1} = 1;
	}

	printf "Case #$case: %d\n", f();
}


